#include "MaxHeap.h"
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
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
		list[i] = nullptr;
	}
	size = 0;
}

MaxHeap::~MaxHeap()
{
	for (int i = 0; i < sizeofarray; i++) {
		if (heap[i] != nullptr) {
			delete heap[i];

		}
		if (list[i] != nullptr) {
			delete list[i];
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
		int x;
		bool heap_done = false;
		bool list_done = false;
		for (int i = 0; i < sizeofarray; i++) {

			if ((heap[i] == nullptr)&&heap_done==false) {
				 heap[i] = DBG_NEW student(GPA, Name);
				reaheap();
				heap_done = true;
			}
			if (list[i] == nullptr && list_done == false) {
				x = i;
			
				list[i] = DBG_NEW student(GPA, Name);
				while ((x > 0) && (list[x - 1]->getgpa() < list[x]->getgpa())) {
					std::swap(list[x], list[x - 1]);
					x--;
				}
				list_done = true;
			}
			if (heap_done==true && list_done == true) {
				size++;
				break;
			}
		}

		
	}
}

void MaxHeap::removeStudent(std::string Name)
{
	int x;
	bool heap_done = false;
	bool list_done = false;
	for (int i = 0; i < size; i++) {
		if ((heap[i] != nullptr) && heap_done == false) {
			if (heap[i]->getname() == Name) {
				std::swap(heap[i], heap[size-1]);
				delete heap[size - 1];
				heap[size - 1]= nullptr;

				heap_done = true;
				heapify(i);
			}
		}
		if (list[i] != nullptr && list_done == false) {
			if (list[i]->getname() == Name) {
				x = i;
				std::swap(list[i], list[size - 1]);
				delete list[size - 1];
				list[size - 1] = nullptr;
				qsort(0, size - 2);
				list_done = true;
			}
		}
		if (heap_done == true && list_done == true) {
			size--;
			
			return;
		}

	}
	std::cout << "could not find target";
}

void MaxHeap::updateStudent(std::string Name, float GPA)
{
	int x;
	bool heap_done = false;
	bool list_done = false;
	for (int i = 0; i < sizeofarray; i++) {
		if ((heap[i] != nullptr) && heap_done == false) {
			if (heap[i]->getname() == Name) {
				heap[i]->setgpa(GPA);
				heapify(i);

			}

		}
		if (list[i] != nullptr && list_done == false) {
			if (list[i]->getname() == Name) {
				x = i;
				list[i]->setgpa(GPA);
				qsort(0, size - 1);
				list_done = true;
			}
		}
		if (heap_done == true && list_done == true) {

			return;
		}
	}
	std::cout << "Nothing to update!";
}

void MaxHeap::printheap()
{

	int index = 1;
	for (int i = 0; i < sizeofarray; i++) {
		if (heap[i] != nullptr) {
			if ((i+1 == index)) {
				std::cout << std::endl;
				for (int x = 0;x <abs(15-index);x++) {
					std::cout << ' ';
				}
				index *= 2;

			}
			std::cout << ' ' << heap[i]->getname() <<' '<< heap[i]->getgpa();

			
		}
	}
	std::cout << std::endl << std::endl;

	for (int i = 0; i < sizeofarray-1; i++) {
		if (list[i] != nullptr) {
			std::cout << i+1 << ' ' << list[i]->getname() << ' ' << list[i]->getgpa()<<std::endl;
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
		std::swap(heap[index], heap[largest]);
		heapify(largest);
	}
}
void MaxHeap::reaheap() {
	for (int i = 0; i < size; i++) {
		heapify(i);
	}
}
int MaxHeap::partition(int first, int last)
{
	int middle = (first + last) / 2;
	std::swap(list[first], list[middle]); // swap the pivot element with first
	// element in the array
	int pivot = list[first]->getgpa();
	int smallIndex = first;
	for (int i = first + 1; i <= last; i++) //start from 2nd element
	{
		if (list[i]->getgpa() > pivot)
		{
			smallIndex++;
			std::swap(list[smallIndex], list[i]);
		}
	}
	std::swap(list[first], list[smallIndex]);
	return smallIndex;
}
void MaxHeap::qsort(int first, int last)
{

		if (first < last)
		{
			int pivotLocation = partition(first,last);
			qsort(first, pivotLocation - 1);
			qsort(pivotLocation + 1, last);
		}

}
