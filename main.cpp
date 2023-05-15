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

    ofstream file("animals.txt", ios::app);

    Bird b1("Bird1", 2, Skin::Feathers, Color::Red, 2);
    b1.write_to_file("animals.txt");
    file << endl;

    Reptile r1("Reptile1", 4, Skin::Scales, true);
    r1.write_to_file("animals.txt");
    file << endl;


    Mammal m1("Mammal1", 4, Skin::Fur, 2, 10);
    m1.write_to_file("animals.txt");
    file << endl;

    Archaeopteryx a1("Archaeopteryx1", 2, Skin::Feathers, Color::Red, 2, true);
    a1.write_to_file("animals.txt");
    file << endl;

    return 0;
}