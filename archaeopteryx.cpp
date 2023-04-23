#include <iostream>
#include <cstring>
#include "Headers/archaeopteryx.hpp"


Archaeopteryx::Archaeopteryx() : Animal(), Bird(), Reptile() {

}


Archaeopteryx::Archaeopteryx(string name, int no_of_feet, Skin type_of_skin, 
            Color wing_color, int no_of_eggs, bool is_venomous) 
            : Animal(name, no_of_feet, type_of_skin), Bird(name, no_of_feet, type_of_skin, wing_color, no_of_eggs),
              Reptile(name, no_of_feet, type_of_skin, is_venomous) {

}



Archaeopteryx::Archaeopteryx(const Archaeopteryx& copy) : Animal(copy), Bird(copy), Reptile(copy){

}


Archaeopteryx& Archaeopteryx::operator=(const Archaeopteryx& copy){
    
    if(this != &copy){
        Bird::operator=(copy);
        Reptile::operator=(copy);
    }

    return *this;
}


istream& operator >> (istream& in, Archaeopteryx& copy){

    in >> (Animal&)copy;

    // Bird

    cout << "Number of eggs: ";
    in >> copy.no_of_eggs;

    read:cout << "Color (red/green/blue/purple/white): ";
    char aux[30];
    in >> aux;
    if(strcmp(aux, "red") == 0)
        copy.wing_color = Color::Red;
    else if(strcmp(aux, "blue") == 0)
        copy.wing_color = Color::Blue;
    else if(strcmp(aux, "green") == 0)
        copy.wing_color = Color::Green;
    else if(strcmp(aux, "purple") == 0)
        copy.wing_color = Color::Purple;
    else if(strcmp(aux, "white") == 0)
        copy.wing_color = Color::White;
    else
        goto read;

    // Reptile

    cout << "Is venomous(1/0): ";
    in >> copy.is_venomous;

    return in;

}


ostream& operator << (ostream& out, const Archaeopteryx& copy){

    out << (Animal&)copy;

    // Bird
    
    out << "Number of eggs: " << copy.no_of_eggs << endl;

    out << "Wing color: ";
    if(copy.wing_color == Color::Blue)
        out << "blue";
    else if(copy.wing_color == Color::Red)
        out << "red";
    else if(copy.wing_color == Color::White)
        out << "white";
    else if(copy.wing_color == Color::Green)
        out << "green";
    else if(copy.wing_color == Color::Purple)
        out << "purple";
    else
        out << "none";

    // Reptile

    out << "is venomous: " << copy.is_venomous << endl;

    return out;
}


void Archaeopteryx::make_sound(){
    cout << "AHHH" << endl;
}