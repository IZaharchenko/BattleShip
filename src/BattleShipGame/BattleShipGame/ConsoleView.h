#pragma once
#include <iostream>
#include <windows.h>

#include "Coordinates.h"

using std::string;

#ifndef __CONSOLEVIEW_H__
#define __CONSOLEVIEW_H__

namespace ConsoleView
{
	void print(const int x, const int y, const string state);
	void setCoordinates(int x, int y);
	const HANDLE& getHandleOut();
};

#endif // __CONSOLEVIEW_H__