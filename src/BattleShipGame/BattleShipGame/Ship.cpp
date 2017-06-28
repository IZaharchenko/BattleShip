#include <iostream>
#include "Ship.h"

#include <vector>
#include <algorithm>

using std::vector;
using std::size_t;

Ship::Ship() : Ship(vector<Coordinates>()) { };

Ship::Ship(vector<Coordinates> body) : body_(body) { };

bool Ship::searchInBody(const Coordinates& coordinates)
{
	bool result = false;
	const auto findItem = std::find(body_.begin(), body_.end(), coordinates);
	if (findItem != body_.end())
	{
		result = true;
	}
	return result;
}
void Ship::drawBody(int shifX, int shiftY)
{
	for (size_t i = 0; i < body_.size(); i++)
	{
		ConsoleView::print(body_[i].getX() + shifX, 
			body_[i].getY() + shiftY, "O");
	}
}
const vector<Coordinates> Ship::getBody()
{
	return body_;
}

