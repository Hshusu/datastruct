#include "MaxHeap.h"
#include <iomanip>
int MaxHeap::findParent(int x)
{
	if (x > 0) {
		return((x - (x % 2)) / 2);
	}
	else return NULL;
}

MaxHeap::MaxHeap()
{
	for (int i = 0; i < sizeofarray; i++) {
		heap[i] = nullptr;
	}
	size = 0;
}

MaxHeap::~MaxHeap()
{
	for (int i = 0; i < sizeofarray; i++) {
		if (heap[i] != nullptr) {
			delete heap[i];

		}

	}

}

void MaxHeap::addStudent(std::string Name, float GPA)
{
	if (size >= sizeofarray) {
		std::cout << "too many students!!";
	}
	else {
		for (int i = 0; i < sizeofarray; i++) {
			if (heap[i] != nullptr) {
				if (heap[i]->getname() == Name) {
					std::cout << " Name already exists";
					return;
				
				}
			}
		}

		for (int i = 0; i < sizeofarray; i++) {

			if (heap[i] == nullptr) {
			 heap[i] = new student(GPA, Name);
				size++;
				reaheap();
				return;
			}
	
		}

		
	}
}

void MaxHeap::removeStudent(std::string Name)
{
	for (int i = 0; i < size; i++) {
		if ((heap[i] != nullptr)) {
			if (heap[i]->getname() == Name) {
				swap(heap[i], heap[size-1]);
				delete heap[size - 1];
				heap[size - 1]= nullptr;

				size--;
				heapify(i);
				return;
			}
		}

	}
	std::cout << "could not find target";
}
void MaxHeap::swap(student*& one, student*& two)
{
	student* temp = one;
	one = two;
	two = temp;
}
void MaxHeap::updateStudent(std::string Name, float GPA)
{
	
	for (int i = 0; i < sizeofarray; i++) {
		if (heap[i] != nullptr) {
			if (heap[i]->getname() == Name) {
				heap[i]->setgpa(GPA);
				heapify(i);
				return;
			}

		}
	}
	std::cout << "Nothing to update!";
}

void MaxHeap::printheap()
{

	int index = 1;
	student* list[sizeofarray];

	for (int i = 0; i < sizeofarray; i++) {
		list[i] = heap[i];

	}
	qsort(list, 0, size - 1);
	std::cout << "Top list:" << std::endl;
	float top = list[0]->getgpa();
	for (int i = 0; i < sizeofarray; i++) {
		if (list[i] != nullptr) {
			if (top > list[i]->getgpa()) {
				break;
			}
			std::cout << "Name: " << list[i]->getname() << " Gpa: " << std::setprecision(2) << std::fixed << list[i]->getgpa() << std::endl;
		}
	}
	std::cout << "Heap :"<<std::endl;
	for (int i = 0; i < sizeofarray; i++) {
		if (heap[i] != nullptr) {

			std::cout<< "Name: "<<heap[i]->getname() << " Gpa: " << std::setprecision(2) << std::fixed<< heap[i]->getgpa();
			std::cout << " left child: ";
			if (heap[2 * i + 1] != nullptr) {
				std::cout << heap[2 * i + 1]->getname();
			}
			else {
				std::cout << "NULL";
			}
			std::cout << " right child: ";
			if (heap[2 * i + 2] != nullptr) {
				std::cout << heap[2 * i + 2]->getname();
			}
			else {
				std::cout << "NULL";
			}
			std::cout<<std::endl;
			if ((i + 1 == index)) {

				std::cout << std::endl << "-------------------------------------------" << std::endl;

				index *= 2;

			}
		}
	}
	std::cout << std::endl << std::endl << "list :" << std::endl;
	for (int i = 0; i < sizeofarray; i++) {
		if (list[i] != nullptr) {
			std::cout<<'#' << i+1 << ' ' << list[i]->getname() << ' ' << std::setprecision(2) << std::fixed << list[i]->getgpa()<<std::endl;
		}
	}
}
void MaxHeap::heapify(int index) {
	int largest = index;
	int left_child = 2 * index + 1;
	int right_child = 2 * index + 2;
	if (left_child < size && heap[left_child]->getgpa() > heap[largest]->getgpa()) {
		largest = left_child;
	}
	if (right_child < size && heap[right_child]->getgpa() > heap[largest]->getgpa()) {
		largest = right_child;
	}
	if (largest != index) {
		swap(heap[index], heap[largest]);
		heapify(largest);
	}
}
void MaxHeap::reaheap() {
	for (int i = 0; i < size; i++) {
		heapify(i);
	}
}
int MaxHeap::partition(student* list[],int first, int last)
{
	int middle = (first + last) / 2;
	swap(list[first], list[middle]); // swap the pivot element with first
	// element in the array
	int pivot = list[first]->getgpa();
	int smallIndex = first;
	for (int i = first + 1; i <= last; i++) //start from 2nd element
	{
		if (list[i]->getgpa() > pivot)
		{
			smallIndex++;
			swap(list[smallIndex], list[i]);
		}
	}
	swap(list[first], list[smallIndex]);
	return smallIndex;
}
void MaxHeap::qsort(student* list[],int first, int last)
{

		if (first < last)
		{
			int pivotLocation = partition(list,first,last);
			qsort(list, first, pivotLocation - 1);
			qsort(list, pivotLocation + 1, last);
		}

}
