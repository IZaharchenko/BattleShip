#include <iostream>
#include <time.h>
#include <conio.h>

#include "ConsoleView.h"
#include "Player.h"
#include "Computer.h"
#include "User.h"

#include "ConsolePrint.h"

#include "nShips_sizeField.h"
#include "ConsoleCoordinates.h"
#include "KeyCode.h"

using std::cout;
using std::cin;

using std::endl;
using std::string;

int main()
{
	srand((unsigned)time(0));

	ConsolePrint::printEmptyFields(shiftInitialX, shiftInitialY);

	Player& pl1 = User();
	Player& pl2 = Computer();

	pl1.initializeVectorShip();
	pl2.initializeVectorShip();

	pl1.drawField(shiftInitialX, shiftInitialY);
	pl2.drawField(shiftInitialX, shiftInitialY);

	int key = 0;
	int initialX = shiftInitialX;
	int initialY = shiftInitialY + 2;

	int currentX = initialX;
	int currentY = initialY;
	ConsoleView::setCoordinates(currentX, currentY);

	while (true)
	{
		key = _getch();
		if (key == enter)
		{
			Coordinates step = Coordinates(currentX - initialX, 
				currentY - initialY);
		}
		if (key == 0 || key == 0xE0)
		{

			key = _getch();
			switch (key)
			{
			case up:
				if (currentY == initialY) { currentY = initialY + fieldSize - 1; }
				else { currentY--; }
				break;
			case right:
				if (currentX == fieldSize + initialX - 1) { currentX = initialX; }
				else { currentX++; }
				break;
			case left:
				if (currentX == initialX) { currentX = initialX + fieldSize - 1; }
				else { currentX--; }
				break;
			case down:
				if (currentY == initialY + fieldSize - 1) { currentY = initialY; }
				else { currentY++; }
				break;
			}
			ConsoleView::setCoordinates(currentX, currentY);
		}
	}
	

	//Player pl1 = Player();
	//pl1.initializeVectorShip();
	//pl1.drawField(shiftInitialX, shiftInitialY);

	//Player pl2 = Player();
	//pl2.initializeVectorShip();
	//pl2.drawField(shiftInitialX + 15, shiftInitialY);

	//int x = 0;
	//int y = 0;
	//ConsolePrint::setCoordinatesName("X", Coordinates(coordinateXPrintX, coordinateYPrintX));
	//ConsolePrint::setCoordinatesName("Y", Coordinates(coordinateXPrintY, coordinateYPrintY));

	//while (true)
	//{
	//	x = ConsolePrint::getCoordinatesFromUser(coordinateXInputX, coordinateYInputX);
	//	y = ConsolePrint::getCoordinatesFromUser(coordinateXInputY, coordinateYInputY);
	//	Coordinates step = Coordinates(x, y);
	//	pl2.makeStep(step);
	//	pl2.drawStep(step);
	//	if (pl2.isLose())
	//	{

	//	}
	//	//Generate computer coordinates
	//	x = 2; 
	//	y = 5;
	//	step = Coordinates(x, y);
	//	pl1.makeStep(step);
	//	pl1.drawStep(step);
	//	if (pl1.isLose())
	//	{

	//	}
	//	break;
	//}
	return 0;
}
