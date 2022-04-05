#ifndef UNPACKING_HH
#define UNPACKING_HH


#include <iostream>
#include <assert.h>
#include "package.hh"
#include "stack.hh"

template <int size>
class unpacking{
    private:
    char _decoded_message[size];
    public:
    void unpack_them_all(stack stacko);
    char* decoded_message()
    {
        return _decoded_message;
    }
    /*unpacking();
    unpacking(stack stacko);
    ~unpacking();*/

};

template <int size>
void unpacking<size>::unpack_them_all(stack stacko)
{
    int i;
    for(i=0;i<size;++i)
    {
        this->_decoded_message[stacko.Top_get_num()]=stacko.Top_get_ch();
        stacko.Pop();
    }
}




#endif