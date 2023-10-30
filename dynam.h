#pragma once
#include <iostream>
class dynam
{
private:
	char val;
	dynam* forward = nullptr;
	dynam* backward  = nullptr;
public:
	dynam(char input);
	char getdata();
	dynam* findnext();
	dynam* findback();
	void assignforward(dynam* forward);
	void assignbackward(dynam* backward);

};

