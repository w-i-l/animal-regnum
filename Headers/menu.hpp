#include <iostream>
#include <vector>
#include <cstring>
#include <list>
#include <typeinfo>
#include <exception>

#include "animal.hpp"
#include "reptile.hpp"
#include "bird.hpp"
#include "mammal.hpp"
#include "archaeopteryx.hpp"

#ifndef MENU_FILE_INCLUDED
#define MENU_FILE_INCLUDED

class Menu{
    private:

        // admin
        string admin_username;
        string admin_password;

        static Menu* instance;
        vector<Animal*> animals;

        // constructor
        Menu();
        Menu(const Menu&);
        Menu& operator=(const Menu&);

        // aux methods
        int select_species(string text_to_display);
        template<typename T>
        int select_animal_from_species(T species);
        string select_species_from(list<string> species);

        string get_type_of_animal(string name);
        string get_name_of_class_from_typid_name(string name);

        // main methods
        void read_from_file(string filename, bool append_to_vector);
        void write_to_file(string filename, bool append);

        void display_animals_names();
        void display_animal_info();

        void delete_animals();
        void add_animal();
        void remove_animal();

        void breed_animals();
        
        // menu

        int get_option_for_admin();
        int get_option_for_user();

        void admin_auth();
        void admin_menu();
        void user_menu();

    public:

        static Menu* get_instance();

        void run();
        
};

#endif