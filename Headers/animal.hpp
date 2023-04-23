#ifndef ANIMAL_FILE_INCLUDED
#define ANIMAL_FILE_INCLUDED

#include "skin.hpp"
#include <string>

using namespace std;

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

        // method
        const void greed() const;

};

#endif