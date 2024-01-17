#include "student.h"

student::student(int GPA, std::string Name)
{
	this->GPA = GPA;
	this->Name = Name;
}



int student::getgpa()
{
	return GPA;
}

std::string student::getname()
{
	return Name;
}

