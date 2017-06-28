#include <iomanip>
#include <iostream>
#include <string>

#include "ConsolePrint.h"
#include "ConsoleView.h"

#include "nShips_sizeField.h"
#include "ConsoleCoordinates.h"


using std::setw;
using std::cin;


void ConsolePrint::printEmptyFields(int col, int row)
{
	const char topLeft = static_cast<unsigned char>(218);
	const char topRight = static_cast<unsigned char>(191);

	const char horizontal = static_cast<unsigned char>(196);
	const char vertical = static_cast<unsigned char>(179);

	const char bottomLeft = static_cast<unsigned char>(192);
	const char bottomRight = static_cast<unsigned char>(217);

	cout << endl;
	cout << endl;
	//user
	for (int i = 0; i < col; i++)
	{
		cout << ' ';
	}
	for (char i = 'A'; i < 'K'; i++)
	{
		cout << i;
	}
	for (int i = 0; i < (col + 3); i++)
	{
		cout << ' ';
	}
	//computer
	for (char i = 'A'; i < 'K'; i++)
	{
		cout << i;
	}
	cout << endl;
	//user
	for (int i = 0; i < col - 1; i++)
	{
		cout << ' ';
	}
	cout << topLeft;
	for (int i = 0; i < 10; i++)
	{
		cout << horizontal;
	}
	cout << topRight;
	//computer
	for (int i = 0; i < (col + 1); i++)
	{
		cout << ' ';
	}
	cout << topLeft;
	for (int i = 0; i < 10; i++)
	{
		cout << horizontal;
	}
	cout << topRight;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		//user
		for (int i = 0; i < col - 3; i++)
		{
			cout << ' ';
		}
		cout << setw(2) << i + 1;
		cout << vertical;
		for (int i = 0; i < 10; i++)
		{
			cout << ' ';
		}
		cout << vertical;
		//computer
		for (int i = 0; i < col - 1; i++)
		{
			cout << ' ';
		}
		cout << setw(2) << i + 1;
		cout << vertical;
		for (int i = 0; i < 10; i++)
		{
			cout << ' ';
		}
		cout << vertical;
		cout << endl;
	}
	//user
	for (int i = 0; i < (col - 1); i++)
	{
		cout << ' ';
	}
	cout << char(192);
	for (int i = 0; i < 10; i++)
	{
		cout << char(196);
	}
	cout << char(217);
	//computer
	for (int i = 0; i < (col + 1); i++)
	{
		cout << ' ';
	}
	cout << char(192);
	for (int i = 0; i < 10; i++)
	{
		cout << char(196);
	}
	cout << char(217);
	cout << endl;

}

int ConsolePrint::getCoordinatesFromUser(int x, int y)
{
	while (true)
	{
		ConsoleView::setCoordinates(x, y);
		int x = 0;
		cin >> x;
		if (x > 0 && x < fieldSize) { return x; }
		ConsoleView::setCoordinates(x, y);
		cout << "   ";
	}
}

void ConsolePrint::setCoordinatesName(string name, const Coordinates & cPrint)
{
	ConsoleView::setCoordinates(cPrint.getX(), cPrint.getY());
	cout << name << " = ";
}

