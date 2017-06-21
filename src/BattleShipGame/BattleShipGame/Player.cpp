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


Player::Player() : nMyKilledShips_(0), nEnemyKilledShip_(0), repeatStep_(false), stepResult_(0){ }

void Player::initializeVectorShip()
{
 
}
void Player::makeStep(const Coordinates& coordinates)
{

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