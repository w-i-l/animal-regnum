#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

#include "../../Headers/animal.hpp"
#include "../../Headers/bird.hpp"
#include "../../Headers/custom_exception.hpp"


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


Bird Bird::operator + (Bird copy){

    copy.name = this->name + "-"+ copy.name;
    copy.no_of_feet = max(this->no_of_feet, copy.no_of_feet);
    copy.no_of_eggs = this->no_of_eggs + copy.no_of_eggs;

    return copy;

}


istream& operator>>(istream& in, Bird& copy){
    
    in >> (Animal&)copy;
    cout << "Bird Read: " << endl;

    try{
    
        cout << "Number of eggs: ";
        in >> copy.no_of_eggs;
    
        if(copy.no_of_eggs < 0){
            throw InvalidOption();
        }
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


void Bird::make_sound(){
    cout << "CIP CIP RIP" << endl;
}


void Bird::multiply(vector<Animal*> animals){

    Bird* bird = new Bird;

    for(int i = 0; i < rand() % this->no_of_eggs; i++){

        *bird = Bird(this->name + "-" + to_string(i), this->no_of_feet, this->type_of_skin, Color::White, rand() % 10);
        animals.push_back((Animal*) bird);
        bird = new Bird;
    }
}


void Bird::write_to_file(string filename){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // Animal info
    Animal::write_to_file(filename);

    // we write the bird traits separated by a space
    // wing color, number of eggs

    if(this->wing_color == Color::Blue)
        file << "blue" << " ";
    else if(this->wing_color == Color::Red)
        file << "red" << " ";
    else if(this->wing_color == Color::White)
        file << "white" << " ";
    else if(this->wing_color == Color::Green)
        file << "green" << " ";
    else if(this->wing_color == Color::Purple)
        file << "purple" << " ";
    else
        file << "none" << " ";

    file << no_of_eggs << " ";


}


void Bird::read_from_line(string line){
    
        // we read the animal info
        Animal::read_from_line(line);
    
        // we read the bird traits separated by a space
        // wing color, number of eggs
    
        char aux[30];
        strcpy(aux, line.c_str());
        // get the name
        char* token = strtok(aux, " ");
        // no of feet
        token = strtok(NULL, " ");
        // type of skin
        token = strtok(NULL, " ");

    
        token = strtok(NULL, " ");
        if(strcmp(token, "red") == 0)
            this->wing_color = Color::Red;
        else if(strcmp(token, "blue") == 0)
            this->wing_color = Color::Blue;
        else if(strcmp(token, "green") == 0)
            this->wing_color = Color::Green;
        else if(strcmp(token, "purple") == 0)
            this->wing_color = Color::Purple;
        else if(strcmp(token, "white") == 0)
            this->wing_color = Color::White;
        else
            this->wing_color = Color::None;
    
        token = strtok(NULL, " ");
        this->no_of_eggs = atoi(token);
}