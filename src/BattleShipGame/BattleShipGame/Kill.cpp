#include "Kill.h"

void Kill::draw(const Coordinates& coordinates)
{
	ConsoleView::print(coordinates, "X");
}
bool Kill::getStepRepeat()
{
	return true;
}
