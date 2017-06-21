#include "�oordinates.h"

void �oordinates::setX(const int x)
{
	x_ = x;
}

void �oordinates::setY(const int y) 
{
	y_ = y;
}

int �oordinates::getX() {
	return x_;
}

int �oordinates::getY() {
	return y_;
}

bool �oordinates::operator==(const �oordinates& lhs)
{
	return (x_ == lhs.x_) && (y_ == lhs.y_);

}
bool �oordinates::operator!=(const �oordinates& lhs)
{
	return (x_ != lhs.x_) && (y_ != lhs.y_);

}