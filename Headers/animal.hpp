#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include "skin.hpp"

using namespace std;
using std::runtime_error;

#ifndef ANIMAL_FILE_INCLUDED
#define ANIMAL_FILE_INCLUDED


class FileNotFound : public exception{
    public:
        virtual const char* what() const throw(){
            return "File not found";
        }
};


class Animal{

    protected:
        string name;
        int no_of_feet;
        Skin type_of_skin;

    public:

        // getters
        string get_name() const{ return this->name; }
        int get_no_of_feet() const{ return this->no_of_feet; }
        Skin get_type_of_skin() const{ return this->type_of_skin; }

        // setters
        void set_name(string name) { this->name = name; }
        void set_no_of_feet(int no_of_feet) { this->no_of_feet = no_of_feet; }
        void set_type_of_skin(Skin type_of_skin) {this->type_of_skin = type_of_skin; }

        // constructors
        Animal();
        Animal(string name, int no_of_feet, Skin type_of_skin);
        Animal(const Animal& copy);

        // operators
        Animal& operator=(const Animal& copy);

        // friend
        friend istream& operator>>(istream& in, Animal& copy);
        friend ostream& operator<<(ostream& out, const Animal& copy);

        // virtual
        virtual void make_sound() = 0;
        virtual void multiply(vector<Animal*> animals) = 0;

        // method
        const void greed() const;
        void write_to_file(string filename);

};

#endif