// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dynam.h"
#include"LL.h"
#include <windows.h>
int main()
{
	LL list;
	list.insertfirst(new dynam('D'));
	list.insertlast(new dynam('D'));
	list.insertlast(new dynam('R'));
	list.insertlast(new dynam('D'));
	list.insertlast(new dynam('R'));
	list.insertlast(new dynam('R'));

	list.insertlast(new dynam('R'));
	list.insertlast(new dynam('D'));
	list.insertlast(new dynam('D'));
	list.insertlast(new dynam('D'));
	list.insertlast(new dynam('L'));
	list.insertlast(new dynam('L'));
	list.insertlast(new dynam('L'));
	list.insertlast(new dynam('U'));
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

