#include <iostream>
#include "Headers/animal.hpp"
#include "Headers/bird.hpp"
#include "Headers/mammal.hpp"
#include "Headers/reptile.hpp"

using namespace std;

int main(){

    // Mammal g("om", 2, Skin::Feather, 2, 18);
    // g.make_sound();
    // Bird().make_sound();

    // Bird().greed();
    // g.greed();


    Reptile r("sarpe", 0, Skin::Scales, true);
     cout << r;
     cin >> r;
     cout << r;
     r.greed();
     r.make_sound();

    return 0;
}