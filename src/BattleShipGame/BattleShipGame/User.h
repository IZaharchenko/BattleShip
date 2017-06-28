#include <iostream>
#include "Player.h"

#ifndef _USER_H_
#define _USER_H_

class User : public Player
{
	virtual Coordinates getCoordinateStep() override;
};
#endif //_USER_H_