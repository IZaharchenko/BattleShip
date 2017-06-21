#include "Boner.h"

void Boner::draw(const Coordinates& coordinates)
{
	ConsoleView::print(coordinates, "-");
}
bool Boner::getStepRepeat()
{
	return true;
}