#ifndef PACKING_HH
#define PACKING_HH


#include <iostream>
#include <assert.h>
#include "package.hh"
#include "stack.hh"
#include "random.hh"

template <int size>
class packing{
    private:
    stack _stacko;//stack do ktorego chcemy zapakowac nasze pakiety danych z tekstu
    public:
    void pack_them_all(char message[]);
    stack get()
    {
        return this->_stacko;
    }
};

template <int size>
void packing<size>::pack_them_all(char message[])
{
    int i;
    package<1> pack;
    random_with_no_repeats<size> pack_random;
    pack_random.randomize();//tworzymy tablice losowy niepowtarzajacych sie liczb
    for(i=0;i<size;++i)
    {
        pack.change(&message[pack_random[i]],pack_random[i]);//pakujemy do pakietow numery wystepowania danej litery i litere
        this->_stacko.Push(pack);
        this->_stacko.Top();
    }

}

#endif