#include <string>
#include "animal.hpp"
#include "skin.hpp"
using namespace std;

#ifndef MAMMAL_FILE_INCLUDED
#define MAMMAL_FILE_INCLUDED

class Mammal : public Animal{

    private:
        int no_of_mammal_glands;
        int reproductive_maturity_year;

    public:

        // getters
        int get_no_of_mammal_glands() const{ return this->no_of_mammal_glands; }
        int  get_reproductive_maturity_year() const{ return this->reproductive_maturity_year; }

        // constructors
        Mammal();
        Mammal(string name, int no_of_feet, Skin type_of_skin, int no_of_mammal_glands, int reproductive_maturity_year);
        Mammal(const Mammal& copy);

        // operators
        Mammal& operator=(const Mammal& copy);

        // friend
        friend istream& operator>>(istream& in, Mammal& copy);
        friend ostream& operator<<(ostream& out, Mammal& copy);

        // virtual
        void make_sound();
}; 

#endif