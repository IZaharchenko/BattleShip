#include "Injure.h"

void Injure::draw(const Coordinates& coordinates)
{
	ConsoleView::print(coordinates, "+");
}
bool Injure::getStepRepeat()
{
	return true;
}
