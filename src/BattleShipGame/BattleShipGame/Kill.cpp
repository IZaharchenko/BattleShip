#include "Kill.h"

void Kill::draw(const int x, const int y)
{
	ConsoleView::print(x, y, "X");
}
bool Kill::getStepRepeat()
{
	return true;
}
