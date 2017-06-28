#include <iostream>
#include "Player.h"

#ifndef _COMPUTER_H_
#define _COMPUTER_H_

class Computer : public Player
{
	virtual Coordinates getCoordinateStep() override;
};
#endif //_COMPUTER_H_