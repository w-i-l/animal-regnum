#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "../../Headers/animal.hpp"
#include "../../Headers/bird.hpp"
#include "../../Headers/reptile.hpp"
#include "../../Headers/mammal.hpp"
#include "../../Headers/archaeopteryx.hpp"
#include "../../Headers/custom_exception.hpp"
#include "../../Headers/corral.hpp"

using namespace std;

template <class T_animal>
Corral<T_animal>::Corral(){
    this->name = "no_name";
    this->animals = {};
}


template <class T_animal>
Corral<T_animal>::Corral(string corral_name, vector<T_animal*> animals){
    this->name = corral_name;
    this->animals = animals;
}


template <class T_animal>
Corral<T_animal>::Corral(const Corral& copy){
    this->name = copy.name;
    this->animals = copy.animals;
}


template <class T_animal>
Corral<T_animal>& Corral<T_animal>::operator=(const Corral& copy){
    if(this != &copy){
        this->name = copy.name;
        this->animals = copy.animals;
    }

    return *this;
}


template <class T_animal>
Corral<T_animal> Corral<T_animal>::operator + (Corral copy){
    copy.name = copy.name + "-" + this->name;
    copy.animals.insert(copy.animals.end(), this->animals.begin(), this->animals.end());

    return copy;
}


template <class T_animal>
T_animal* Corral<T_animal>::operator[](int index) const{
    return this->animals[index];
}


template <class T_animal>
Corral<T_animal>& Corral<T_animal>::operator+=(T_animal* animal){
    this->animals.push_back(animal);

    return *this;
}


template <class T_animal>
void Corral<T_animal>::add_animal(T_animal* animal){
    this->animals.push_back(animal);
}


template <class T_animal>
void Corral<T_animal>::remove_animal(T_animal* animal){
    for(int i = 0; i < this->animals.size(); i++){
        if(this->animals[i] == animal){
            this->animals.erase(this->animals.begin() + i);
            break;
        }
    }
}


template <class T_animal>
size_t Corral<T_animal>::size() const{
    return this->animals.size();
}


template <class T_animal>
void operator+=(Corral<T_animal>& corral, T_animal* animal){
    corral.animals.push_back(animal);
}   


template <class T_animal>
ostream& operator<<(ostream& out, const Corral<T_animal>& corral){
    out << "Corral name: " << corral.name << endl;
    out << "Animals: " << endl;

    for(int i = 0; i < corral.animals.size(); i++){
        out << *corral.animals[i] << endl;
    }

    return out;
}


template <class T_animal>
istream& operator>>(istream& in, Corral<T_animal>& corral){
    cout << "Enter corral name: ";
    in >> corral.name;

    cout << "Enter animals: " << endl;
    cout << "Enter number of animals: ";
    int number_of_animals;
    in >> number_of_animals;

    for(int i = 0; i < number_of_animals; i++){
        T_animal* animal = new T_animal();
        in >> *animal;
        corral.animals.push_back(animal);
    }

    return in;
}


template <>
Corral<Mammal>::Corral(){
    this->corral_name = "no_name";
    this->animals = {};
}


template <>
Corral<Mammal>::Corral(string corral_name, vector<Mammal*> animals){
    this->corral_name = corral_name;
    this->animals = animals;
}


template <>
Corral<Mammal>::Corral(const Corral& copy){
    this->corral_name = copy.corral_name;
    this->animals = copy.animals;
}


template <>
Corral<Mammal>& Corral<Mammal>::operator=(const Corral& copy){
    if(this != &copy){
        this->corral_name = copy.corral_name;
        this->animals = copy.animals;
    }

    return *this;
}


template <>
ostream& operator<<(ostream& out, const Corral<Mammal>& corral){

    out << "Corral name: " << corral.corral_name << endl;
    out << "Animals: " << endl;

    for(int i = 0; i < corral.animals.size(); i++){
        out << *corral.animals[i] << endl;
    }

    return out;
}


template <>
istream& operator>>(istream& in, Corral<Mammal>& corral){
    cout << "Enter corral name: ";
    in >> corral.corral_name;

    cout << "Enter animals: " << endl;
    cout << "Enter number of animals: ";
    int number_of_animals;
    in >> number_of_animals;

    for(int i = 0; i < number_of_animals; i++){
        Mammal* animal = new Mammal();
        in >> *animal;
        corral.animals.push_back(animal);
    }

    return in;
}


template <>
void Corral<Mammal>::add_animal(Mammal* animal){
    animals.push_back(animal);
}


template <>
void Corral<Mammal>::remove_animal(Mammal* animal){
    for(int i = 0; i < animals.size(); i++){
        if(animals[i] == animal){
            animals.erase(animals.begin() + i);
            break;
        }
    }
}