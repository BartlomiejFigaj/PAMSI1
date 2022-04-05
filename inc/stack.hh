#ifndef STACK_HH
#define STACK_HH

#include <iostream>
#include <assert.h>
#include "package.hh"

typedef package<1> stack_package;
//postac wezla uzywanego w naszym stosie
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


//tworzenie nowego wezla i ustawianie go jako top
void stack::Push (stack_package pack )
{
    packageNode* location;
    location = new packageNode;
    location->info = pack;
    location->next = this->toppointero;
    this->toppointero = location;
}

//usuwanie topowego wezla i ustawianie nastepnego jako top
void stack::Pop()
{
        packageNode* temp;
        temp = this->toppointero;
        this->toppointero = this->toppointero ->next;
        delete temp;
}

//pokazywanie
void stack::Top()
{
    this->toppointero->info.show();
}

//dostep do topowego pakietu i jego litery
char stack::Top_get_ch()const
{
    return this->toppointero->info.get_ch();
}

//dostep do topowego pakietu i jego numeru
unsigned int stack::Top_get_num()const
{
    return this->toppointero->info.get_num();
}


#endif