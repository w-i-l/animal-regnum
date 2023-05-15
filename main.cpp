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

    // ofstream file("animals.txt", ios::app);

    // Bird b1("Bird1", 2, Skin::Feathers, Color::Red, 2);
    // b1.write_to_file("animals.txt");
    // file << endl;

    // Reptile r1("Reptile1", 4, Skin::Scales, true);
    // r1.write_to_file("animals.txt");
    // file << endl;


    // Mammal m1("Mammal1", 4, Skin::Fur, 2, 10);
    // m1.write_to_file("animals.txt");
    // file << endl;

    // Archaeopteryx a1("Archaeopteryx1", 2, Skin::Feathers, Color::Red, 2, true);
    // a1.write_to_file("animals.txt");
    // file << endl;


    ifstream file("animals.txt"); 
    string line;

    Bird b1;
    Reptile r1;
    Mammal m1;
    Archaeopteryx a1;


    while(getline(file, line)){
        if(line.find("Bird") != string::npos)
            b1.read_from_line(line);
        else if(line.find("Reptile") != string::npos)
            r1.read_from_line(line);
        else if(line.find("Mammal") != string::npos)
            m1.read_from_line(line);
        else if(line.find("Archaeopteryx") != string::npos)
            a1.read_from_line(line);
    }

    cout << b1 << endl;
    cout << r1 << endl;
    cout << m1 << endl;
    cout << a1 << endl;
    

    return 0;
}