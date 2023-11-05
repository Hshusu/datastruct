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
	gotoxy(x, y);
	if (selected == temp) {
		std::cout << 'O';
	}
	else {
		std::cout << 'X';
	}
	if ((first != nullptr) && (last != nullptr)) {
		temp = temp->findnext();
	}
	while (temp != nullptr) {
		switch (temp->getdata())
		{
		case 'U':
			y--;
			gotoxy(x, y);
			std::cout << '|';
			y--;
			gotoxy(x, y);
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
		if (selected == temp) {
			std::cout << 'O';
		}
		else {
			std::cout << 'X';
		}

		temp = temp->findnext();



	} ;
			


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
		gotoxy(0, y + 5);
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

	 if (first == last) {

		delete first;
		first = nullptr;
		last = nullptr;
		std::cout << "cannot delete anything else !";
		exit(0);

	  }
	else if (selected->findback() == nullptr) {
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