#pragma once
#include <iostream>
#include <vector>

#include "Coordinates.h"
#include "StepResult.h"

#ifndef _SHIP_H
#define _SHIP_H

using std::vector;
class Ship
{
public:
	Ship(vector<Coordinates> body);
	bool searchInBody(const Coordinates& coordinates);
	void drawBody();
	const vector<Coordinates> getBody();
private:
	vector<Coordinates> body_;
};

#endif //_SHIP_H