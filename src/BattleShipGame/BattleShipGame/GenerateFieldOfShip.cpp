#include <iostream>
#include <list>
#include <random>
#include <map>

#include "Ship.h"
#include "Coordinates.h"

using std::list;
using std::vector;
using std::map;
using std::find;

using std::default_random_engine;
using std::uniform_int_distribution;

class GenerateFieldOfShips
{
public:
	GenerateFieldOfShips(const int nShips, map<int, int> nTypeShip);
	vector<Ship> createField();
private:
	//map<TypeShipName = {1,2,3,4}, nShip>
	map<int, int> nTypeShip_;
	list<Coordinates> field_;
	list<Ship> ships_;
	default_random_engine generator_;
	uniform_int_distribution<int> distribution_;

	Coordinates& getRandCoord();
	bool isValidCoordinate(const Coordinates& begin,
		int moveX, int moveY, const int typeShipNo);
	void addShip(const Coordinates& coordinates, const int length);
	void addEnvironmentShip(const Coordinates& coordinates, const int length);

};

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

		const auto i = std::find(field_.begin(),
			field_.end(), c);
		if (i != field_.end())
		{
			break;
		}
	}
	return *c;
}

void GenerateFieldOfShips::addShip(const Coordinates& coordinates, const int length)
{
	vector<Coordinates> body = vector<Coordinates>(length);
	(coordinates);
	Ship newObj = Ship(body);
	ships_.push_back(newObj);
}

bool GenerateFieldOfShips::isValidCoordinate(const Coordinates& begin, 
	int moveX, int moveY, const int size)
{
	
}

void GenerateFieldOfShips::addEnvironmentShip(const Coordinates& begin, const int length)
{

}
vector<Ship> GenerateFieldOfShips::createField()
{
	int add = 1;
	int sub = -1;
	//get count of ship's type
	for (int i = 0; i < nTypeShip_.size(); i++)
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
