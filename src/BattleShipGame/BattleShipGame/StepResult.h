#pragma once
#include <iostream>
#include "ConsoleView.h"

#ifndef _STEPRESULT_H
#define _STEPRESULT_H

class StepResult
{
public:
	virtual void draw(const int x, const int y) = 0;
	virtual bool getStepRepeat() = 0;
};

#endif //_STEPRESULT_H