#include <iostream>
#include "Headers/animal.hpp"
#include "Headers/bird.hpp"
#include "Headers/mammal.hpp"
#include "Headers/reptile.hpp"
#include "Headers/archaeopteryx.hpp"

using namespace std;

int main(){

    // Mammal g("om", 2, Skin::Feather, 2, 18);
    // g.make_sound();
    // Bird().make_sound();

    // Bird().greed();
    // g.greed();

    Bird pasare("uliu", 2, Skin::Feather, Color::Purple, 4);
    Reptile reptila("sarpe", 0, Skin::Scales, true);
    //  cout << r;
    //  cin >> r;
    //  cout << r;
    //  r.greed();
    //  r.make_sound();

    Archaeopteryx a("uliu", 2, Skin::Feather, Color::Purple, 4, true);
    cout << a;
    // a.make_sound();
    // a.greed();

    Archaeopteryx b;
    b = a;
    cout << b;

    return 0;
}