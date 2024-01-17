
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include"MaxHeap.h"

int main()
{
    MaxHeap heap;
    heap.addStudent("A", 451);
    heap.addStudent("B", 41);
    heap.addStudent("C", 311);
    heap.addStudent("D", 1);
    heap.addStudent("E", 2);
    heap.printlist();

 



    std::cout << "Hello World!\n";
    
}
