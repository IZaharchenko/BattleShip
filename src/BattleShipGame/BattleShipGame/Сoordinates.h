#pragma once
#include <windows.h>

#ifndef _�OORDINATES_H
#define _�OORDINATES_H

class �oordinates
{
public:
	�oordinates(int x = 0, int y = 0) : x_(x), y_(y) {};
	void setX(const int x);
	void setY(const int y);
	int getX();
	int getY();
	bool operator!= (const �oordinates& lhs);
	bool operator == (const �oordinates& lhs);
private:
	int x_;
	int y_;
};

#endif //_�OORDINATES_H