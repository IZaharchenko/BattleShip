#include <string>
#include "ConsoleView.h"

void ConsoleView::setCoordinates(Ñoordinates& coordinates)
{
	COORD coord{ coordinates.getX(), coordinates.getY() };
	SetConsoleCursorPosition(getHandleOut(), coord);
}
void ConsoleView::print(Ñoordinates& coordinates, const string state)
{
	setCoordinates(coordinates);
	cout << state;
}
HANDLE& ConsoleView::getHandleOut()
{
	static HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	return handleOut;
}