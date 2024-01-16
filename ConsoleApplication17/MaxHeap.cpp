#include "MaxHeap.h"

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
		list[i] = nullptr;
	}

}

void MaxHeap::addStudent(std::string Name, int GPA)
{
	for (int i = 0; i < sizeofarray+1; i++) {
	
		 if (list[i] == nullptr) {
			 list[i] = new student(GPA, Name);
			while (i>0) {
				if (list[findParent(i)]->getgpa() <= list[i]->getgpa()) {
					std::swap(list[findParent(i)], list[i]);
					i = ((i - (i % 2)) / 2);
				}
				else {
					std::cout << "hellooo";
					break;
				}
			}
			break;
			}

		}
		
	}

void MaxHeap::printlist()
{
	for (int i = 0; i < sizeofarray; i++) {
		if (list[i] != nullptr) {
			std::cout << list[i]->getname() << "  " << list[i]->getgpa() << std::endl;
		}
	}
}
