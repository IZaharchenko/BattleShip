#pragma once
#include <iostream>
#include <vector>
#include "Ship.h"
#include "nShips_sizeField.h"

#ifndef _PLAYER_H
#define _PLAYER_H

using std::vector;

class Player {
public:
	Player();
	void initializeVectorShip();
	void makeStep(const Coordinates& Coordinates);
	virtual Coordinates getCoordinateStep() = 0;
	void drawStep(const Coordinates& Coordinates) const;
	void drawField(int shiftX, int shiftY) const;
	const bool isLose();
	void showStatistic();
protected:
	bool isOnEnemyField(const Coordinates& Coordinates);
	void setStepResult(const StepResult& stepResult);
private:
	vector<Ship> ships_;
	int fieldOwn_[fieldSize][fieldSize];
	int fieldEnemy_[fieldSize][fieldSize];
	int nMyKilledShips_;
	int nEnemyKilledShip_;
	bool repeatStep_;
	StepResult* stepResult_;
};
enum StateField { EMPTY, HAS_STEP, HAS_SHIP, SHIP_KILL };
#endif //_PLAYER_H
