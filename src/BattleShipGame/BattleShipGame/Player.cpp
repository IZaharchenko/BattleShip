#include <random>

#include <list>
#include <algorithm>

#include "Player.h"
#include "Coordinates.h"
#include "StepResult.h"

#include "StepResult.h"
#include "Boner.h"
#include "Injure.h"
#include "Kill.h"

#include "ConsoleView.h"
#include "GenerateFieldOfShip.h"

using std::map;
using std::pair;

Player::Player() : nMyKilledShips_(0), nEnemyKilledShip_(0), repeatStep_(false), stepResult_(0){ }

void Player::initializeVectorShip()
{
	map<int, int> typesShips = map<int, int>{ { 1, 4 }, {2, 3}, {3, 2}, {4, 1} };
	GenerateFieldOfShips generate = GenerateFieldOfShips(10, typesShips);
	ships_ = generate.createField();
}
void Player::makeStep(const Coordinates& coordinates)
{

}
void Player::drawField()
{
	for each ( auto ship in ships_)
	{
		ship.drawBody();
	}
}

void Player::drawStep(const Coordinates& coordinates)
{
	stepResult_->draw(coordinates);
}

const bool Player::isLose()
{
	return false;
}

void Player::showStatistic() 
{
	//create coord for all data
 //ConsoleView::print()
}

StepResult& Player::checkStep(const Coordinates& coord)
{
	return Boner();
}

void Player::setStepResult(const StepResult& stepResult)
{
	*(stepResult_) = stepResult;
}