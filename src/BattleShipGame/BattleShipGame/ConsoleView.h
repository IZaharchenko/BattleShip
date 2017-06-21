#pragma once
#include <iostream>
#include <windows.h>

#include "Ñoordinates.h"

using namespace std;

#ifndef __CONSOLEVIEW_H__
#define __CONSOLEVIEW_H__

class ConsoleView
{
public:
	static void print(Ñoordinates& coordinates, const string state);
private:
	static void setCoordinates(Ñoordinates& coordinates);
	static HANDLE& getHandleOut();
};

#endif // __CONSOLEVIEW_H__