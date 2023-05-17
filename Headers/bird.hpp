#include <vector>
#include <iostream>

#include "animal.hpp"
#include "skin.hpp"
#include "reptile.hpp"
#include "custom_exception.hpp"

using namespace std;

#ifndef BIRD_FILE_INCLUDED
#define BIRD_FILE_INCLUDED

class Bird : virtual public Animal{

    protected: 
        Color wing_color;
        int no_of_eggs;
    
    public:

        // getters
        Color get_wing_color() const{ return this->wing_color; }
        int get_no_of_eggs() const{ return this->no_of_eggs; }
        
        // setters
        void set_wing_color(Color wing_color) { this->wing_color = wing_color; }
        void set_no_of_eggs(int no_of_eggs) { this->no_of_eggs = no_of_eggs; }

        // constructors
        Bird();
        Bird(string name, int no_of_feet, Skin type_of_skin, Color wing_color, int no_of_egs);
        Bird(const Bird& copy);

        // operators
        Bird& operator = (const Bird& copy);
        Bird operator + (Bird copy);
        template<typename Return, typename T>
        Return operator+(const T& copy);

        // friend
        friend istream& operator>>(istream& in, Bird& copy);
        friend ostream& operator<<(ostream& out, const Bird& copy);

        // virtual
        void make_sound();
        void multiply(vector<Animal*> animals);
        void write_to_file(string filename) throw(FileNotFound);
        void read_from_line(string line);


};

#endif