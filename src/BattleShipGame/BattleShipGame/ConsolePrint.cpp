#include <iomanip>
#include <iostream>

#include "ConsolePrint.h"
#include "ConsoleView.h"

using std::setw;

void ConsolePrint::printEmptyFields(int col, int row)
{
	const char topLeft = static_cast<char>(218);
	const char topRight = static_cast<char>(191);

	const char horizontal = static_cast<char>(196);
	const char vertical = static_cast<char>(179);

	const char bottomLeft = static_cast<char>(192);
	const char bottomRight = static_cast<char>(217);

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
