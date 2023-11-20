// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "dynam.h"
#include <conio.h>
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
		list.insertlast(new dynam('D'));
		pathFile.close();
	}

	list.controls();



 
}

