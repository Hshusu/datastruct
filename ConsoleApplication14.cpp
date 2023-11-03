// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "dynam.h"
#include"LL.h"
#include <windows.h>
int main()
{
	char input;
	std::ifstream pathFile("path.txt");
	LL list;
	if (pathFile.is_open()) {
		while (pathFile >> input) {
			switch (input) {
			case 'U':
				list.insertlast(new dynam('U'));
				break;
			case 'D':
				list.insertlast(new dynam('D'));
				break;
			case 'L':
				list.insertlast(new dynam('L'));
				break;
			case 'R':
				list.insertlast(new dynam('R'));
				break;
			default:
				std::cout << "please only input U,D,L,R";
				break;
			}
		}
		pathFile.close();
	}
	list.printlist();
	while (1) {
		
		while ((GetAsyncKeyState('W')) || GetAsyncKeyState('S') || GetAsyncKeyState('X')) {
			system("cls");
			list.printlist();
			std::cout << std::endl;
			if (GetAsyncKeyState('W')) {
				list.setselectup();
			}
			if (GetAsyncKeyState('S')) {
				list.setselectdown();
			}
			if (GetAsyncKeyState('X')) {
				list.setselect();
			}
			std::cout << std::endl;
			Sleep(100);
		}
	}


 
}

