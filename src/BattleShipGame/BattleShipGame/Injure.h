#pragma once
#include "StepResult.h"

#ifndef _INJURE_H
#define _INJURE_H

class Injure : public StepResult
{
	virtual void draw(const int x, const int y) override;
	virtual bool getStepRepeat() override;
};
#endif //_INJURE_H