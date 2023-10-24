#pragma once
#include "dynam.h"
class LL
{
private:
    dynam* first;// remembers the first ptr
    dynam* last;// remembers the last ptr
    dynam* selected;
public:
    LL();
    void insertfirst(dynam* input);
    void insertlast(dynam* input);
    void deletefirst();
    void deletelast();
    void printlist();
    void setselect(int x);
    void setselectup();
    void setselectdown();
    void printselect();
};

