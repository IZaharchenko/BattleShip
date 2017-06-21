#include <string>
#include "ConsoleView.h"

using std::cout;

void ConsoleView::setCoordinates(const Coordinates& coordinates)
{
	Coordinates& c = const_cast<Coordinates&>(coordinates);
	COORD coord{ c.getX(), c.getY() };
	SetConsoleCursorPosition(getHandleOut(), coord);
}
void ConsoleView::print(const Coordinates& coordinates, const string state)
{
	setCoordinates(coordinates);
	cout << state;
}
const HANDLE& ConsoleView::getHandleOut()
{
	static const HANDLE& handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	return handleOut;
}