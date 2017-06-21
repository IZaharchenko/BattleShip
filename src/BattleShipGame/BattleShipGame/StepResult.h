#pragma once
#include <iostream>
#include "Coordinates.h"
#include "ConsoleView.h"

#ifndef _STEPRESULT_H
#define _STEPRESULT_H

class StepResult
{
public:
	virtual void draw(const Coordinates& coordinates) = 0;
	virtual bool getStepRepeat() = 0;
};

#endif //_STEPRESULT_H