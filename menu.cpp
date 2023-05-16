#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <map>
#include <string>
#include "Headers\animal.hpp"
#include "Headers\reptile.hpp"
#include "Headers\bird.hpp"
#include "Headers\mammal.hpp"
#include "Headers\archaeopteryx.hpp"
#include "Headers\menu.hpp"

using namespace std;


Menu* Menu::instance = NULL;


Menu::Menu(){
    Bird* bird = new Bird;
    Reptile* reptile = new Reptile;
    Mammal* mammal = new Mammal;
    Archaeopteryx* archaeopteryx = new Archaeopteryx;

    *bird = Bird("eagle",2, Skin::Feathers, Color::White, 4);
    animals.push_back((Animal*) bird);
    bird = new Bird;

    *bird = Bird("owl", 2, Skin::Feathers, Color::Blue, 2);
    animals.push_back((Animal*) bird);

    *reptile = Reptile("boa", 0, Skin::Scales, 1);
    animals.push_back((Animal*) reptile);
    reptile = new Reptile;

    *reptile = Reptile("turtle", 4, Skin::Leather, 0);
    animals.push_back((Animal*) reptile);

    *mammal = Mammal("koala", 4, Skin::Fur, 2, 10);
    animals.push_back((Animal*) mammal);
    mammal = new Mammal;

    *mammal = Mammal("deer", 4, Skin::Leather, 4, 4);
    animals.push_back((Animal*) mammal);

    *archaeopteryx = Archaeopteryx("arch-2", 2, Skin::Feathers, Color::Green, 2, 0);
    animals.push_back((Animal*) archaeopteryx);
    archaeopteryx = new Archaeopteryx;

    *archaeopteryx = Archaeopteryx("arch-1", 2, Skin::Feathers, Color::Blue, 3, 1);
    animals.push_back((Animal*) archaeopteryx);

}


Menu* Menu::get_instance(){
    if (instance == NULL){
        instance = new Menu;
    }

    return instance;
}


void Menu::write_to_file(string filename, bool append){

    ofstream file;

    if(append == true){
        file.open(filename, ios::app);
    }
    else{
        file.open(filename);
    }

    if(file.is_open() == false){
        throw FileNotFound();
    }

    for(int i = 0; i < animals.size(); i++){
        if(typeid(*(animals[i])) == typeid(Bird)){
            file << "Bird" << endl;
            Bird* bird = dynamic_cast<Bird*>(animals[i]);
            bird->write_to_file(filename);
            file << endl;
        }
        else if(typeid(*(animals[i])) == typeid(Reptile)){
            file << "Reptile" << endl;
            Reptile* reptile = dynamic_cast<Reptile*>(animals[i]);
            reptile->write_to_file(filename);
            file << endl;
        }
        else if(typeid(*(animals[i])) == typeid(Mammal)){
            file << "Mammal" << endl;
            Mammal* mammal = dynamic_cast<Mammal*>(animals[i]);
            mammal->write_to_file(filename);
            file << endl;
        }
        else if(typeid(*(animals[i])) == typeid(Archaeopteryx)){
            file << "Archaeopteryx" << endl;
            Archaeopteryx* archaeopteryx = dynamic_cast<Archaeopteryx*>(animals[i]);
            archaeopteryx->write_to_file(filename);
            file << endl;
        }

    }

    file.close();
}


void Menu::read_from_file(string filename, bool append_to_vector){

    if(append_to_vector == false){
        animals.clear();
    }

    ifstream file(filename);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    Bird* bird = new Bird;
    Reptile* reptile = new Reptile;
    Mammal* mammal = new Mammal;
    Archaeopteryx* archaeopteryx = new Archaeopteryx;

    string line;

    while(getline(file, line)){

        if(line == "Bird"){
            getline(file, line);

            bird->read_from_line(line);
            animals.push_back((Animal*) bird);
            
            // cleaning memory
            bird = new Bird;
        }
        else if(line == "Reptile"){
            getline(file, line);

            reptile->read_from_line(line);
            animals.push_back((Animal*) reptile);
            
            // cleaning memory
            reptile = new Reptile;
        }
        else if(line == "Mammal"){
            getline(file, line);

            mammal->read_from_line(line);
            animals.push_back((Animal*) mammal);
            
            // cleaning memory
            mammal = new Mammal;
        }
        else if(line == "Archaeopteryx"){
            getline(file, line);

            archaeopteryx->read_from_line(line);
            animals.push_back((Animal*) archaeopteryx);
            
            // cleaning memory
            archaeopteryx = new Archaeopteryx;
        }
    }

    file.close();
}


void Menu::display_animals_names(){
    for(int i = 0; i < animals.size(); i++){
        cout << animals[i]->get_name() << endl;
    }
}


void Menu::delete_animals(){
    animals.clear();
}


// returns 1 if bird, 2 if reptile, 3 if mammal, 4 if archaeopteryx
int Menu::select_species(string text_to_display){

    int option;

    cout << endl;
    cout << "Which species would you like to " + text_to_display + "?" << endl;
    cout << "1. Bird" << endl;
    cout << "2. Reptile" << endl;
    cout << "3. Mammal" << endl;
    cout << "4. Archaropteryx" << endl;
    
    cout << endl << "Enter an option: ";
    cin >> option;
    cout << endl;

    if(option < 0 || option >= 5){
        throw InvalidOption();
    }

    return option;

}


// returns the index of the selected animal in the animals vector
template <typename T>
int Menu::select_animal_from_species(T species){

    // we bind the displayed option to the index in the vector
    map<int, int> option_to_index;

    int index = 1;

    for(int i = 0; i < animals.size(); i++){
        if(typeid(*(animals[i])) == typeid(species)){
            cout << index << ". " << animals[i]->get_name() << endl;
            option_to_index[index] = i;
            index ++;
        }
    }

    int option;

    cout << endl << "Enter an option: ";
    cin >> option;
    cout << endl;

    if(option < 1 || option >= index){
        throw InvalidOption();
    }

    return option_to_index[option];

}


void Menu::add_animal(){

    int species = select_species("add");

    if(species == 1){
        Bird* bird = new Bird;
        cin >> *bird;
        animals.push_back((Animal*) bird);
    }
    else if(species == 2){
        Reptile* reptile = new Reptile;
        cin >> *reptile;
        animals.push_back((Animal*) reptile);
    }
    else if(species == 3){
        Mammal* mammal = new Mammal;
        cin >> *mammal;
        animals.push_back((Animal*) mammal);
    }
    else if(species == 4){
        Archaeopteryx* archaeopteryx = new Archaeopteryx;
        cin >> *archaeopteryx;
        animals.push_back((Animal*) archaeopteryx);
    }

    cout << "Added successfully!" << endl;

}


void Menu::remove_animal(){

    int species = select_species("remove");
    
    if(species == 1){
        int index = select_animal_from_species(Bird());
        animals.erase(animals.begin() + index);
    }
    else if(species == 2){
        int index = select_animal_from_species(Reptile());
        animals.erase(animals.begin() + index);
    }
    else if(species == 3){
        int index = select_animal_from_species(Mammal());
        animals.erase(animals.begin() + index);
    }
    else if(species == 4){
        int index = select_animal_from_species(Archaeopteryx());
        animals.erase(animals.begin() + index);
    }

    cout << "Removed successfully!" << endl;

}


// returns the name of the animal species selected
string Menu::select_species_from(list<string> species){

    cout << "Choose a species: " << endl;

    int index = 1;

    for(auto it = species.begin(); it != species.end(); it++){
        cout << index << ". " << *it << endl;
        index ++;
    }

    int option;

    cout << endl << "Enter an option: ";
    cin >> option;
    cout << endl;

    if(option < 1 || option >= index){
        throw InvalidOption();
    }

    index = 0;

    for(auto it = species.begin(); it != species.end(); it++){
        if(index == option){
            return *it;
        }
        index ++;
    }

}


void Menu::breed_animals(){

    int first_species = select_species("breed");

    map<int, list<string>> species_to_list_of_species;

    species_to_list_of_species[1] = {"Bird", "Reptile"};
    species_to_list_of_species[2] = {"Reptile", "Bird"};
    species_to_list_of_species[3] = {"Mammal"};
    species_to_list_of_species[4] = {"Archaeopteryx"};

    string second_species_name = select_species_from(species_to_list_of_species[first_species]);
    string first_species_name = species_to_list_of_species[first_species].front();

    int index_of_first_animal, index_of_second_animal;

    if(first_species_name == "Bird"){

        index_of_first_animal = select_animal_from_species(Bird());

        if(second_species_name == "Bird"){

            index_of_second_animal = select_animal_from_species(Bird());
            
            Bird* new_bird = new Bird, first_bird, second_bird;

            first_bird = dynamic_cast<Bird&>(*animals[index_of_first_animal]);
            second_bird = dynamic_cast<Bird&>(*animals[index_of_second_animal]);

            *new_bird = first_bird + second_bird;
            animals.push_back((Animal*) new_bird);

        }

        else if(second_species_name == "Reptile"){

            index_of_second_animal = select_animal_from_species(Reptile());
        
            Bird bird;
            Reptile reptile;
            Archaeopteryx* new_archaeopteryx = new Archaeopteryx;

            bird = dynamic_cast<Bird&>(*animals[index_of_first_animal]);
            reptile = dynamic_cast<Reptile&>(*animals[index_of_second_animal]);

            *new_archaeopteryx = bird.operator+<Archaeopteryx, Reptile>(reptile);
            animals.push_back((Animal*) new_archaeopteryx);

        }
    }

    else if(first_species_name == "Reptile"){

        index_of_first_animal = select_animal_from_species(Reptile());

        if(second_species_name == "Reptile"){
            index_of_second_animal = select_animal_from_species(Reptile());

            Reptile* new_reptile = new Reptile, first_reptile, second_reptile;

            first_reptile = dynamic_cast<Reptile&>(*animals[index_of_first_animal]);
            second_reptile = dynamic_cast<Reptile&>(*animals[index_of_second_animal]);

            *new_reptile = first_reptile + second_reptile;
            animals.push_back((Animal*) new_reptile);
        }

        else if(second_species_name == "Bird"){
            index_of_second_animal = select_animal_from_species(Bird());

            Bird bird;
            Reptile reptile;
            Archaeopteryx* new_archaeopteryx = new Archaeopteryx;

            bird = dynamic_cast<Bird&>(*animals[index_of_second_animal]);
            reptile = dynamic_cast<Reptile&>(*animals[index_of_first_animal]);

            *new_archaeopteryx = reptile.operator+<Archaeopteryx, Bird>(bird);
            animals.push_back((Animal*) new_archaeopteryx);
        }
    }

    else if(first_species_name == "Mammal"){

        index_of_first_animal = select_animal_from_species(Mammal());

        if(second_species_name == "Mammal"){

            index_of_second_animal = select_animal_from_species(Mammal());

            Mammal* new_mammal = new Mammal, first_mammal, second_mammal;

            first_mammal = dynamic_cast<Mammal&>(*animals[index_of_first_animal]);
            second_mammal = dynamic_cast<Mammal&>(*animals[index_of_second_animal]);

            *new_mammal = first_mammal + second_mammal;
            animals.push_back((Animal*) new_mammal);
        }
    }

    else if(first_species_name == "Archaeopteryx"){

        index_of_first_animal = select_animal_from_species(Archaeopteryx());

        if(second_species_name == "Archaeopteryx"){
            index_of_second_animal = select_animal_from_species(Archaeopteryx());

            Archaeopteryx* new_archaeopteryx = new Archaeopteryx, first_archaeopteryx, second_archaeopteryx;

            first_archaeopteryx = dynamic_cast<Archaeopteryx&>(*animals[index_of_first_animal]);
            second_archaeopteryx = dynamic_cast<Archaeopteryx&>(*animals[index_of_second_animal]);

            *new_archaeopteryx = first_archaeopteryx + second_archaeopteryx;
            animals.push_back((Animal*) new_archaeopteryx);
        }
    }

    cout << "The new animal has been added to the list." << endl;

}


string Menu::get_name_of_class_from_typid_name(string name){

    if(name == typeid(Bird).name()){
        return "Bird";
    }
    else if(name == typeid(Reptile).name()){
        return "Reptile";
    }
    else if(name == typeid(Mammal).name()){
        return "Mammal";
    }
    else if(name == typeid(Archaeopteryx).name()){
        return "Archaeopteryx";
    }

}


string Menu::get_type_of_animal(string name){

    if(name == "Bird"){
        return typeid(Bird()).name();
    }
    else if(name == "Reptile"){
        return typeid(Reptile()).name();
    }
    else if(name == "Mammal"){
        return typeid(Mammal()).name();
    }
    else if(name == "Archaeopteryx"){
        return typeid(Archaeopteryx()).name();
    }
}

// void menu(){

//     vector<Animal*> animals;
    
//     Bird* bird = new Bird;
//     Reptile* reptile = new Reptile;
//     Mammal* mammal = new Mammal;
//     Archaeopteryx* archaeopteryx = new Archaeopteryx;

//     *bird = Bird("eagle",2, Skin::Feathers, Color::White, 4);
//     animals.push_back((Animal*) bird);
//     bird = new Bird;

//     *bird = Bird("owl", 2, Skin::Feathers, Color::Blue, 2);
//     animals.push_back((Animal*) bird);

//     *reptile = Reptile("boa", 0, Skin::Scales, 1);
//     animals.push_back((Animal*) reptile);
//     reptile = new Reptile;

//     *reptile = Reptile("turtle", 4, Skin::Leather, 0);
//     animals.push_back((Animal*) reptile);

//     *mammal = Mammal("koala", 4, Skin::Fur, 2, 10);
//     animals.push_back((Animal*) mammal);
//     mammal = new Mammal;

//     *mammal = Mammal("deer", 4, Skin::Leather, 4, 4);
//     animals.push_back((Animal*) mammal);

//     *archaeopteryx = Archaeopteryx("arch-2", 2, Skin::Feathers, Color::Green, 2, 0);
//     animals.push_back((Animal*) archaeopteryx);
//     archaeopteryx = new Archaeopteryx;

//     *archaeopteryx = Archaeopteryx("arch-1", 2, Skin::Feathers, Color::Blue, 3, 1);
//     animals.push_back((Animal*) archaeopteryx);

//     char option;

//     while(1){

//         cout << endl;
//         cout << "----Meniu----" << endl;
//         cout << "1. Add animal" << endl;
//         cout << "2. Delete animal" << endl;
//         cout << "3. Show animals" << endl;
//         cout << "4. Breed two animals" << endl;
//         cout << "Press q to exit" << endl;

//         cout << "Enter an option: ";
//         cin >> option;

//         system("cls");

//         if (option == '1'){

//    choose : cout << endl;
//             cout << "Which animal would you like to add?" << endl;
//             cout << "1. Bird" << endl;
//             cout << "2. Reptile" << endl;
//             cout << "3. Mammal" << endl;
//             cout << "4. Archaropteryx" << endl;
            
//             cout << endl << "Enter an option: ";
//             cin >> option;
//             cout << endl;

//             switch(option){
//                 case '1':{
//                     Bird* aux = new Bird;
//                     cin >> *aux;

//                     animals.push_back((Animal*) aux);
//                     cout << "Added!" << endl;

//                     break;
//                 }

//                 case '2':{
//                     Reptile* aux = new Reptile;
//                     cin >> *aux;

//                     animals.push_back((Animal*) aux);
//                     cout << "Added!" << endl;

//                     break;
//                 }

//                 case '3':{
//                     Mammal* aux = new Mammal;
//                     cin >> *aux;

//                     animals.push_back((Animal*) aux);
//                     cout << "Added!" << endl;

//                     break;
//                 }

//                 case '4':{
//                     Archaeopteryx* aux = new Archaeopteryx;
//                     cin >> *aux;
                    
//                     animals.push_back((Animal*) aux);
//                     cout << "Added!" << endl;
                    
//                     break;
//                 }

//                 default:{
//                     goto choose;
//                     break;
//                 }
//             }
//         }
        
//         else if(option == '2'){
            
//        ch : cout << endl;
//             cout << "Which animal would you like to delete?" << endl;
//             cout << "1. Bird" << endl;
//             cout << "2. Reptile" << endl;
//             cout << "3. Mammal" << endl;
//             cout << "4. Archaropteryx" << endl;
//             cout << endl;

//             int opt;

//             cout << "Enter an option: ";
//             cin >> opt;

//             if(opt == 1){
                
//                 int index = 1;

//                 // vector with all animals' indexes
//                 vector<int> vec_idx; 

//                 for(auto curent = animals.begin(); curent != animals.end(); curent++){
                    
//                     if(typeid(**curent) == typeid(Bird)){
//                         cout << index << ". " << (**curent).get_name() << endl;
//                         vec_idx.push_back(curent - animals.begin());
//                         index ++;
//                     }
                
//                 }

//                 cout << endl <<"Enter an option: ";
//                 cin >> opt;

//                 // the index to delete;
//                 animals.erase(animals.begin() + vec_idx[opt - 1]);
//                 cout << "Erased!" << endl;

//             }

//             else if(opt == 2){
                
//                 int index = 1;

//                 // vector with all animals' indexes
//                 vector<int> vec_idx; 

//                 for(auto curent = animals.begin(); curent != animals.end(); curent++){
                    
//                     if(typeid(**curent) == typeid(Reptile)){
//                         cout << index << ". " << (**curent).get_name() << endl;
//                         vec_idx.push_back(curent - animals.begin());
//                         index ++;
//                     }
                
//                 }

//                 cout << endl <<"Enter an option: ";
//                 cin >> opt;

//                 // the index to delete;
//                 animals.erase(animals.begin() + vec_idx[opt - 1]);
//                 cout << "Erased!" << endl;
//             }

//             else if(opt == 3){
                
//                 int index = 1;

//                 // vector with all animals' indexes
//                 vector<int> vec_idx; 

//                 for(auto curent = animals.begin(); curent != animals.end(); curent++){
                    
//                     if(typeid(**curent) == typeid(Mammal)){
//                         cout << index << ". " << (**curent).get_name() << endl;
//                         vec_idx.push_back(curent - animals.begin());
//                         index ++;
//                     }
                
//                 }

//                 cout << endl << "Enter an option: ";
//                 cin >> opt;

//                 // the index to delete;
//                 animals.erase(animals.begin() + vec_idx[opt - 1]);
//                 cout << "Erased!" << endl;
//             }

//             else if(opt == 4){
                
//                 int index = 1;

//                 // vector with all animals' indexes
//                 vector<int> vec_idx; 

//                 for(auto curent = animals.begin(); curent != animals.end(); curent++){
                    
//                     if(typeid(**curent) == typeid(Archaeopteryx)){
//                         cout << index << ". " << (**curent).get_name() << endl;
//                         vec_idx.push_back(curent - animals.begin());
//                         index ++;
//                     }
                
//                 }

//                 cout << endl << "Enter an option: ";
//                 cin >> opt;

//                 // the index to delete;
//                 animals.erase(animals.begin() + vec_idx[opt - 1]);
//                 cout << "Erased!" << endl;
//             }

//             else{
//                 goto ch;
//             }

//         }

//         else if(option == '3'){

//             for(auto curent = animals.begin(); curent != animals.end(); curent++){
                
//                 if(typeid(**curent) == typeid(Bird)){

//                     Bird* aux = dynamic_cast<Bird*>(*curent);

//                     if(aux == NULL){
//                         cout << "Problem with casting!" << endl;
//                         exit(-1);
//                     }

//                     cout << *aux << endl;
//                 }

//                 else if(typeid(**curent) == typeid(Reptile)){

//                     Reptile* aux = dynamic_cast<Reptile*>(*curent);

//                     if(aux == NULL){
//                         cout << "Problem with casting!" << endl;
//                         exit(-1);
//                     }

//                     cout << *aux << endl;
//                 }

//                 else if(typeid(**curent) == typeid(Mammal)){

//                     Mammal* aux = dynamic_cast<Mammal*>(*curent);

//                     if(aux == NULL){
//                         cout << "Problem with casting!" << endl;
//                         exit(-1);
//                     }

//                     cout << *aux << endl;
//                 }

//                 else if(typeid(**curent) == typeid(Archaeopteryx)){

//                     Archaeopteryx* aux = dynamic_cast<Archaeopteryx*>(*curent);

//                     if(aux == NULL){
//                         cout << "Problem with casting!" << endl;
//                         exit(-1);
//                     }

//                     cout << *aux << endl;
//                 }
                
//             }   

//         }

//         else if(option == '4'){
            
//             cout << endl;
//             cout << "Choose the first species:" << endl;
//             cout << "1. Bird" << endl;
//             cout << "2. Reptile" << endl;
//             cout << "3. Mammal" << endl;
//             cout << "4. Archaropteryx" << endl;

//             cout << "Enter an option: ";
//             cin >> option;

//             if(option == '1'){

//           ch4 : cout << "Choose the second species:" << endl;
//                 cout << "1. Bird" << endl;
//                 cout << "2. Reptile" << endl;

//                 cout << endl << "Enter an option: ";
//                 cin >> option;

//                 cout << endl;


//                 if(option == '1'){

//                     int opt1, opt2;

//                     int index = 1;

//                     // vector with all animals' indexes
//                     vector<int> vec_idx; 

//                     for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
//                         if(typeid(**curent) == typeid(Bird)){
//                             cout << index << ". " << (**curent).get_name() << endl;
//                             vec_idx.push_back(curent - animals.begin());
//                             index ++;
//                         }
                    
//                     }

//                     cout << "Choose the first bird: ";
//                     cin >> opt1;
//                     cout << "Choose the second bird: ";
//                     cin >> opt2;

//                     Bird* aux = new Bird;
//                     *aux = *(dynamic_cast<Bird*>((animals[vec_idx[opt1 - 1]]))) + *(dynamic_cast<Bird*>(animals[vec_idx[opt2 - 1]]));
//                     cout << endl <<"Bredeed a Bird: " << endl << endl;
//                     cout << *aux;
//                     cout << endl;

//                     animals.push_back((Animal*) aux);
//                 }
                
//                 else if(option == '2'){
//                     int opt1, opt2;

//                     int index = 1;

//                     // vector with all animals' indexes
//                     vector<int> vec_idx; 

//                     for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
//                         if(typeid(**curent) == typeid(Bird)){
//                             cout << index << ". " << (**curent).get_name() << endl;
//                             vec_idx.push_back(curent - animals.begin());
//                             index ++;
//                         }
                    
//                     }

//                     cout << "Choose a bird: ";
//                     cin >> opt1;

//                     Bird* bird = dynamic_cast<Bird*>(animals[vec_idx[opt1 -1]]);

//                     index = 1;
//                     vec_idx.clear();

//                     for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
//                         if(typeid(**curent) == typeid(Reptile)){
//                             cout << index << ". " << (**curent).get_name() << endl;
//                             vec_idx.push_back(curent - animals.begin());
//                             index ++;
//                         }
//                     }

//                     cout << "Choose a reptile: ";
//                     cin >> opt2;

//                     Reptile* reptile = dynamic_cast<Reptile*>(animals[vec_idx[opt2 -1]]);

//                     Archaeopteryx* aux = new Archaeopteryx(*bird);
//                     (*aux).set_name((*bird).get_name() + "-" + (*reptile).get_name());
//                     (*aux).set_is_venomous((*reptile).get_is_venomous());

//                     cout << endl <<"Bredeed an Archaeopteryx" << endl;
//                     cout << *aux;

//                     animals.push_back((Animal*) aux);
//                 }

//                 else{
//                     goto ch4;
//                 }
//             }

//             else if(option == '2'){

                
//           ch3 : cout << "Choose a species:" << endl;
//                 cout << "1. Bird" << endl;
//                 cout << "2. Reptile" << endl;

//                 cout << "Enter an option: ";
//                 cin >> option;
//                 cout << endl;


//                 if(option == '2'){

//                     int opt1, opt2;

//                     int index = 1;

//                     // vector with all animals' indexes
//                     vector<int> vec_idx; 

//                     for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
//                         if(typeid(**curent) == typeid(Reptile)){
//                             cout << index << ". " << (**curent).get_name() << endl;
//                             vec_idx.push_back(curent - animals.begin());
//                             index ++;
//                         }
                    
//                     }

//                     cout << "Choose the first reptile: ";
//                     cin >> opt1;
//                     cout << "Choose the first reptile: ";
//                     cin >> opt2;
//                     cout << endl;

//                     Reptile* aux = new Reptile;
//                     *aux = *(dynamic_cast<Reptile*>((animals[vec_idx[opt1 - 1]]))) + *(dynamic_cast<Reptile*>(animals[vec_idx[opt2 - 1]]));
//                     cout << endl << "Bredeed a Reptile: " << endl << endl;
//                     cout << *aux;

//                     animals.push_back((Animal*) aux);
//                 }

//                 else if(option == '1'){
//                     int opt1, opt2;

//                     int index = 1;

//                     // vector with all animals' indexes
//                     vector<int> vec_idx; 

//                     for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
//                         if(typeid(**curent) == typeid(Bird)){
//                             cout << index << ". " << (**curent).get_name() << endl;
//                             vec_idx.push_back(curent - animals.begin());
//                             index ++;
//                         }
                    
//                     }

//                     cout << "Choose a bird: ";
//                     cin >> opt1;

//                     Bird* bird = dynamic_cast<Bird*>(animals[vec_idx[opt1 -1]]);

//                     index = 1;
//                     vec_idx.clear();

//                     for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
//                         if(typeid(**curent) == typeid(Reptile)){
//                             cout << index << ". " << (**curent).get_name() << endl;
//                             vec_idx.push_back(curent - animals.begin());
//                             index ++;
//                         }
//                     }

//                     cout << "Choose a reptile: ";
//                     cin >> opt2;

//                     Reptile* reptile = dynamic_cast<Reptile*>(animals[vec_idx[opt2 -1]]);

//                     Archaeopteryx* aux = new Archaeopteryx(*bird);
//                     (*aux).set_name((*bird).get_name() + "-" + (*reptile).get_name());
//                     (*aux).set_is_venomous((*reptile).get_is_venomous());

//                     cout << endl <<"Bredeed an Archaeopteryx" << endl;
//                     cout << *aux;

//                     animals.push_back((Animal*) aux);
//                 }

//                 else {
//                     goto ch3;
//                 }
//             }

//             else if(option == '3'){
                
//           ch2 : cout << "Choose the second species:" << endl;
//                 cout << "1. Mammal" << endl;

//                 cout << "Enter an option: ";
//                 cin >> option;

//                 cout << endl;

//                 if(option == '1'){
                    
//                     int opt1, opt2;

//                     int index = 1;

//                     // vector with all animals' indexes
//                     vector<int> vec_idx; 

//                     for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
//                         if(typeid(**curent) == typeid(Mammal)){
//                             cout << index << ". " << (**curent).get_name() << endl;
//                             vec_idx.push_back(curent - animals.begin());
//                             index ++;
//                         }
                    
//                     }

//                     cout << "Choose the first mammal: ";
//                     cin >> opt1;
//                     cout << "Choose the second mammal: ";
//                     cin >> opt2;

//                     Mammal* aux = new Mammal;
//                     *aux = *(dynamic_cast<Mammal*>((animals[vec_idx[opt1 - 1]]))) + *(dynamic_cast<Mammal*>(animals[vec_idx[opt2 - 1]]));
//                     cout << endl << "Bredeed a Mammal: " << endl << endl;
//                     cout << *aux;

//                     animals.push_back((Animal*) aux);

//                 }

//                 else{
//                     goto ch2;
//                 }
//             }

//             else if(option == '4'){
                
//           ch5 : cout << "Choose the second species:" << endl;
//                 cout << "1. Archaeopteryx" << endl;

//                 cout << "Enter an option: ";
//                 cin >> option;

//                 cout << endl;

//                 if(option == '1'){
                    
//                     int opt1, opt2;

//                     int index = 1;

//                     // vector with all animals' indexes
//                     vector<int> vec_idx; 

//                     for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
//                         if(typeid(**curent) == typeid(Archaeopteryx)){
//                             cout << index << ". " << (**curent).get_name() << endl;
//                             vec_idx.push_back(curent - animals.begin());
//                             index ++;
//                         }
                    
//                     }

//                     cout << "Enter an option 1: ";
//                     cin >> opt1;
//                     cout << "Enter an option 2: ";
//                     cin >> opt2;

//                     Archaeopteryx* aux = new Archaeopteryx;
//                     *aux = *(dynamic_cast<Archaeopteryx*>((animals[vec_idx[opt1 - 1]]))) + *(dynamic_cast<Archaeopteryx*>(animals[vec_idx[opt2 - 1]]));
//                     cout << endl << "Bredeed a Archaeopteryx: " << endl << endl;
//                     cout << *aux;

//                     animals.push_back((Animal*) aux);

//                 }

//                 else{
//                     goto ch5;
//                 }
//             }

//         }

//         else if(option == 'q'){
//             for(auto curent = animals.begin(); curent != animals.end(); curent++){
//                 if(typeid(**curent) == typeid(Bird))
//                     delete dynamic_cast<Bird*>(*curent);
//                 else if(typeid(**curent) == typeid(Reptile))
//                     delete dynamic_cast<Reptile*>(*curent);
//                 else if(typeid(**curent) == typeid(Mammal))
//                     delete dynamic_cast<Mammal*>(*curent);
//                 else if(typeid(**curent) == typeid(Archaeopteryx))
//                     delete dynamic_cast<Archaeopteryx*>(*curent);
//             }
//             return;
//         }

//         else{
//             cout << "Enter a valid option!" << endl << endl;
//         }

//     }
// }

