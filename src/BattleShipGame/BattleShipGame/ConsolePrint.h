#pragma once
#include <iostream>

#include "ConsoleView.h"
#include "Player.h"

using std::cout;
using std::endl;

#ifndef __CONSOLEPRINT_H__
#define __CONSOLEPRINT_H__

namespace ConsolePrint
{
	void printEmptyFields(int col, int row);
	int setCoordinatesName(int x, int y);
	int getCoordinatesFromUser(int x, int y);

};

#endif // __CONSOLEPRINT_H__