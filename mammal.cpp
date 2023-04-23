#include <iostream>
#include <cstring> 
#include "Headers/animal.hpp"
#include "Headers/skin.hpp"
#include "Headers/mammal.hpp"

Mammal::Mammal() : Animal(){
    this->no_of_mammal_glands = 0;
    this->reproductive_maturity_year = 0;
}


Mammal::Mammal(string name, int no_of_feet, Skin type_of_skin,int no_of_mammal_glands, int reproductive_maturity_year) : Animal(name, no_of_feet, type_of_skin){
    this->no_of_mammal_glands = no_of_mammal_glands;
    this->reproductive_maturity_year = reproductive_maturity_year;
}


Mammal::Mammal(const Mammal& copy) : Animal(copy){
    this->no_of_mammal_glands = copy.no_of_mammal_glands;
    this->reproductive_maturity_year = copy.reproductive_maturity_year;
}


Mammal& Mammal::operator=(const Mammal& copy){
    if(this != &copy){
        Animal::operator=(copy);
        this->no_of_mammal_glands = copy.no_of_mammal_glands;
        this->reproductive_maturity_year = copy.reproductive_maturity_year;
    }

    return *this;
}  


istream& operator>>(istream& in, Mammal& copy){
    in >> (Animal&)copy;
    cout << "Mammal Read: " << endl;
    cout << "Number of mammal glands: ";
    in >> copy.no_of_mammal_glands;
    cout << "Reproductive maturity year: ";
    in >> copy.reproductive_maturity_year;

    return in;
}


ostream& operator<<(ostream& out, Mammal& copy){
    out << (Animal&)copy;
    out << "Mammal Info: " << endl;
    cout << "Number of mammal glands: " << copy.no_of_mammal_glands << endl;
    cout << "Reproductive maturity year: " << copy.reproductive_maturity_year << endl;

    return out;
}


void Mammal::make_sound(){
    cout << "GRHHHHH" << endl;
}