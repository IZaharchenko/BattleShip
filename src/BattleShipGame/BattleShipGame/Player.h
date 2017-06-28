#pragma once
#include <iostream>
#include <vector>
#include "Ship.h"

#ifndef _PLAYER_H
#define _PLAYER_H

using std::vector;

class Player {
public:
	Player();
	void initializeVectorShip();
	void makeStep(const Coordinates& Coordinates);
	void drawStep(const Coordinates& Coordinates) const;
	void drawField(int shiftX, int shiftY) const;
	const bool isLose();
	void showStatistic();
protected:
	StepResult& checkStep(const Coordinates& Coordinates);
	void setStepResult(const StepResult& stepResult);
private:
	vector<Ship> ships_;

	int nMyKilledShips_;
	int nEnemyKilledShip_;
	bool repeatStep_;
	StepResult* stepResult_;
};

#endif //_PLAYER_H
