#include "LL.h"
#include <windows.h>
#include <conio.h>
LL::LL()
{
	first = nullptr;
	last = nullptr;
	selected = nullptr;
	size = 0;
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

	
	short x = 0, y = 2;

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
		size++;


	} while (temp->findnext() != nullptr);
	gotoxy(x, y);
	if (selected == temp) {
		std::cout << 'O';
	}
	else {
		std::cout << 'X';
	}
	gotoxy(0, y + 5);
	
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
		dynam* temp = selected->findnext();
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

void LL::controls()
{
	char input;
	bool running = true;
	printlist();
	while (running == true) {
		gotoxy(0, 0);
		std::cout << "use wasd to move, + and - for insertion and deletion , use q quit";

		std::cin >> input;
		system("cls");

		if (input == 'w') {
			if ((selected->findback() != nullptr) && (selected->findback()->getdata() == 'D')) {
				setselectup();
			}
			else if (selected->getdata() == 'U') {
				setselectdown();
			}
			else {
				std::cout << std::endl;
				std::cout << "invalid direction";
			}
		}
		else if (input == 's') {
			if ((selected->findback() != nullptr) && (selected->findback()->getdata() == 'U')) {
				setselectup();
			}
			else if (selected->getdata() == 'D') {
				setselectdown();
			}
			else {
				std::cout << std::endl;
				std::cout << "invalid direction";
			}
		}
		else if (input == 'a') {
			if ((selected->findback() != nullptr) && (selected->findback()->getdata() == 'R')) {
				setselectup();
			}
			else if (selected->getdata() == 'L') {
				setselectdown();
			}
			else {
				std::cout << std::endl;
				std::cout << "invalid direction";
			}
		}
		else if (input == 'd') {
			if ((selected->findback() != nullptr) && (selected->findback()->getdata() == 'L')) {
				setselectup();
			}
			else if (selected->getdata() == 'R') {
				setselectdown();
			}
			else {
				std::cout << std::endl;
				std::cout << "invalid direction";
			}
		}
		else if (input == 'q') {
			running = false;
		}
		else if (input == '+') {
			setselect();
		}
		else if (input == '-') {
			deleteselected();
		}
		else {
			std::cout << std::endl;
			std::cout << "invalid input";
		}
		printlist();


	}
	for (int i = 0; i < size; i++) {
		deleteselected();
	}
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