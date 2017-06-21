#pragma once
#include <iostream>
#include <vector>

#include "Coordinates.h"
#include "StepResult.h"

#ifndef _SHIP_H
#define _SHIP_H

class Ship
{
public:
	Ship(std::vector<Coordinates> body);
	bool searchInBody(const Coordinates& coordinates);
	void drawBody();
private:
	std::vector<Coordinates> body_;
};

#endif //_SHIP_H