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
 //   list<Coordinates> tempMapCoordinates;
	//default_random_engine generator;
	//uniform_int_distribution<int> distribution(1, 10);
	//int shiftX = 5;
	//int shiftY = 3;
	//int x = distribution(generator);
	//int y = distribution(generator);
	//
	//auto findItem = std::find(tempMapCoordinates.begin(),
	//	tempMapCoordinates.end(), new Coordinates(x, y));
	//if (findItem == tempMapCoordinates.end())
	//{
	//	//coord free
	//}
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