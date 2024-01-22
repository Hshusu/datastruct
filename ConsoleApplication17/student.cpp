#include "student.h"

student::student(float GPA, std::string Name)
{
	this->GPA = GPA;
	this->Name = Name;
}

void student::setgpa(float GPA)
{
	this->GPA = GPA;
}



float student::getgpa()
{
	return GPA;
}

std::string student::getname()
{
	return Name;
}

