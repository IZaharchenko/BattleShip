#include <random>

#include <list>
#include <algorithm>

#include "Player.h"
#include "Ñoordinates.h"
#include "StepResult.h"

#include "Ñoordinates.h"

using namespace std;

void Player::initializeVectorShip()
{
    list<Ñoordinates> tempMapCoordinates;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 10);
	int shiftX = 5;
	int shiftY = 3;
	int x = distribution(generator);
	int y = distribution(generator);
	
	auto findItem = std::find(tempMapCoordinates.begin(),
		tempMapCoordinates.end(), new Ñoordinates(x, y));
	if (findItem == tempMapCoordinates.end())
	{
		//coord free
	}
}
void Player::makeStep(const Ñoordinates coord)
{

}

void Player::drawStep(const Ñoordinates coord)
{

}

bool Player::canWin()
{
	return isWin_;
}

void Player::showStatistic() 
{

}

StepResult& Player::checkStep(const Ñoordinates coord)
{
	return Boner();
}

void Player::setStepResult(const StepResult& stepResult)
{
	stepResult_ = stepResult;
}