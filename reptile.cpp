#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "Headers\animal.hpp"
#include "Headers\reptile.hpp"


Reptile::Reptile() : Animal(){
    this->is_venomous = false;
}


Reptile::Reptile(string name, int no_of_feet, Skin type_of_skin, bool is_venomous) 
    : Animal(name, no_of_feet, type_of_skin){
        this->is_venomous = is_venomous;
}


Reptile::Reptile(const Reptile& copy) : Animal(copy){
    this->is_venomous = copy.is_venomous;
}


Reptile& Reptile::operator=(const Reptile& copy){

    if(this != &copy){
        Animal::operator=(copy);
        this->is_venomous = copy.is_venomous;
    }

    return *this;
}


Reptile Reptile::operator + (Reptile copy){

    copy.name = this->name + '-' + copy.name;
    copy.no_of_feet = max(this->no_of_feet, copy.no_of_feet);
    copy.is_venomous = copy.is_venomous || this->is_venomous;

    return copy;
}


istream& operator >> (istream& in, Reptile& copy){
    in >> (Animal&)copy;
    cout << "Is venomous(1/0): ";
    in >> copy.is_venomous;

    return in;
}


ostream& operator << (ostream& out, const Reptile& copy){
    out << (Animal&)copy;
    out << "is venomous: " << copy.is_venomous << endl;

    return out;
}


void Reptile::make_sound(){
    cout << "SPRHHHH" << endl;
}


void Reptile::multiply(vector<Animal*> animals){

    Reptile* reptile = new Reptile;

    for(int i = 0; i < rand() % 12; i++){

        *reptile = Reptile(this->name + "-" + to_string(i), this->no_of_feet, this->type_of_skin, this->is_venomous);
        animals.push_back((Animal*) reptile);
        reptile = new Reptile;
    }
}


void Reptile::write_to_file(string filename){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // Animal info
    Animal::write_to_file(filename);

    // we write reptile info to file separated by a space
    // is_venomous
    file << this->is_venomous << " ";
    
}


void Reptile::read_from_line(string line){
        
     // we read the animal info
    Animal::read_from_line(line);

    // we read the mammal info
    // no_of_mammal_glands, reproductive_maturity_year

    char aux[30];
    strcpy(aux, line.c_str());

    // get the name
    char* token = strtok(aux, " ");
    // no of feet
    token = strtok(NULL, " ");
    // type of skin
    token = strtok(NULL, " ");

    // is venomous
    token = strtok(NULL, " ");
    this->is_venomous = atoi(token);
    
}