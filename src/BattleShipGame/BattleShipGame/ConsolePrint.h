#pragma once
#include <iostream>

#include "ConsoleView.h"
#include "Player.h"

using std::cout;
using std::endl;
using std::string;


#ifndef __CONSOLEPRINT_H__
#define __CONSOLEPRINT_H__

namespace ConsolePrint
{
	void printEmptyFields(int col, int row);
	void setCoordinatesName(string name, const Coordinates & cPrint);
	int getCoordinatesFromUser(int x, int y);

};

#endif // __CONSOLEPRINT_H__