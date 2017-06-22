#include <iostream>
#include <time.h>

#include "ConsoleView.h"
#include "Player.h"

#include "ConsolePrint.h"

//const
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
	pl1.initializeVectorShip();

	int x = 0;
	int y = 0;
	ConsoleView::setCoordinates(Coordinates(coordinateXPrintX, coordinateYPrintX));
	cout << "X = ";
	while (true)
	{
		ConsoleView::setCoordinates(Coordinates(coordinateXInputX, coordinateYInputX));
		cin >> x;
		if (x > 0 && x < fieldSize) { break; }
	}
	ConsoleView::setCoordinates(Coordinates(coordinateXPrintY, coordinateYPrintY));
	cout << "Y = ";
	while (true)
	{
		ConsoleView::setCoordinates(Coordinates(coordinateXInputY, coordinateYInputY));
		cin >> y;
		if (x > 0 && x < fieldSize) { break; }
	}
	pl2.makeStep(Coordinates(x, y));
	return 0;
}
