#include "student.h"

student::student(float GPA, std::string Name)
{
	if (GPA > 4.0) {
		this->GPA = 4.0;
	}
	else {
		this->GPA = GPA;
	}
	this->Name = Name;
}

void student::setgpa(float GPA)
{
	if (GPA > 4.0) {
		this->GPA = 4.0;
	}
	else {
		this->GPA = GPA;
	}
}



float student::getgpa()
{
	return GPA;
}

std::string student::getname()
{
	return Name;
}

