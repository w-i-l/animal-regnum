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
    menu->delete_animals();
    menu->display_animals_names();
    // menu->write_to_file("animals.txt", 1);
    menu->read_from_file("animals.txt", 1);
    menu->display_animals_names();

    return 0;
}