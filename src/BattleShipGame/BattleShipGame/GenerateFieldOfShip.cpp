#include <iostream>
#include <stdlib.h>

#include "GenerateFieldOfShip.h"

#include "nShips_sizeField.h"
#include "ConsoleCoordinates.h"

using std::size_t;
using std::normal_distribution;

GenerateFieldOfShips::GenerateFieldOfShips(const int nShips,
	map<int, int>& nTypeShip) : nTypeShip_(nTypeShip) {}

Coordinates& GenerateFieldOfShips::getRandCoord()
{
	Coordinates* c = 0;
	while (true)
	{
		c = &Coordinates(rand() % nShips, rand() % nShips);
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
	bool x = (begin.getX() >= 0) && (begin.getX() < nShips);
	bool y = (begin.getY() >= 0) && (begin.getY() < nShips);
	if (x && y)
	{
		const auto i = find(field_.begin(),
			field_.end(), begin);
		if (i == field_.end())
		{
			isUnique = true;
		}
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
	for (int k = 1; k < length; k++)
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
	}
		if (length == body.size())
		{
			addShip(body);
			addEnvironmentShip(body);
			isValid = true;
		}
	return isValid;
}
void GenerateFieldOfShips::environmentHorizontalShip(const Coordinates& firstC,
	const Coordinates& lastC, int value, int length)
{
	int y = firstC.getY();
	for (int i = value; i <= length; i++)
	{
		Coordinates& c1 = Coordinates(firstC.getX() + i, y - 1);
		if (checkCoordOnField(c1))
		{
			field_.push_back(c1);
		}
		Coordinates& c2 = Coordinates(firstC.getX() + i, y + 1);
		if (checkCoordOnField(c2))
		{
			field_.push_back(c2);
		}
	}
	Coordinates& c1 = Coordinates(firstC.getX() - 1, y);
	if (checkCoordOnField(c1))
	{
		field_.push_back(c1);
	}
	Coordinates& c2 = Coordinates(lastC.getX() + 1, y);
	if (checkCoordOnField(c2))
	{
		field_.push_back(c2);
	}
}

void GenerateFieldOfShips::environmentVerticalShip(const Coordinates& firstC,
	const Coordinates& lastC, int value, int length)
{
	int x = firstC.getX();
	for (int i = value; i <= length; i++)
	{
		Coordinates& c1 = Coordinates(x - 1, firstC.getY() + i);
		if (checkCoordOnField(c1))
		{
			field_.push_back(c1);
		}
		Coordinates& c2 = Coordinates(x + 1, firstC.getY() + i);
		if (checkCoordOnField(c2))
		{
			field_.push_back(c2);
		}
	}
	Coordinates& c1 = Coordinates(x, firstC.getY() - 1);
	if (checkCoordOnField(c1))
	{
		field_.push_back(c1);
	}
	Coordinates& c2 = Coordinates(x, lastC.getY() + 1);
	if (checkCoordOnField(c2))
	{
		field_.push_back(c2);
	}
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
		environmentHorizontalShip(firstC, lastC, -1, (int)ship.size());
		/*int y = firstC.getY();
		for (int i = -1; i <= (int)ship.size(); i++)
		{
			field_.push_back(Coordinates(firstC.getX() + i, y - 1));
			field_.push_back(Coordinates(firstC.getX() + i, y + 1));
		}
		field_.push_back(Coordinates(firstC.getX() - 1, y));
		field_.push_back(Coordinates(lastC.getX() + 1, y));*/
	}
	if (firstC.getX() > lastC.getX())
	{
		environmentHorizontalShip(firstC, lastC, -(int)ship.size(), 1);

	/*	int y = firstC.getY();
		for (int i = 1; i >= -(int)ship.size(); i--)
		{
			field_.push_back(Coordinates(firstC.getX() + i, y - 1));
			field_.push_back(Coordinates(firstC.getX() + i, y + 1));
		}
		field_.push_back(Coordinates(firstC.getX() + 1, y));
		field_.push_back(Coordinates(lastC.getX() - ship.size(), y));*/
	}

	if (firstC.getY() < lastC.getY())
	{
		environmentVerticalShip(firstC, lastC, -1, (int)ship.size());

		/*int x = firstC.getX();
		field_.push_back(Coordinates(x, firstC.getY() - 1));
		field_.push_back(Coordinates(x, lastC.getY() + 1));
		for (int i = -1; i <= (int)ship.size(); i++)
		{
			field_.push_back(Coordinates(x - 1, firstC.getY() + i));
			field_.push_back(Coordinates(x + 1, firstC.getY() + i));
		}*/
	}
	if (firstC.getY() > lastC.getY())
	{
		environmentVerticalShip(firstC, lastC, -(int)ship.size(), 1);

		/*int x = firstC.getX();
		field_.push_back(Coordinates(x, firstC.getY() - ship.size()));
		field_.push_back(Coordinates(x, lastC.getY() + 1));
		for (int i = 1; i >= -(int)ship.size(); i--)
		{
			field_.push_back(Coordinates(x - 1, firstC.getY() + i));
			field_.push_back(Coordinates(x + 1, firstC.getY() + i));
		}*/
	}
}

vector<Ship> GenerateFieldOfShips::createField()
{
	int add = 1;
	int sub = -1;

	for (int i = (int)nTypeShip_.size(); i > 0; i--)
	{
		//get count of ship for each ship's type
		for (int j = 0; j < nTypeShip_[i]; j++)
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
								beginC.getY() - sub, i))
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
	vector<Ship> result;
	for (auto i = ships_.begin(); i != ships_.end(); i++)
	{
		result.push_back(*i);
	}
	return result;
}
