#pragma once
#include <iostream>
#include <vector>

#include "Ñoordinates.h"
#include "StepResult.h"

#ifndef _SHIP_H
#define _SHIP_H

class Ship
{
public:
	Ship(std::vector<Ñoordinates> body) : body_(body) {};
	bool searchInBody(Ñoordinates coordinates);
	void drawBody();
private:
	std::vector<Ñoordinates> body_;
};

#endif //_SHIP_H