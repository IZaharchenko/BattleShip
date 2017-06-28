#include "Computer.h"
#include "nShips_sizeField.h"

Coordinates Computer::getCoordinateStep()
{
	bool noUnique = true;
	Coordinates* step = nullptr;
	while (noUnique)
	{
		step = new Coordinates(rand() % nShips + 1,
			rand() % nShips + 1);
		noUnique = isOnEnemyField(*step);
	}
	
	return *step;
}