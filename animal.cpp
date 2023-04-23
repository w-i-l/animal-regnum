#include <iostream>
#include <cstring>
#include "Headers/skin.hpp"
#include "Headers/animal.hpp"

using namespace std;

Animal::Animal(){
    this->name = "none";
    this->no_of_feet = 0;
    this->type_of_skin = Skin::None;
}


Animal::Animal(string name, int no_of_feet, Skin type_of_skin){
    this->name = name;
    this->no_of_feet = no_of_feet;
    this->type_of_skin = type_of_skin;
}


Animal::Animal(const Animal& copy){
    this->name = copy.name;
    this->no_of_feet = copy.no_of_feet;
    this->type_of_skin = copy.type_of_skin;
}


Animal& Animal::operator=(const Animal& copy){
    if(this != &copy){
        this->name = copy.name;
        this->no_of_feet = copy.no_of_feet;
        this->type_of_skin = copy.type_of_skin;
    }
    
    return *this;
}


istream& operator>>(istream& in, Animal& copy){
    cout << "Animal Read: " << endl;
    cout << "Name: ";
    in >> copy.name;
    cout << "Number of feet: ";
    in >> copy.no_of_feet;
    read:cout << "Skin type (fur/leather/feather/scales): ";
    char aux[30];
    in >> aux;

    if (strcmp(aux, "fur") == 0)
        copy.type_of_skin = Skin::Fur;
    else if (strcmp(aux, "leather") == 0)
        copy.type_of_skin = Skin::Leather;
    else if (strcmp(aux, "scales") == 0)
        copy.type_of_skin = Skin::Scales;
    else if (strcmp(aux, "feather") == 0)
        copy.type_of_skin = Skin::Feather;
    else
        goto read;

    return in;
}   


ostream& operator<<(ostream& out, const Animal& copy){

    out << "Animal Info:" << endl;
    out << "Name: " << copy.name << endl;
    out << "Number of feet: " << copy.no_of_feet << endl;
    out << "Type of skin: ";
    
    if(copy.type_of_skin == Skin::Fur){
        out << "fur";
    }
    else if(copy.type_of_skin == Skin::Leather){
        out << "leather";
    }
    else if(copy.type_of_skin == Skin::Scales){
        out << "scales";
    }
    else if(copy.type_of_skin == Skin::Feather){
        out << "feather";
    }
    else{
        out << "none";
    }
    out << endl;

    return out;
}


const void Animal::greed() const{
    cout << "I'm alive!" << endl;
}
