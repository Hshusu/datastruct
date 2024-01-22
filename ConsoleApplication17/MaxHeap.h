#pragma once



#include "student.h"
#include <iostream>
#define sizeofarray  80
class MaxHeap
{
private:

	student *heap[sizeofarray];
	int size;
	//student* findLchild(int x);
	int findParent(int x);
	void heapify(int index);
	void reaheap();
	void qsort(student* list[],int first, int last);
	int partition(student* list[], int first, int last);
	void swap(student*& one, student*& two);
public:
	MaxHeap();
	~MaxHeap();
	void addStudent(std::string Name, float GPA);
	void removeStudent(std::string Name);
	void updateStudent(std::string Name, float GPA);
	void printheap();

};

