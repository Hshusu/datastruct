#include "LL.h"

LL::LL()
{
	first = nullptr;
	last = nullptr;
	selected = nullptr;
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
	dynam* temp = first;
	while (temp != nullptr) {

		
		if (temp == selected) {
			std::cout << "\033[1;31m" << temp->getdata()<<"  <-----" << "\033[0m";
		}
		else { 
		
			std::cout << temp->getdata(); }
	
		if (temp != last) {
			std::cout << '-';
		}
		temp = temp->findnext();

	}
}

void LL::deletefirst()
{
	if (first != nullptr) {
		dynam* temp = first->findnext();
		delete first;
		first = temp;
		first->assignbackward(nullptr);
	}
}

void LL::printselect()
{
	if (selected != nullptr) {
		std::cout << selected->getdata();
	}
}

void LL::setselect(int x)
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

