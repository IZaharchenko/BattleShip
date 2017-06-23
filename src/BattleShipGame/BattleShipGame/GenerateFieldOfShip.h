#pragma once
#include <list>
#include <random>
#include <ctime>
#include <map>

#include "Ship.h"
#include "Coordinates.h"

#ifndef _G_FIELD_OF_SHIPS_H
#define _G_FIELD_OF_SHIPS_H

using std::list;
using std::vector;
using std::map;
using std::find;

using std::default_random_engine;
using std::uniform_int_distribution;

class GenerateFieldOfShips
{
public:
	GenerateFieldOfShips(const int nShips, map<int, int>& nTypeShip);
	vector<Ship> createField();
private:
	map<int, int> nTypeShip_;
	list<Coordinates> field_;
	list<Ship> ships_;
	
	Coordinates& getRandCoord();
	bool checkCoordOnField(const Coordinates& begin);
	bool isValidCoordinate(const Coordinates& begin,
		int moveX, int moveY, const int& length);
	void addShip(const list<Coordinates> body);
	void addEnvironmentShip(const list<Coordinates>& ship);
	void environmentHorizontalShip(const Coordinates& firstC, const Coordinates& lastC,
		int shiftX, int length);
};
#endif //_G_FIELD_OF_SHIPS_H