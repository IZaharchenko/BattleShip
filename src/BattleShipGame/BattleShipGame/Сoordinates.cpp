#include "Coordinates.h"

void Coordinates::setX(const int x)
{
	x_ = x;
}

void Coordinates::setY(const int y) 
{
	y_ = y;
}

int Coordinates::getX() const {
	return x_;
}

int Coordinates::getY() const {
	return y_;
}

bool Coordinates::operator==(const Coordinates& lhs)
{
	return (x_ == lhs.x_) && (y_ == lhs.y_);

}
bool Coordinates::operator!=(const Coordinates& lhs)
{
	return (x_ != lhs.x_) && (y_ != lhs.y_);

}