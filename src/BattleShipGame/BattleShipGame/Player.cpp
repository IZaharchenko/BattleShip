#include <random>

#include <list>
#include <algorithm>

#include "Player.h"
#include "�oordinates.h"
#include "StepResult.h"

#include "�oordinates.h"

using namespace std;

void Player::initializeVectorShip()
{
    list<�oordinates> tempMapCoordinates;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 10);
	int shiftX = 5;
	int shiftY = 3;
	int x = distribution(generator);
	int y = distribution(generator);
	
	auto findItem = std::find(tempMapCoordinates.begin(),
		tempMapCoordinates.end(), new �oordinates(x, y));
	if (findItem == tempMapCoordinates.end())
	{
		//coord free
	}
}
void Player::makeStep(const �oordinates coord)
{

}

void Player::drawStep(const �oordinates coord)
{

}

bool Player::canWin()
{
	return isWin_;
}

void Player::showStatistic() 
{

}

StepResult& Player::checkStep(const �oordinates coord)
{
	return Boner();
}

void Player::setStepResult(const StepResult& stepResult)
{
	stepResult_ = stepResult;
}