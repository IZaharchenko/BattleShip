#pragma once
#include "StepResult.h"

#ifndef _BONER_H
#define _BONER_H

class Boner : public StepResult
{
	virtual void draw(const Coordinates& coordinates) override;
	virtual bool getStepRepeat() override;
};
#endif //_BONER_H