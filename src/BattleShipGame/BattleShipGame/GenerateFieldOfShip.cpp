#include <iostream>
#include "GenerateFieldOfShip.h"

using std::size_t;

GenerateFieldOfShips::GenerateFieldOfShips(const int nShips,
	map<int, int>& nTypeShip) : nTypeShip_(nTypeShip),
	ships_(list<Ship>(nShips)),
	distribution_(uniform_int_distribution<int>(1, nShips)) { };

Coordinates& GenerateFieldOfShips::getRandCoord()
{
	Coordinates* c = 0;
	while (true)
	{
		c = &Coordinates(distribution_(generator_),
			distribution_(generator_));
		if (checkCoordOnField(*c))
		{
			break;
		}
	}
	return *c;
}
bool GenerateFieldOfShips::checkCoordOnField(const Coordinates& begin)
{
	bool isUnique = false;
	const auto i = find(field_.begin(),
		field_.end(), begin);
	if (i == field_.end())
	{
		isUnique = true;
	}
	return isUnique;
}
void GenerateFieldOfShips::addShip(const list<Coordinates> body)
{
	vector<Coordinates> bodyShip;
	for (auto i = body.begin(); i != body.end(); i++)
	{
		bodyShip.push_back(*i);
	}
	Ship newObj = Ship(bodyShip);
	ships_.push_back(newObj);
}
bool GenerateFieldOfShips::isValidCoordinate(const Coordinates& begin,
	int x, int y, const int& length)
{
	bool isValid = false;
	list<Coordinates> body;
	body.push_back(begin);
	for (int k = 0; k < length; k++)
	{
		Coordinates moveC = Coordinates(x, y);
		if (checkCoordOnField(moveC))
		{
			body.push_back(moveC);
			if (begin.getX() < x) { ++x; }
			else if (begin.getX() > x) { --x; }
			else if (begin.getY() < y) { ++y; }
			else if (begin.getY() > y) { --y; }
		}
		else
		{
			isValid = false;
			break;
		}
		if (length == body.size())
		{
			addShip(body);
			addEnvironmentShip(body);
			isValid = true;
			break;
		}
	}
	return isValid;
}
void GenerateFieldOfShips::addEnvironmentShip(const list<Coordinates>& ship)
{
	for each (auto shipC in ship)
	{
		field_.push_back(shipC);
	}
	const Coordinates& firstC = ship.front();
	const Coordinates& lastC = ship.back();
	if (firstC.getX() < lastC.getX())
	{
		int y = firstC.getY();
		for (size_t i = 0; i < ship.size(); i++)
		{
			field_.push_back(Coordinates(firstC.getX() + i, y - 1));
			field_.push_back(Coordinates(firstC.getX() + i, y + 1));
		}
		field_.push_back(Coordinates(firstC.getX() - 1, y - 1));
		field_.push_back(Coordinates(firstC.getX() - 1, y));
		field_.push_back(Coordinates(firstC.getX() - 1, y + 1));

		field_.push_back(Coordinates(lastC.getX() + 1, y - 1));
		field_.push_back(Coordinates(lastC.getX() + 1, y));
		field_.push_back(Coordinates(lastC.getX() + 1, y + 1));
	}

}
vector<Ship> GenerateFieldOfShips::createField()
{
	int add = 1;
	int sub = -1;

	int countTypeShips = nTypeShip_.size();
	for (int i = 4; i > 0; i--)
	{
		int countEachShips = nTypeShip_[i];

		//get count of ship for each ship's type
		for (int j = 0; j < 1; j++)
		{
			while (true)
			{
				Coordinates beginC = getRandCoord();
				//right
				if (!isValidCoordinate(beginC, beginC.getX() + add,
					beginC.getY(), i))
				{
					//left
					if (!isValidCoordinate(beginC, beginC.getX() - sub,
						beginC.getY(), i))
					{
						//up
						if (!isValidCoordinate(beginC, beginC.getX(),
							beginC.getY() + add, i))
						{
							//down
							if (!isValidCoordinate(beginC, beginC.getX(),
								beginC.getY() - sub, countEachShips))
							{
								continue;
							}
						}
					}
				}
				break;
			}
		}
	}
	vector<Ship> result = vector<Ship>(ships_.size());
	for (auto i = ships_.begin(); i != ships_.end(); i++)
	{
		result.push_back(*i);
	}
	return result;
}
