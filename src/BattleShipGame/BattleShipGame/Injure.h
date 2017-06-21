#pragma once
#include "StepResult.h"

#ifndef _INJURE_H
#define _INJURE_H

class Injure : public StepResult
{
	virtual void draw(const Coordinates& coordinates) override;
	virtual bool getStepRepeat() override;
};
#endif //_INJURE_H