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
	if (first == nullptr) {
		std::cout << "nothing to destroy lol";
	}
	else {

		dynam* current = first;
		while (current != nullptr) {
			current = current->findnext();
			std::cout << first->getdata() << "has been destroyed " << std::endl;
			delete first;
			first = current;
		}
	}
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
	
}
void LL::insertlast(dynam* input)
{
	if (last != nullptr) {
		last->assignforward(input);
		input->assignbackward(last);
	}
	else {
		first = input;
	}
	last = input;
}
void LL::printlist()
{
	short x =0, y =0;

	dynam* temp = first;
	while (temp != nullptr) {
		COORD input_pos = { x,y };
		HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsoleOutput, input_pos);
		std::cout << 'X';
		switch (temp->getdata())
		{
		case 'U':
			y --;
			gotoxy(x, y);
			std::cout << '|';
			y --;
			break;
		case 'D':
			y++;
			gotoxy(x, y);
			std::cout << '|';
			y++;
			gotoxy(x, y);
			break;
		case 'L':
			x--;
			gotoxy(x, y);
			std::cout << '-';
			x--;
			gotoxy(x, y);
			break;
		case 'R':
			x++;
			gotoxy(x, y);
			std::cout << '-';
			x++;
			gotoxy(x, y);
			break;
		default:
			break;
		}
		temp = temp->findnext();

	}

	std::cout << 'X';
	/*dynam* temp = first;
	while (temp != nullptr) {


		if (temp == selected) {
			std::cout << "\033[1;31m" << temp->getdata() << "  <-----" << "\033[0m";
		}
		else {

			std::cout << temp->getdata();
		}

		if (temp != last) {
			std::cout << '-';
		}
		temp = temp->findnext();

	}*/
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

void LL::printselect()
{
	if (selected != nullptr) {
		std::cout << selected->getdata();
	}
}

void LL::setselect(char x)
{
	dynam* temp = new dynam(x);
	if (selected->findnext() == nullptr) {
		insertlast(temp);
	}
	else {
		temp->assignbackward(selected);
		temp->assignforward(selected->findnext());
		(selected->findnext())->assignbackward(temp);
		selected->assignforward(temp);
	}



	
}

void LL::setselectdown()
{
	if (selected == nullptr) { selected = first; }
	else {
		selected = selected->findnext();
	}
}

void LL::setselectup()
{
	if (selected == nullptr) { selected = last; }
	else {
		selected = selected->findback();
	}


}
void LL::gotoxy(int x, int y) 
{ COORD scrn;
HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
scrn.X = x; 
scrn.Y = y;
SetConsoleCursorPosition(hConsoleOutput, scrn); }