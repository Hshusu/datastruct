
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include"MaxHeap.h"

int main()
{
    bool running= true;
    std::string options;
    std::string name;
    int number;
    MaxHeap *heap = new MaxHeap();
    while (running == true) {
        std::cout << "Input Print , Add , Remove , Update or Quit"<<std::endl;
        std::cin >> options;
        if (options == "Print") {
            heap->printheap();
        }
        else if (options == "Add") {
            std::cout << "Input Name"<<std::endl;
            std::cin >> name;
            std::cout << "Input GPA " << std::endl;
            std::cin >> number;
            heap->addStudent(name, number);
        }
        else if (options == "Remove") {
            std::cout << "Input Name " << std::endl;
            std::cin >> name;
            heap->removeStudent(name);
        }
        else if (options == "Update") {
            std::cout << "Input Name " << std::endl;
            std::cin >> name;
            std::cout << "Input GPA " << std::endl;
            std::cin >> number;
            heap->addStudent(name, number);
        }
        else if (options == "Quit") {
            running = false;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    heap->printheap();
    delete heap;
    _CrtDumpMemoryLeaks();
}
