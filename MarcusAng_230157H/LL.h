#pragma once
#include "dynam.h"
class LL
{
private:
    dynam* first;// remembers the first ptr
    dynam* last;// remembers the last ptr
    dynam* selected;
    int size;
public:
    LL();
    ~LL();
    void insertfirst(dynam* input);
    void insertlast(dynam* input);
    void deleteselected();
    void printlist();
    void setselect();
    void setselectup();
    void setselectdown();
    void controls();
    void gotoxy(int x, int y);

};

