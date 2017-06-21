#pragma once
#include <iostream>
#include <vector>
#include "Ship.h"

#ifndef _PLAYER_H
#define _PLAYER_H

using std::vector;

class Player {
public:
	//make ref and const
	//add constructor
	//in if - in left - const
	//connect std::conctereNamespace,not all
	//instead class ConsoleView - namespace ConsoleView
	Player();
	void initializeVectorShip();
	void makeStep(const Coordinates& Coordinates);
	void drawStep(const Coordinates& Coordinates);
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
