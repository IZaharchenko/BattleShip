#pragma once
#include <iostream>
#include <vector>

#include "�oordinates.h"
#include "StepResult.h"

#ifndef _SHIP_H
#define _SHIP_H

class Ship
{
public:
	Ship(std::vector<�oordinates> body) : body_(body) {};
	bool searchInBody(�oordinates coordinates);
	void drawBody();
private:
	std::vector<�oordinates> body_;
};

#endif //_SHIP_H