#ifndef RANDOM_HH
#define RANDOM_HH

#include <iostream>
#include <cstdlib>
#include <ctime>

#define message_length 160
/*
bool czyBylaWylosowana( int iLiczba, int tab[], int ile )
{
    if( ile <= 0 )
         return false;
   
    int i = 0;
    do
    {
        if( tab[ i ] == iLiczba )
             return true;
       
        i++;
    } while( i < ile );
   
    return false;
}

int wylosuj()
{
    return( rand() % 10 ) + 1;
}

int main()
{
    srand( time( 0 ) );
    int wylosowane[ 5 ];
    int wylosowanych = 0;
    do
    {
        int liczba = wylosuj();
        if( czyBylaWylosowana( liczba, wylosowane, wylosowanych ) == false )
        {
            wylosowane[ wylosowanych ] = liczba;
            wylosowanych++;
        } //if
    } while( wylosowanych < 5 );
   
    wylosowanych = 0;
    do
    {
        std::cout << wylosowane[ wylosowanych ] << std::endl;
        wylosowanych++;
    } while( wylosowanych < 5 );
   
    return 0;
}*/
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
bool random_with_no_repeats<size>::is_randomized(int number)
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
int random_with_no_repeats<size>::randomize()
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