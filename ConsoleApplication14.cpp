// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dynam.h"
#include"LL.h"
#include <windows.h>
int main()
{
	LL list;
	list.insertfirst(new dynam(111111));
	list.insertlast(new dynam(4444444));
	list.insertlast(new dynam(2222222));
	list.insertlast(new dynam(55555555));
	list.insertfirst(new dynam(3333333));
	
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
				list.setselect(9999999);
			}
			std::cout << std::endl;
			Sleep(100);
		}
	}


 
}

