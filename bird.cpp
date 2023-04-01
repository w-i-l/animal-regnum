#include <iostream>
#include <cstring>
#include "Headers/bird.hpp"

using namespace  std;

Bird::Bird() : Animal(){
    this->no_of_eggs = 0 ;
    this->wing_color = Color::None;
}


Bird::Bird(string name, int no_of_feet, Skin type_of_skin, Color wing_color, int no_of_eggs) : Animal(name, no_of_feet, type_of_skin){
    this->wing_color = wing_color;
    this->no_of_eggs = no_of_eggs;
}


Bird::Bird(const Bird& copy) : Animal(copy){
    this->no_of_eggs = copy.no_of_eggs;
    this->wing_color = copy.wing_color;
}


Bird& Bird::operator=(const Bird& copy){
    if(this != &copy){
        Animal::operator=(copy);
        this->no_of_eggs = copy.no_of_eggs;
        this->wing_color = copy.wing_color;
    }
    
    return *this;
}


istream& operator>>(istream& in, Bird& copy){
    
    in >> (Animal&)copy;
    cout << "Bird Read: " << endl;

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

    return in;
}


ostream& operator<<(ostream& out, const Bird& copy){

    out << (Animal&)copy;
    out << "Bird Info" << endl;

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

    out << endl;

    return out;
}