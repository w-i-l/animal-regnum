#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <map>
#include <string>

#include "../../Headers/animal.hpp"
#include "../../Headers/bird.hpp"
#include "../../Headers/reptile.hpp"
#include "../../Headers/mammal.hpp"
#include "../../Headers/archaeopteryx.hpp"
#include "../../Headers/menu.hpp"
#include "../../Headers/custom_exception.hpp"



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

    admin_username = "admin";
    admin_password = "admin";

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
// Which animal would you like to "text_to_display"?
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

    index = 1;

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


// shows info from a selected animal by user
void Menu::display_animal_info(){

    int selected_species = select_species("display info");
    
    // Bird
    if(selected_species == 1){

        int selected_animal = select_animal_from_species<Bird>(Bird());
        Bird bird = dynamic_cast<Bird&>(*animals[selected_animal]);
        cout << bird;
    }

    // Reptile
    else if(selected_species == 2){

        int selected_animal = select_animal_from_species<Reptile>(Reptile());
        Reptile reptile = dynamic_cast<Reptile&>(*animals[selected_animal]);
        cout << reptile;
    }

    // Mammal
    else if(selected_species == 3){

        int selected_animal = select_animal_from_species<Mammal>(Mammal());
        Mammal mammal = dynamic_cast<Mammal&>(*animals[selected_animal]);
        cout << mammal;
    }

    // Archaeopteryx
    else if(selected_species == 4){

        int selected_animal = select_animal_from_species<Archaeopteryx>(Archaeopteryx());
        Archaeopteryx archaeopteryx = dynamic_cast<Archaeopteryx&>(*animals[selected_animal]);
        cout << archaeopteryx;
    }

    cout << endl;


}


// throws AuthFailed if cant login as admin
void Menu::admin_auth(){
    
    cout << "Please provide your credentials to access the admin menu!" << endl;

    string username, password;

    cout << "Username: ";
    cin >> username;

    cout << endl;

    cout << "Password: ";
    cin >> password;

    if(username == admin_username){

        if(password == admin_password){
            cout << "Welcome, " << username << "!" << endl;
            return;
        }

        // wrong password - give 2 more attempts
        else{

            int attempts = 2;

            while(attempts && password != admin_password){

                cout << "Wrong password!" << endl;
                cout << "You have " << attempts << " more attempts to enter the correct password." << endl;

                cout << "Password: ";
                cin >> password;

                attempts--;
            }

            if(password == admin_password){
                cout << "Welcome, " << username << "!" << endl;
                return;
            }
            else{
                throw AuthFailed();
            }
        }
    }
    else{
        throw AuthFailed();
    }
}


int Menu::get_option_for_user(){

    cout << endl << "=== User === Menu ===" << endl << endl;
    cout << "1. Display all animlas" << endl;
    cout << "2. Select an animal" << endl;
    cout << "3. Log out" << endl;
    cout << "0. Exit the application" << endl;

    int option;
    cout << endl << "Enter an option: ";
    cin >> option;

    if(option < 0 || option >= 4){
        throw InvalidOption();
    }

    return option;
}


void Menu::user_menu(){

    while(true){
        int option = get_option_for_user();

        system("cls");

        if(option == 1){
            display_animals_names();
        }

        else if(option == 2){
            display_animal_info();
        }
        
        else if(option == 3){
            return;
        }

        else if(option == 0){
            exit(0);
        }

        else{
            throw InvalidOption();
        }
    }

}


int Menu::get_option_for_admin(){

    cout << "::::Admin::::Menu::::" << endl << endl;

    cout << "[1] Add an animal" << endl;
    cout << "[2] Remove an animal" << endl;
    cout << "[3] Breed two animals" << endl;
    cout << "[4] Display all animals" << endl;
    cout << "[5] Select an animal" << endl;
    cout << "[6] Update the zoo from a file" << endl;
    cout << "[7] Save the zoo to a file" << endl;
    cout << "[8] Delete the zoo" << endl;
    cout << "[9] Log Out" << endl;
    cout << "[0] Exit the application" << endl;

    int option;
    cout << "Choose an option from above: ";
    cin >> option;
    cout << endl;

    if(option < 0 || option >= 10){
        throw InvalidOption();
    }

    return option;

}


void Menu::admin_menu(){

    while(true){

        int option = get_option_for_admin();

        system("cls");

        if(option == 1){
            add_animal();
        }
        
        else if(option == 2){
            remove_animal();
        }
        
        else if(option == 3){
            breed_animals();
        }
        
        else if(option == 4){
            display_animals_names();
        }
        
        else if(option == 5){
            display_animal_info();
        }
        
        else if(option == 6){

            string filename, append_to_vector;
            bool append;

            cout << "Enter the filename: ";
            cin >> filename;
            cout << endl;

            cout << "Do you want to append to the existing animals?(y/n): ";
            cin >> append_to_vector;
            cout << endl;

            if(append_to_vector == "y" || append_to_vector == "yes" || append_to_vector == "Y"){
                append = true;
            }
            else if(append_to_vector == "n" || append_to_vector == "no" || append_to_vector == "N"){
                append = false;
            }
            else{
                throw InvalidOption();
            }

            read_from_file(filename, append);
        }

        else if(option == 7){
            string filename, append_to_vector;
            bool append;

            cout << "Enter the filename: ";
            cin >> filename;
            cout << endl;

            cout << "Do you want to append to the existing animals from file?(y/n): ";
            cin >> append_to_vector;
            cout << endl;

            if(append_to_vector == "y" || append_to_vector == "yes" || append_to_vector == "Y"){
                append = true;
            }
            else if(append_to_vector == "n" || append_to_vector == "no" || append_to_vector == "N"){
                append = false;
            }
            else{
                throw InvalidOption();
            }

            write_to_file(filename, append);
        }

        else if(option == 8){
            delete_animals();
        }

        else if(option == 9){
            return;
        }

        else if (option == 0){
            exit(0);
        }

        else{
            throw InvalidOption();
        }
    }
}


void Menu::run(){

    while(true){
        cout << "Welcome to the Zoo!" << endl << endl;
        cout << "Select your role!" << endl;
        cout << "[1] admin" << endl;
        cout << "[2] user" << endl;
        cout << "[0] exit" << endl;

        int option;
        cout << "Enter your option: ";
        cin >> option;
        cout << endl;

        if(option == 1){
            admin_auth();            
            admin_menu();
        }

        else if(option == 2){
            user_menu();
        }

        else if(option == 0){
            return;
        }
        
        else{
            throw InvalidOption();
        }
    }
}