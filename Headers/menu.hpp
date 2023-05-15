#include <iostream>
#include <vector>
#include <cstring>
#include <typeinfo>
#include "animal.hpp"
#include "reptile.hpp"
#include "bird.hpp"
#include "mammal.hpp"
#include "archaeopteryx.hpp"

#ifndef MENU_FILE_INCLUDED
#define MENU_FILE_INCLUDED

class Menu{
    private:

        static Menu* instance;
        vector<Animal*> animals;

        // constructor
        Menu();
        Menu(const Menu&);
        Menu& operator=(const Menu&);


    public:

        static Menu* get_instance();
        

        // methods
        void read_from_file(string filename, bool append_to_vector);
        void write_to_file(string filename, bool append);

        void display_animals_names();
        void delete_animals();

};

#endif