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
		list[i] = nullptr;
	}

}

MaxHeap::~MaxHeap()
{
	for (int i = 0; i < sizeofarray; i++) {
		if (list[i] != nullptr) {
			delete list[i];
		}

	}
}

void MaxHeap::addStudent(std::string Name, int GPA)
{
	for (int i = 0; i < sizeofarray; i++) {
		 if (list[i] == nullptr) {
			 list[i] = DBG_NEW student(GPA, Name);
			while (i>0) {
				if (list[findParent(i)]->getgpa() <= list[i]->getgpa()) {
					std::swap(list[findParent(i)], list[i]);
					i = ((i - (i % 2)) / 2);
				}
				else {
					
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
