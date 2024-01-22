#pragma once



#include "student.h"
#include <iostream>
#define sizeofarray  80
class MaxHeap
{
private:

	student *heap[sizeofarray];
	student* list[sizeofarray];
	int size;
	//student* findLchild(int x);
	int findParent(int x);
	void heapify(int index);
	void reaheap();
	void qsort(int first, int last);
	int partition(int first, int last);
public:
	MaxHeap();
	~MaxHeap();
	void addStudent(std::string Name, float GPA);
	void removeStudent(std::string Name);
	void updateStudent(std::string Name, float GPA);
	void printheap();

};

