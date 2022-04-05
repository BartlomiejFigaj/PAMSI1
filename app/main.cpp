#include <iostream>
#include <cstdlib>
#include <fstream>

#include "packing.hh"
#include "unpacking.hh"

#define MESSEGE_SIZE 160 //ograniczenie ilosci znakow dla wiadomosci jak przy systemie SMS


int main()
{
    char message[MESSEGE_SIZE];
    packing<MESSEGE_SIZE> dpacking;
    unpacking<MESSEGE_SIZE> dunpacking;
    std::cout << "Welcome to program enter a massage:\n";

    //wersja z wpisywaniem
    //std::cin.getline(message,MESSEGE_SIZE);
    //wersja z wpisaniem

    //wersja driverowa
    std::fstream file;
    file.open("examples.txt", std::ios::in);
    if(file.good()==true)
    {
        file.getline(message,MESSEGE_SIZE);
        file.close();
        std::cout << message << std::endl;
    }
    else
    {
        file.close();
        std::cout << "Nie udalo sie otworzyc pliku :(\n";
        return -1;
    }
    //wersja driverowa

    std::cout << "~Encoding~\n";
    dpacking.pack_them_all(message);
    std::cout << "~Sending~\n";
    std::cout << "~Decoding~\n";
    dunpacking.unpack_them_all(dpacking.get());
    std::cout << "Decoded message is\n";
    std:: cout << dunpacking.decoded_message() << std::endl;
    return 0;
}