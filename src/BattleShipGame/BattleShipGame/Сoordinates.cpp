#include "Ñoordinates.h"

void Ñoordinates::setX(const int x)
{
	x_ = x;
}

void Ñoordinates::setY(const int y) 
{
	y_ = y;
}

int Ñoordinates::getX() {
	return x_;
}

int Ñoordinates::getY() {
	return y_;
}

bool Ñoordinates::operator==(const Ñoordinates& lhs)
{
	return (x_ == lhs.x_) && (y_ == lhs.y_);

}
bool Ñoordinates::operator!=(const Ñoordinates& lhs)
{
	return (x_ != lhs.x_) && (y_ != lhs.y_);

}