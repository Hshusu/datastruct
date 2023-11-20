#pragma once
#include <iostream>
class dynam
{
private:
	char val;
	dynam* forward;
	dynam* backward;
public:
	dynam(char input);
	char getdata();
	dynam* findnext();
	dynam* findback();
	void assignforward(dynam* forward);
	void assignbackward(dynam* backward);

};

