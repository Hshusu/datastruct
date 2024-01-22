
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
        std::cout << "Input print , add , remove , update or quit"<<std::endl;
        std::cin >> options;
        if (options == "print") {
            heap->printheap();
        }
        else if (options == "add") {
            std::cout << "Input Name"<<std::endl;
            std::cin >> name;
            std::cout << "Input GPA " << std::endl;
            std::cin >> number;
            heap->addStudent(name, number);
        }
        else if (options == "remove") {
            std::cout << "Input Name " << std::endl;
            std::cin >> name;
            heap->removeStudent(name);
        }
        else if (options == "update") {
            std::cout << "Input Name " << std::endl;
            std::cin >> name;
            std::cout << "Input GPA " << std::endl;
            std::cin >> number;
            heap->updateStudent(name, number);
        }
        else if (options == "quit") {
            running = false;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    heap->printheap();
    delete heap;
}
