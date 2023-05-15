#include <iostream>
#include <cstring>
#include <fstream>
#include "Headers\skin.hpp"
#include "Headers\animal.hpp"

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
    read:cout << "Skin type (fur/leather/feathers/scales): ";
    char aux[30];
    in >> aux;

    if (strcmp(aux, "fur") == 0)
        copy.type_of_skin = Skin::Fur;
    else if (strcmp(aux, "leather") == 0)
        copy.type_of_skin = Skin::Leather;
    else if (strcmp(aux, "scales") == 0)
        copy.type_of_skin = Skin::Scales;
    else if (strcmp(aux, "feathers") == 0)
        copy.type_of_skin = Skin::Feathers;
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
    else if(copy.type_of_skin == Skin::Feathers){
        out << "feathers";
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


// we write the Animal info separrated by spaces
// on the same line, and we end the file with " "
void Animal::write_to_file(string filename){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // we write the name, number of feet and type of skin
    // on the same line separrated by spaces

    file << this->name << " " << this->no_of_feet << " ";

    if(this->type_of_skin == Skin::Fur){
        file << "fur";
    }
    else if(this->type_of_skin == Skin::Leather){
        file << "leather";
    }
    else if(this->type_of_skin == Skin::Scales){
        file << "scales";
    }
    else if(this->type_of_skin == Skin::Feathers){
        file << "feathers";
    }
    else{
        file << "none";
    }

    file << " ";
}


void Animal::read_from_line(string line){
    // we read the name, number of feet and type of skin
    // from the same line separrated by spaces

    char aux[30];
    strcpy(aux, line.c_str());
    char* token = strtok(aux, " ");
    this->name = token;
    token = strtok(NULL, " ");
    this->no_of_feet = atoi(token);
    token = strtok(NULL, " ");

    if (strcmp(token, "fur") == 0)
        this->type_of_skin = Skin::Fur;
    else if (strcmp(token, "leather") == 0)
        this->type_of_skin = Skin::Leather;
    else if (strcmp(token, "scales") == 0)
        this->type_of_skin = Skin::Scales;
    else if (strcmp(token, "feathers") == 0)
        this->type_of_skin = Skin::Feathers;
    else
        this->type_of_skin = Skin::None;
}