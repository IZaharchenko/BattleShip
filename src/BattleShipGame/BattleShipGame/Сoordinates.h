#pragma once
#include <windows.h>

#ifndef _ÑOORDINATES_H
#define _ÑOORDINATES_H

class Ñoordinates
{
public:
	Ñoordinates(int x = 0, int y = 0) : x_(x), y_(y) {};
	void setX(const int x);
	void setY(const int y);
	int getX();
	int getY();
	bool operator!= (const Ñoordinates& lhs);
	bool operator == (const Ñoordinates& lhs);
private:
	int x_;
	int y_;
};

#endif //_ÑOORDINATES_H