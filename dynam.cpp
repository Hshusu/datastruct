#include "dynam.h"

dynam::dynam(int input)
{
	val = input;

}

int dynam::getdata()
{
	return val;
}

dynam* dynam::findnext()
{
	return forward;
}

dynam* dynam::findback()
{
	return backward;
}

void dynam::assignforward(dynam* forward)
{
	this->forward = forward;
}

void dynam::assignbackward(dynam* backward)
{
	this->backward = backward;
}
