#include <iostream>
#include <time.h>

#include "ConsoleView.h"
#include "Player.h"

#include "ConsolePrint.h"

#include "nShips_sizeField.h"
#include "ConsoleCoordinates.h"

using std::cout;
using std::cin;

using std::endl;
using std::string;

int main()
{
	srand((unsigned)time(0));

	ConsolePrint::printEmptyFields(shiftInitialX, shiftInitialY);
	Player pl1 = Player();
	pl1.initializeVectorShip();
	pl1.drawField(shiftInitialX, shiftInitialY);

	Player pl2 = Player();
	pl2.initializeVectorShip();
	pl2.drawField(shiftInitialX + 15, shiftInitialY);

	int x = 0;
	int y = 0;
	ConsolePrint::setCoordinatesName("X", Coordinates(coordinateXPrintX, coordinateYPrintX));
	ConsolePrint::setCoordinatesName("Y", Coordinates(coordinateXPrintY, coordinateYPrintY));

	while (true)
	{
		x = ConsolePrint::getCoordinatesFromUser(coordinateXInputX, coordinateYInputX);
		y = ConsolePrint::getCoordinatesFromUser(coordinateXInputY, coordinateYInputY);
		Coordinates step = Coordinates(x, y);
		pl2.makeStep(step);
		pl2.drawStep(step);
		if (pl2.isLose())
		{

		}
		//Generate computer coordinates
		x = 2; 
		y = 5;
		step = Coordinates(x, y);
		pl1.makeStep(step);
		pl1.drawStep(step);
		if (pl1.isLose())
		{

		}
		break;
	}
	return 0;
}
