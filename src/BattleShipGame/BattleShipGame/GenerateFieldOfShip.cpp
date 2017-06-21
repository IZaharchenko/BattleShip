#include <iostream>
#include "GenerateFieldOfShip.h"

GenerateFieldOfShips::GenerateFieldOfShips(const int nShips, map<int, int> nTypeShip) :
	nTypeShip_(nTypeShip),
	field_(list<Coordinates>(nShips*nShips)),
	ships_(list<Ship>(nShips)),
	distribution_(uniform_int_distribution<int>(1, nShips)){ };

Coordinates& GenerateFieldOfShips::getRandCoord()
{
	Coordinates* c = 0;
	while (true)
	{
		c = &Coordinates(distribution_(generator_), 
			distribution_(generator_));
		if (checkCoordOnField)
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
	vector<Coordinates> bodyShip = vector<Coordinates>(body.size());
	for (int i = 0; i < body.size(); i++)
	{
		bodyShip.push_back(bodyShip[i]);
	}
	Ship newObj = Ship(bodyShip);
	ships_.push_back(newObj);
}
bool GenerateFieldOfShips::isValidCoordinate(Coordinates& begin, 
	int moveX, int moveY, const int size)
{
	bool isValid = false;
	list<Coordinates> body;
	for (int i = 0; i < size; i++)
	{
		int x = begin.getX() + moveX;
		int y = begin.getY() + moveY;
		Coordinates moveC = Coordinates(x, y);
		if (checkCoordOnField(moveC))
		{
			body.push_back(moveC);
		}
		else
		{
			break;
		}
	}
	if (size == body.size())
	{
		addShip(body);
		isValid = true;
	}
	return isValid;
}
void GenerateFieldOfShips::addEnvironmentShip(const Coordinates& begin, const int length)
{
	Ship lastShip = ships_.back();
	vector<Coordinates> ship = lastShip.getBody();

}
vector<Ship> GenerateFieldOfShips::createField()
{
	int add = 1;
	int sub = -1;
	//get count of ship's type
	for (int i = nTypeShip_.size(); i > 0 ; i--)
	{
		//get count of ship for each ship's type
		for (int j = 0; j < nTypeShip_[i]; j++)
		{
			while (true)
			{
				Coordinates& beginC = getRandCoord();
				//right
				if (!isValidCoordinate(beginC, beginC.getX() + add, beginC.getY(), nTypeShip_[i]))
				{
					//left
					if (!isValidCoordinate(beginC, beginC.getX() - sub, beginC.getY(), nTypeShip_[i]))
					{
						//up
						if (!isValidCoordinate(beginC, beginC.getX(), beginC.getY() + add, nTypeShip_[i]))
						{
							//down
							if (!isValidCoordinate(beginC, beginC.getX(), beginC.getY() - sub, nTypeShip_[i]))
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
}
