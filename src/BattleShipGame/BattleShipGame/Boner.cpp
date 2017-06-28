#include "Boner.h"

void Boner::draw(const int x, const int y)
{
	ConsoleView::print(x, y, "-");
}
bool Boner::getStepRepeat()
{
	return true;
}