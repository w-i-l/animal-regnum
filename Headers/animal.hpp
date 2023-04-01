#include "skin.hpp"
#include <string>

using namespace std;

#ifndef ANIMAL_FILE_INCLUDED
#define ANIMAL_FILE_INCLUDED


class Animal{

    protected:
        string name;
        int no_of_feet;
        Skin type_of_skin;

    public:

        // constructors
        Animal();
        Animal(string name, int no_of_feet, Skin type_of_skin);
        Animal(const Animal& copy);

        // operators
        Animal& operator=(const Animal& copy);

        // friend
        friend istream& operator>>(istream& in, Animal& copy);
        friend ostream& operator<<(ostream& out, const Animal& copy);

};

#endif