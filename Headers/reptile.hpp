#include <string>
#include "animal.hpp"
#include "skin.hpp"
using namespace std;


class Reptile: public Animal{

    private:
        bool is_venomous;

    public:
        
        // getters
        bool get_is_venomous() const{ return this->is_venomous; }

        // constructors
        Reptile();
        Reptile(string name, int no_of_feet, Skin type_of_skin, bool is_venomous);
        Reptile(const Reptile& copy);


        // operators
        Reptile& operator=(const Reptile& copy);

        // friends
        friend istream& operator >> (istream& in, Reptile& copy);
        friend ostream& operator << (ostream& out, const Reptile& copy);

        void make_sound();
};