#include <iostream>
#include <vector>
#include <cstring>
#include <list>
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
        int select_species(string text_to_display);
        template<typename T>
        int select_animal_from_species(T species);
        string select_species_from(list<string> species);
        string get_type_of_animal(string name);
        string get_name_of_class_from_typid_name(string name);


    public:

        static Menu* get_instance();
        

        // methods
        void read_from_file(string filename, bool append_to_vector);
        void write_to_file(string filename, bool append);

        void display_animals_names();
        void delete_animals();
        void add_animal();
        void remove_animal();

        void breed_animals();

};

#endif