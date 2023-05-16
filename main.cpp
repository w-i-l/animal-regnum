#include <iostream>
#include <fstream>
#include "Headers\animal.hpp"
#include "Headers\bird.hpp"
#include "Headers\mammal.hpp"
#include "Headers\reptile.hpp"
#include "Headers\archaeopteryx.hpp"
#include "Headers\menu.hpp"

using namespace std;

int main(){

    Menu* menu = Menu::get_instance();
    // menu->delete_animals();
    // menu->display_animals_names();
    // menu->write_to_file("animals.txt", 1);
    // menu->read_from_file("animals.txt", 1);
    // cout << endl;
    // menu->add_animal();

    // cout << endl;

    // menu->display_animals_names();
    // menu->remove_animal();
    
    // menu->display_animals_names();


    // Bird bird = Bird("bird", 2, Skin::Feathers, Color::Red, 2);
    // Reptile reptile = Reptile("reptile", 4, Skin::Scales, 2);

    // cout << bird.operator+<Archaeopteryx, Reptile>(reptile) << endl;

    // cout << reptile.operator+<Archaeopteryx, Bird>(bird) << endl;

    menu->breed_animals();
    menu->display_animals_names();

    return 0;
}