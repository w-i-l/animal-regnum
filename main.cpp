#include <iostream>
#include "Headers/animal.hpp"
#include "Headers/bird.hpp"
#include "Headers/mammal.hpp"


using namespace std;

int main(){

    Mammal g("om", 2, Skin::Feather, 2, 18);
    Mammal h(g);
    Mammal s = g;
    cout << g << endl;
    cout << h << endl;
    cout << s << endl;


    return 0;
}