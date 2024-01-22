#pragma once
#include <iostream>
class student
{
private :
	float GPA;
	std::string Name;
public :
	student(float GPA , std::string Name);
	void setgpa(float GPA);
	float getgpa();
	std::string getname();
};

