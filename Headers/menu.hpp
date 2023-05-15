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

        // methods
        void read_from_file(string filename);
        void write_to_file(string filename);

    public:
        Menu* get_instance();
};

#endif