#include <iostream>
#include <cstring> 
#include <vector>
#include "Headers\animal.hpp"
#include "Headers\skin.hpp"
#include "Headers\mammal.hpp"


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


Mammal Mammal::operator + (Mammal copy){

    copy.name = copy.name + "-" +this->name;
    copy.no_of_feet = max(this->no_of_feet, copy.no_of_feet);
    copy.no_of_mammal_glands = this->no_of_mammal_glands + copy.no_of_mammal_glands;
    copy.reproductive_maturity_year = min(copy.reproductive_maturity_year, this->reproductive_maturity_year);

    return copy;

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


void Mammal::multiply(vector<Animal*> animals){

    Mammal* mammal = new Mammal;

    for(int i = 0; i < rand() % this->no_of_mammal_glands; i++){

        *mammal = Mammal(this->name + "-" + to_string(i), this->no_of_feet, this->type_of_skin,rand() % 10, rand() % 30);
        animals.push_back((Animal*) mammal);
        mammal = new Mammal;
    }
}
