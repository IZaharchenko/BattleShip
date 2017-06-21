#pragma once
#include "StepResult.h"

#ifndef _KILL_H
#define _KILL_H

class Kill : public StepResult
{
	virtual void draw(const Coordinates& coordinates) override;
	virtual bool getStepRepeat() override;
};
#endif //_KILL_H