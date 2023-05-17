#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "../../Headers/animal.hpp"
#include "../../Headers/bird.hpp"
#include "../../Headers/reptile.hpp"
#include "../../Headers/archaeopteryx.hpp"
#include "../../Headers/custom_exception.hpp"



Archaeopteryx::Archaeopteryx() : Animal(), Bird(), Reptile() {

}


Archaeopteryx::Archaeopteryx(string name, int no_of_feet, Skin type_of_skin, 
            Color wing_color, int no_of_eggs, bool is_venomous) 
            : Animal(name, no_of_feet, type_of_skin), Bird(name, no_of_feet, type_of_skin, wing_color, no_of_eggs),
              Reptile(name, no_of_feet, type_of_skin, is_venomous) {

}


Archaeopteryx::Archaeopteryx(const Archaeopteryx& copy) : Animal(copy), Bird(copy), Reptile(copy){

}


Archaeopteryx::Archaeopteryx(const Bird& copy) : Animal(copy), Bird(copy){

    this->is_venomous = false;

}


Archaeopteryx& Archaeopteryx::operator=(const Archaeopteryx& copy){
    
    if(this != &copy){
        Bird::operator=(copy);
        Reptile::operator=(copy);
    }

    return *this;
}


Archaeopteryx Archaeopteryx::operator + (Archaeopteryx copy){

    copy.name = copy.name + "-" + this->name;
    copy.no_of_eggs = this->no_of_eggs + copy.no_of_eggs;
    copy.is_venomous = this->is_venomous || copy.is_venomous;

    return copy;
}


istream& operator >> (istream& in, Archaeopteryx& copy){

    in >> (Animal&)copy;

    // Bird

    try{
        cout << "Number of eggs: ";
        in >> copy.no_of_eggs;

        if(copy.no_of_eggs < 0)
            throw InvalidOption();
    }
    catch(InvalidOption& e){

        while(copy.no_of_eggs < 0){
            cout << endl << e.what() << endl;

            cout << "Please provide a number of eggs greater than 0!" << endl;
            cout << "Number of eggs: ";
            in >> copy.no_of_eggs;
        }
    }


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

    char venom;

    try{
        cout << "Is venomous(1/0): ";
        in >> venom;

        if(venom != '0' && venom != '1')
            throw InvalidOption();
        
        copy.is_venomous = venom - '0';
    }
    catch(InvalidOption& e){

        while(venom != '0' && venom != '1'){
            cout << endl << e.what() << endl;

            cout << "Please provide a valid option!" << endl;
            cout << "Is venomous(1/0): ";
            in >> venom;
        }

        copy.is_venomous = venom - '0';
    }

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


void Archaeopteryx::multiply(vector<Animal*> animals){

    Archaeopteryx* archaeopteryx = new Archaeopteryx;

    for(int i = 0; i < rand() % this->no_of_eggs; i++){

        *archaeopteryx = Archaeopteryx(this->name + "-" + to_string(i), this->no_of_feet, this->type_of_skin, Color::Red, rand() % this->no_of_eggs, this->is_venomous);
        animals.push_back((Animal*) archaeopteryx);
        archaeopteryx = new Archaeopteryx;
    }
}


void Archaeopteryx::write_to_file(string filename){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // Bird info
    Bird::write_to_file(filename);

    // Reptile info
    file << this->is_venomous << " ";

}


void Archaeopteryx::read_from_line(string line){

     // we read the bird info
    Bird::read_from_line(line);


    // we read the reptile info

    char aux[30];
    strcpy(aux, line.c_str());

    // get the name
    char* token = strtok(aux, " ");
    // no of feet
    token = strtok(NULL, " ");
    // type of skin
    token = strtok(NULL, " ");
    // wing color
    token = strtok(NULL, " ");
    // no of eggs
    token = strtok(NULL, " ");

    // is venomous
    token = strtok(NULL, " ");
    this->is_venomous = atoi(token) == 1 ? "true" : "false";

}


template<>
Archaeopteryx Bird::operator+(const Reptile& copy){
    
        Archaeopteryx archaeopteryx;
    
        archaeopteryx.name = this->name + "-" + copy.get_name();
        archaeopteryx.no_of_feet = this->no_of_feet + copy.get_no_of_feet();
        archaeopteryx.type_of_skin = this->type_of_skin;
        archaeopteryx.wing_color = this->wing_color;
        archaeopteryx.no_of_eggs = this->no_of_eggs;
        archaeopteryx.set_is_venomous(copy.get_is_venomous());

    
        return archaeopteryx;
}


template<>
Archaeopteryx Reptile::operator+(const Bird& copy){
    
        Archaeopteryx archaeopteryx;
    
        archaeopteryx.name = this->name + "-" + copy.get_name();
        archaeopteryx.no_of_feet = this->no_of_feet + copy.get_no_of_feet();
        archaeopteryx.type_of_skin = this->type_of_skin;
        archaeopteryx.set_wing_color(copy.get_wing_color());
        archaeopteryx.set_no_of_eggs(copy.get_no_of_eggs());
        archaeopteryx.set_is_venomous(this->is_venomous);

    
        return archaeopteryx;
}