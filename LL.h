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
    ~LL();
    void insertfirst(dynam* input);
    void insertlast(dynam* input);
    void deletefirst();
    void deletelast();
    void deleteselected();
    void printlist();
    void setselect();
    void setselectup();
    void setselectdown();
    void controls(char input);
    void printselect();
    void gotoxy(int x, int y);

};

