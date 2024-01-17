#pragma once
#include <iostream>
class student
{
private :
	int GPA;
	std::string Name;
public :
	student(int GPA , std::string Name);

	int getgpa();
	std::string getname();
};

