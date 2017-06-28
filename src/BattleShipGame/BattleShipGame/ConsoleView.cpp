#include <string>
#include "ConsoleView.h"

using std::cout;

void ConsoleView::setCoordinates(int x, int y)
{
	COORD coord{ static_cast<short>(x), static_cast<short>(y) };
	SetConsoleCursorPosition(getHandleOut(), coord);
}
void ConsoleView::print(const int x, const int y, const string state)
{
	setCoordinates(x, y);
	cout << state;
}
const HANDLE& ConsoleView::getHandleOut()
{
	static const HANDLE& handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	return handleOut;
}
