#include <string>
#include <vector>
#include <iostream>
#include "animal.hpp"
#include "reptile.hpp"
#include "bird.hpp"
#include "skin.hpp"

using namespace std;


#ifndef ARCHAEOPTERYX_FILE_INCLUDED
#define ARCHAEOPTERYX_FILE_INCLUDED

class Archaeopteryx : public Bird, public Reptile{

    public:

        // constructors
        Archaeopteryx();
        Archaeopteryx(string name, int no_of_feet, Skin type_of_skin, 
            Color wing_color, int no_of_eggs, bool is_venomous);
        Archaeopteryx(const Archaeopteryx& copy);
        Archaeopteryx(const Bird& copy);

        // operators
        Archaeopteryx& operator = (const Archaeopteryx& copy);
        Archaeopteryx operator + (Archaeopteryx copy);

        // friends
        friend istream& operator >> (istream& in, Archaeopteryx& copy);
        friend ostream& operator << (ostream& out, const Archaeopteryx& copy);

        // methods
        void make_sound();
        void multiply(vector<Animal*> animals);
        void write_to_file(string filename);
};


#endif