#pragma once
#include <windows.h>

#ifndef _Coordinates_H
#define _Coordinates_H

class Coordinates
{
public:
	Coordinates(int x, int y);
	void setX(const int x);
	void setY(const int y);
	int getX() const;
	int getY() const;
	bool operator!= (const Coordinates& lhs);
	bool operator == (const Coordinates& lhs);
private:
	int x_;
	int y_;
};

#endif //_Coordinates_H