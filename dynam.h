#pragma once
#include <iostream>
class dynam
{
private:
	int val;
	dynam* forward = nullptr;
	dynam* backward  = nullptr;
public:
	dynam(int input);
	int getdata();
	dynam* findnext();
	dynam* findback();
	void assignforward(dynam* forward);
	void assignbackward(dynam* backward);

};

