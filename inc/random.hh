#ifndef RANDOM_HH
#define RANDOM_HH

#include <iostream>
#include <cstdlib>
#include <ctime>

#define message_length 160

template <int size>
class random_with_no_repeats{
    private:
    int _random[size];
    int _how_many=0;
    public:
    bool is_randomized(int number);
    int randomize();
    int operator[](int number);
    /*random_with_no_repeats();
    random_with_no_repeats(int from);
    ~random_with_no_repeats();*/
};

template <int size>
bool random_with_no_repeats<size>::is_randomized(int number)//funkcja ktora sprawdza czy dany numer wystapil w tablicy
{
    int i = 0;
    if( this->_how_many <= 0 )
        return false;
    while( i < this->_how_many )
    {
        if( this->_random[i] == number )
            return true;
        ++i;
    }
    return false;
}

template <int size>
int random_with_no_repeats<size>::randomize()//funkcja losujaca liczby i korzysta z funckji po wyzej zeby sie nie powtarzaly
{
    int number;
    srand( time( 0 ) );
    while( this->_how_many < size )
    {
        number=(rand() % message_length);
        if( is_randomized(number) == false )
        {
            this->_random[ this->_how_many ] = number;
            this->_how_many++;
        }
    }
    return *this->_random;
}

template <int size>
int random_with_no_repeats<size>::operator[](int number)
{
    return this->_random[number];
}

#endif