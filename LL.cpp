#include "LL.h"
#include <windows.h>
#include <conio.h>
LL::LL()
{
	first = nullptr;
	last = nullptr;
	selected = nullptr;
}

LL::~LL()
{
	//if (first == nullptr) {
	//	std::cout << "nothing to destroy lol";
	//}
	//else {

	//	dynam* current = first;
	//	while (current != nullptr) {
	//		current = current->findnext();
	//		std::cout << first->getdata() << "has been destroyed " << std::endl;
	//		delete first;
	//		first = current;
	//	}
	//}
}

void LL::insertfirst(dynam* input)
{
	if (first != nullptr) {
		input->assignforward(first);
		first->assignbackward(input);
	}
	else {
		last = input;
	}
	 first = input;
	 selected = input;
	
}
void LL::insertlast(dynam* input)
{
	if (last != nullptr) {
		last->assignforward(input);
		input->assignbackward(last);
	
	}
	else {
		first = input;
		selected = input;
	}
	last = input;
}
void LL::printlist()
{


	short x = 0, y = 0;

	dynam* temp = first;
	COORD input_pos = { x,y };
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, input_pos);

	do {
		gotoxy(x, y);
		if (selected == temp) {
			std::cout << 'O';
		}
		else {
			std::cout << 'X';
		}
		switch (temp->getdata())
		{
		case 'U':
			y--;
			gotoxy(x, y);
			std::cout << '|';
			y--;

			break;
		case 'D':
			y++;
			gotoxy(x, y);
			std::cout << '|';
			y++;

			break;
		case 'L':
			x--;
			gotoxy(x, y);
			std::cout << '-';
			x--;

			break;
		case 'R':
			x++;
			gotoxy(x, y);
			std::cout << '-';
			x++;

			break;
		case 'S':
			gotoxy(x, y);
			break;
		default:
			break;
		}


		temp = temp->findnext();



	} while (temp->findnext() != nullptr);
	gotoxy(x, y);
	if (selected == temp) {
		std::cout << 'O';
	}
	else {
		std::cout << 'X';
	}
	gotoxy(0, y + 5);
	std::cout << "use wasd to move, + and - for insertion and deletion";
	}


void LL::deletefirst()
{
	if (first != nullptr) {
		dynam* temp = first->findnext();
		delete first;
		first = temp;
		first->assignbackward(nullptr);
	}
	else if (first == last) {
	
		delete first;
		first = nullptr;
		last = nullptr;

	}
}

void LL::deletelast()
{
}

void LL::deleteselected()
{

	 if (selected->findback() == nullptr) {
		if (selected->findnext() != nullptr) {
			dynam* temp = selected->findnext();
			selected->findnext()->assignbackward(nullptr);

			delete selected;
			first=selected = temp;


			
		}

	}
	else if (selected->findnext() == nullptr) { // end of list
		if (selected->findback() != nullptr) {
			selected->findback()->assignforward(nullptr);
			dynam* temp = selected->findback();
			delete selected;
			last=selected = temp;

		}
	}
	else {

		selected->findback()->assignforward(selected->findnext());
		selected->findnext()->assignbackward(selected->findback());
		dynam* temp = selected->findback();
		delete selected;
		selected = temp;
	}

	if (first == last) {

		delete first;
		first = nullptr;
		last = nullptr;
		std::cout << "cannot delete anything else !";
		exit(0);

	}
}

void LL::printselect()
{
	if (selected != nullptr) {
		std::cout << selected->getdata();
	}
}

void LL::setselect()
{
	
	
	if (selected->findback() == nullptr) {
		dynam* temp = new dynam(selected->findnext()->getdata());
		insertfirst(temp);
	}
	else if (selected->findnext() == nullptr) {
		dynam* temp = new dynam(selected->findback()->getdata());
		insertlast(temp);
	}
	else {
			
		dynam* temp = new dynam(selected->getdata());
		temp->assignbackward(selected);
		temp->assignforward(selected->findnext());
		(selected->findnext())->assignbackward(temp);
		selected->assignforward(temp);
	}



	
}

void LL::setselectdown()
{
	if (selected->findnext() != nullptr) {
		selected = selected->findnext();
	}
}

void LL::controls(char)
{
	

	if (GetAsyncKeyState('W')) {
		if ((selected->findback() != nullptr) && (selected->findback()->getdata() == 'D')) {
			setselectup();
		}

		if (selected->getdata() == 'U') {
			setselectdown();
		}
	}
	if (GetAsyncKeyState('S')) {
		if ((selected->findback() != nullptr) && (selected->findback()->getdata() == 'U')) {
			setselectup();
		}

		if (selected->getdata() == 'D') {
			setselectdown();
		}
	}

	if (GetAsyncKeyState('A')) {
		if ((selected->findback() != nullptr) && (selected->findback()->getdata() == 'R')) {
			setselectup();
		}

		if (selected->getdata() == 'L') {
			setselectdown();
		}
	}
	if (GetAsyncKeyState('D')) {
		if ((selected->findback() != nullptr) && (selected->findback()->getdata() == 'L')) {
			setselectup();
		}

		if (selected->getdata() == 'R'){
			setselectdown();
		}
	}

	if (GetAsyncKeyState(0xBB)) {
		setselect();
	}
	if (GetAsyncKeyState(0xBD)) {
		deleteselected();
	}
	std::cout << std::endl;

	system("cls");
	printlist();
	Sleep(100);
}

void LL::setselectup()
{
	if (selected->findback() != nullptr) {
		selected = selected->findback();
	}


}
void LL::gotoxy(int x, int y) 
{ COORD scrn;
HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
scrn.X = x; 
scrn.Y = y;
SetConsoleCursorPosition(hConsoleOutput, scrn); }