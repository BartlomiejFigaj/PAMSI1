#ifndef PACKAGE_HH
#define PACKAGE_HH


#include <iostream>
#include <assert.h>

template < int ch_size>
class package{
    private:
     int _number;
    char _ch;
    public:
    /*package();
    package(char c, int num);
    ~package();*/
    void change(char *c, int num);
    void show()const;
    char get_ch()const;
    int get_num()const; 

};

template < int ch_size>
void package<ch_size>::change(char *c,int num)
{
    this->_ch=*c;
    this->_number=num;
}
/*
template < int ch_size>
package<ch_size>::package(char c,int num)
{
    this->_ch=c;
    this->_number=num;
}*/

template < int ch_size>
void package<ch_size>::show()const
{
    std::cout << "[ " << this->_ch << " , " << this->_number << " ]" << std::endl;
}

template < int ch_size>
char package<ch_size>::get_ch()const
{
    return this->_ch;
}

template < int ch_size>
 int package<ch_size>::get_num()const
{
    return this->_number;
}

#endif