#pragma once
#include <iostream>
#include "�oordinates.h"
#include "ConsoleView.h"

#ifndef _STEPRESULT_H
#define _STEPRESULT_H

class StepResult
{
public:
	virtual void draw(�oordinates& coordinates) = 0;
};

class Boner : public StepResult
{
	virtual void draw(�oordinates& coordinates) override;
};
class Injure : public StepResult
{
	virtual void draw(�oordinates& coordinates) override;
}; 
class Kill : public StepResult
{
	virtual void draw(�oordinates& coordinates) override;
};
#endif //_STEPRESULT_H