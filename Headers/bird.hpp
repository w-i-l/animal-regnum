#include <string>
#include "animal.hpp"
#include "skin.hpp"
using namespace std;
    


#ifndef BIRD_FILE_INCLUDED
#define BIRD_FILE_INCLUDED

class Bird : public Animal{

    private: 
        Color wing_color;
        int no_of_eggs;
    
    public:

        // constructors
        Bird();
        Bird(string name, int no_of_feet, Skin type_of_skin, Color wing_color, int no_of_egs);
        Bird(const Bird& copy);

        // operators
        Bird& operator=(const Bird& copy);

        // friend
        friend istream& operator>>(istream& in, Bird& copy);
        friend ostream& operator<<(ostream& out, const Bird& copy);

};

#endif