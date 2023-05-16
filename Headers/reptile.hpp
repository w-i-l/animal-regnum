#include <string>
#include <vector>
#include <iostream>
#include "animal.hpp"
#include "skin.hpp"
using namespace std;
#ifndef REPTILE_FILE_INCLUDED
#define REPTILE_FILE_INCLUDED

class Reptile: virtual public Animal{

    protected:
        bool is_venomous;

    public:
        
        // getters
        bool get_is_venomous() const{ return this->is_venomous; }

        // setters
        void set_is_venomous(bool is_venomous) { this->is_venomous = is_venomous; }

        // constructors
        Reptile();
        Reptile(string name, int no_of_feet, Skin type_of_skin, bool is_venomous);
        Reptile(const Reptile& copy);


        // operators
        Reptile& operator = (const Reptile& copy);
        Reptile operator + (Reptile copy);
        template<typename Return, typename T>
        Return operator+(const T& copy);

        // friends
        friend istream& operator >> (istream& in, Reptile& copy);
        friend ostream& operator << (ostream& out, const Reptile& copy);

        // virtual
        void make_sound();
        void multiply(vector<Animal*> animals);
        void write_to_file(string filename);
        void read_from_line(string line);


};

#endif