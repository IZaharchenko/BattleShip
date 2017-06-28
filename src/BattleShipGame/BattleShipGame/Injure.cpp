#include "Injure.h"

void Injure::draw(const int x, const int y)
{
	ConsoleView::print(x, y, "+");
}
bool Injure::getStepRepeat()
{
	return true;
}
