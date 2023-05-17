#include <iostream>
#include <fstream>
#include <map>
#include <set>

#include "Headers\animal.hpp"
#include "Headers\bird.hpp"
#include "Headers\mammal.hpp"
#include "Headers\reptile.hpp"
#include "Headers\archaeopteryx.hpp"
#include "Headers\menu.hpp"

using namespace std;


int main() {

    Menu* menu = Menu::get_instance();
    menu->run();

    return 0;
}