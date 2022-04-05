#ifndef STACK_HH
#define STACK_HH

#include <iostream>
#include <assert.h>
#include "package.hh"
/*!
 * Ten plik zawiera definicje szablonu stack
 */

/*!
 * https://storm.cis.fordham.edu/zhang/cs2200/slides/stack.pdf jakbys sie kurwa serał i zapomnial 
 */
typedef package<1> stack_package;

struct packageNode
{
    stack_package info;
    packageNode* next;
};


class stack{
    private:
    packageNode* toppointero;
    public:
    void Push( stack_package pack );
    void Pop();
    void Top();
    char Top_get_ch()const;
    unsigned int Top_get_num()const;
    /*stack();
    stack(stack_package pack);
    ~stack();*/

};



void stack::Push (stack_package pack )
{
    packageNode* location;
    location = new packageNode;
    location->info = pack;
    location->next = this->toppointero;
    this->toppointero = location;
}


void stack::Pop()
{
        packageNode* temp;
        temp = this->toppointero;
        this->toppointero = this->toppointero ->next;
        delete temp;
}


void stack::Top()
{
    this->toppointero->info.show();
}


char stack::Top_get_ch()const
{
    return this->toppointero->info.get_ch();
}


unsigned int stack::Top_get_num()const
{
    return this->toppointero->info.get_num();
}


#endif