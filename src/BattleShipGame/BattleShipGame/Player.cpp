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

#include "nShips_sizeField.h"

using std::map;
using std::pair;

Player::Player() : nMyKilledShips_(0), nEnemyKilledShip_(0), repeatStep_(false),
fieldEnemy_{ StateField::EMPTY }, fieldOwn_{ StateField::EMPTY } { }

void Player::initializeVectorShip()
{
	map<int, int> typesShips = map<int, int>{ { 1, 4 }, {2, 3}, {3, 2}, {4, 1} };
	GenerateFieldOfShips generate = GenerateFieldOfShips(nShips, typesShips);
	ships_ = generate.createField();
}
void Player::makeStep(const Coordinates& coordinates)
{

}
void Player::drawField(int shiftX, int shiftY) const
{
	for each ( auto ship in ships_)
	{
		ship.drawBody(shiftX, shiftY);
	}
}

void Player::drawStep(const Coordinates& coordinates) const
{
	stepResult_->draw(coordinates.getX(), coordinates.getY());
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
bool Player::isOnEnemyField(const Coordinates& coordinates)
{
	bool hasStep = fieldEnemy_[coordinates.getX()][coordinates.getY()] == StateField::HAS_STEP;
	bool hasKillShip = fieldEnemy_[coordinates.getX()][coordinates.getY()] == StateField::SHIP_KILL;

	return hasStep && hasKillShip ? true : false;
}

void Player::setStepResult(const StepResult& stepResult)
{
	*(stepResult_) = stepResult;
}