#include <iostream>
#include "Headers/animal.hpp"
#include "Headers/bird.hpp"
#include "Headers/mammal.hpp"


using namespace std;

int main(){

    Mammal g("om", 2, Skin::Feather, 2, 18);
    g.make_sound();
    Bird().make_sound();


    return 0;
}