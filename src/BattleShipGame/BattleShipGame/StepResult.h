#pragma once
#include <iostream>
#include "Ñoordinates.h"
#include "ConsoleView.h"

#ifndef _STEPRESULT_H
#define _STEPRESULT_H

class StepResult
{
public:
	virtual void draw(Ñoordinates& coordinates) = 0;
};

class Boner : public StepResult
{
	virtual void draw(Ñoordinates& coordinates) override;
};
class Injure : public StepResult
{
	virtual void draw(Ñoordinates& coordinates) override;
}; 
class Kill : public StepResult
{
	virtual void draw(Ñoordinates& coordinates) override;
};
#endif //_STEPRESULT_H