#pragma once



#include "student.h"
#include <iostream>
#define sizeofarray  80
class MaxHeap
{
private:

	student *list[sizeofarray];
	//student* findLchild(int x);
	int findParent(int x);
public:
	MaxHeap();
	~MaxHeap();
	void addStudent(std::string Name, int GPA);
	void printlist();
};

