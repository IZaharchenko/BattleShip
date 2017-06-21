#pragma once
#include <iostream>
#include <vector>
#include "Ship.h"

#ifndef _PLAYER_H
#define _PLAYER_H

class Player {
public:
	void initializeVectorShip();
	void makeStep(const Ñoordinates Ñoordinates);
	void drawStep(const Ñoordinates Ñoordinates);
	bool canWin();
	void showStatistic();
protected:
	StepResult& checkStep(const Ñoordinates Ñoordinates);
	void setStepResult(const StepResult& stepResult);
private:
	bool isWin_;
	std::vector<Ship> ships_;
	int nMyKilledShips_;
	int nEnemyKilledShip_;
	bool repeatStep_;
	StepResult& stepResult_;
};

#endif //_PLAYER_H
