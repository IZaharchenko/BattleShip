#pragma once
#include <iostream>
#include <windows.h>

#include "Coordinates.h"

using std::string;

#ifndef __CONSOLEVIEW_H__
#define __CONSOLEVIEW_H__

namespace ConsoleView
{
	static void print(const Coordinates& coordinates, const string state);
	static void setCoordinates(const Coordinates& coordinates);
	static const HANDLE& getHandleOut();
};

#endif // __CONSOLEVIEW_H__