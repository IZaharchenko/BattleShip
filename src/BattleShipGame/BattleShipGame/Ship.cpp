#include <iostream>
#include "Ship.h"

#include <vector>
#include <algorithm>
using namespace std;

bool Ship::searchInBody(Ñoordinates coordinates)
{
	bool result = false;
	auto findItem = std::find(body_.begin(), body_.end(), coordinates);
	if (findItem != body_.end())
	{
		result = true;
	}
	return result;
}
void Ship::drawBody()
{
	for (int i = 0; i < body_.size(); i++)
	{
		ConsoleView::print(body_[i], "O");
	}
}
