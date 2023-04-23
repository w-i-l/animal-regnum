#include <string>
#include "animal.hpp"
#include "skin.hpp"
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

        // constructors
        Bird();
        Bird(string name, int no_of_feet, Skin type_of_skin, Color wing_color, int no_of_egs);
        Bird(const Bird& copy);

        // operators
        Bird& operator=(const Bird& copy);

        // friend
        friend istream& operator>>(istream& in, Bird& copy);
        friend ostream& operator<<(ostream& out, const Bird& copy);

        // virtual
        void make_sound();
};

#endif