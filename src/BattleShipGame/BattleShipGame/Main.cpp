#include <iostream>
#include <time.h>

#include "ConsoleView.h"
#include "Player.h"

#include "ConsolePrint.h"

using std::cout;
using std::cin;

using std::endl;
using std::string;

int main()
{
	srand((unsigned)time(0));
	ConsolePrint::printEmptyFields(3, 2);
	Player pl1 = Player();
	pl1.initializeVectorShip();
	pl1.drawField(3, 2);

	int x = 0;
	int y = 0;
	ConsoleView::setCoordinates(Coordinates(8, 15));
	cout << "X = ";
	ConsoleView::setCoordinates(Coordinates(8, 16));
	cout << "Y = ";
	while (true)
	{
		ConsoleView::setCoordinates(Coordinates(13, 15));
		cin >> x;
		if (x > 0 && x < 10) { break; }
	}
	while (true)
	{
		ConsoleView::setCoordinates(Coordinates(13, 16));
		cin >> y;
		if (x > 0 && x < 10) { break; }
	}

	return 0;
}
