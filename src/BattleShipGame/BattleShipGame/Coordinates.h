#pragma once
#include <windows.h>

#ifndef _Coordinates_H
#define _Coordinates_H

class Coordinates
{
public:
	Coordinates(int x = 0, int y = 0) : x_(x), y_(y) {};
	void setX(const int x);
	void setY(const int y);
	int getX();
	int getY();
	bool operator!= (const Coordinates& lhs);
	bool operator == (const Coordinates& lhs);
private:
	int x_;
	int y_;
};

#endif //_Coordinates_H