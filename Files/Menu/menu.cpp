#include <iostream>
#include <vector>
#include <cstring>
#include "Headers\animal.hpp"
#include "Headers\reptile.hpp"
#include "Headers\bird.hpp"
#include "Headers\mammal.hpp"
#include "Headers\archaeopteryx.hpp"
#include "Headers\menu.hpp"

using namespace std;


void menu(){

    vector<Animal*> animals;
    
    Bird* bird = new Bird;
    Reptile* reptile = new Reptile;
    Mammal* mammal = new Mammal;
    Archaeopteryx* archaeopteryx = new Archaeopteryx;

    *bird = Bird("eagle",2, Skin::Feather, Color::White, 4);
    animals.push_back((Animal*) bird);
    bird = new Bird;

    *bird = Bird("owl", 2, Skin::Feather, Color::Blue, 2);
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

    *archaeopteryx = Archaeopteryx("arch-2", 2, Skin::Feather, Color::Green, 2, 0);
    animals.push_back((Animal*) archaeopteryx);
    archaeopteryx = new Archaeopteryx;

    *archaeopteryx = Archaeopteryx("arch-1", 2, Skin::Feather, Color::Blue, 3, 1);
    animals.push_back((Animal*) archaeopteryx);

    char option;

    while(1){

        cout << endl;
        cout << "----Meniu----" << endl;
        cout << "1. Add animal" << endl;
        cout << "2. Delete animal" << endl;
        cout << "3. Show animals" << endl;
        cout << "4. Breed two animals" << endl;
        cout << "Press q to exit" << endl;

        cout << "Enter an option: ";
        cin >> option;

        system("cls");

        if (option == '1'){

   choose : cout << endl;
            cout << "Which animal would you like to add?" << endl;
            cout << "1. Bird" << endl;
            cout << "2. Reptile" << endl;
            cout << "3. Mammal" << endl;
            cout << "4. Archaropteryx" << endl;
            
            cout << endl << "Enter an option: ";
            cin >> option;
            cout << endl;

            switch(option){
                case '1':{
                    Bird* aux = new Bird;
                    cin >> *aux;

                    animals.push_back((Animal*) aux);
                    cout << "Added!" << endl;

                    break;
                }

                case '2':{
                    Reptile* aux = new Reptile;
                    cin >> *aux;

                    animals.push_back((Animal*) aux);
                    cout << "Added!" << endl;

                    break;
                }

                case '3':{
                    Mammal* aux = new Mammal;
                    cin >> *aux;

                    animals.push_back((Animal*) aux);
                    cout << "Added!" << endl;

                    break;
                }

                case '4':{
                    Archaeopteryx* aux = new Archaeopteryx;
                    cin >> *aux;
                    
                    animals.push_back((Animal*) aux);
                    cout << "Added!" << endl;
                    
                    break;
                }

                default:{
                    goto choose;
                    break;
                }
            }
        }
        
        else if(option == '2'){
            
       ch : cout << endl;
            cout << "Which animal would you like to delete?" << endl;
            cout << "1. Bird" << endl;
            cout << "2. Reptile" << endl;
            cout << "3. Mammal" << endl;
            cout << "4. Archaropteryx" << endl;
            cout << endl;

            int opt;

            cout << "Enter an option: ";
            cin >> opt;

            if(opt == 1){
                
                int index = 1;

                // vector with all animals' indexes
                vector<int> vec_idx; 

                for(auto curent = animals.begin(); curent != animals.end(); curent++){
                    
                    if(typeid(**curent) == typeid(Bird)){
                        cout << index << ". " << (**curent).get_name() << endl;
                        vec_idx.push_back(curent - animals.begin());
                        index ++;
                    }
                
                }

                cout << endl <<"Enter an option: ";
                cin >> opt;

                // the index to delete;
                animals.erase(animals.begin() + vec_idx[opt - 1]);
                cout << "Erased!" << endl;

            }

            else if(opt == 2){
                
                int index = 1;

                // vector with all animals' indexes
                vector<int> vec_idx; 

                for(auto curent = animals.begin(); curent != animals.end(); curent++){
                    
                    if(typeid(**curent) == typeid(Reptile)){
                        cout << index << ". " << (**curent).get_name() << endl;
                        vec_idx.push_back(curent - animals.begin());
                        index ++;
                    }
                
                }

                cout << endl <<"Enter an option: ";
                cin >> opt;

                // the index to delete;
                animals.erase(animals.begin() + vec_idx[opt - 1]);
                cout << "Erased!" << endl;
            }

            else if(opt == 3){
                
                int index = 1;

                // vector with all animals' indexes
                vector<int> vec_idx; 

                for(auto curent = animals.begin(); curent != animals.end(); curent++){
                    
                    if(typeid(**curent) == typeid(Mammal)){
                        cout << index << ". " << (**curent).get_name() << endl;
                        vec_idx.push_back(curent - animals.begin());
                        index ++;
                    }
                
                }

                cout << endl << "Enter an option: ";
                cin >> opt;

                // the index to delete;
                animals.erase(animals.begin() + vec_idx[opt - 1]);
                cout << "Erased!" << endl;
            }

            else if(opt == 4){
                
                int index = 1;

                // vector with all animals' indexes
                vector<int> vec_idx; 

                for(auto curent = animals.begin(); curent != animals.end(); curent++){
                    
                    if(typeid(**curent) == typeid(Archaeopteryx)){
                        cout << index << ". " << (**curent).get_name() << endl;
                        vec_idx.push_back(curent - animals.begin());
                        index ++;
                    }
                
                }

                cout << endl << "Enter an option: ";
                cin >> opt;

                // the index to delete;
                animals.erase(animals.begin() + vec_idx[opt - 1]);
                cout << "Erased!" << endl;
            }

            else{
                goto ch;
            }

        }

        else if(option == '3'){

            for(auto curent = animals.begin(); curent != animals.end(); curent++){
                
                if(typeid(**curent) == typeid(Bird)){

                    Bird* aux = dynamic_cast<Bird*>(*curent);

                    if(aux == NULL){
                        cout << "Problem with casting!" << endl;
                        exit(-1);
                    }

                    cout << *aux << endl;
                }

                else if(typeid(**curent) == typeid(Reptile)){

                    Reptile* aux = dynamic_cast<Reptile*>(*curent);

                    if(aux == NULL){
                        cout << "Problem with casting!" << endl;
                        exit(-1);
                    }

                    cout << *aux << endl;
                }

                else if(typeid(**curent) == typeid(Mammal)){

                    Mammal* aux = dynamic_cast<Mammal*>(*curent);

                    if(aux == NULL){
                        cout << "Problem with casting!" << endl;
                        exit(-1);
                    }

                    cout << *aux << endl;
                }

                else if(typeid(**curent) == typeid(Archaeopteryx)){

                    Archaeopteryx* aux = dynamic_cast<Archaeopteryx*>(*curent);

                    if(aux == NULL){
                        cout << "Problem with casting!" << endl;
                        exit(-1);
                    }

                    cout << *aux << endl;
                }
                
            }   

        }

        else if(option == '4'){
            
            cout << endl;
            cout << "Choose the first species:" << endl;
            cout << "1. Bird" << endl;
            cout << "2. Reptile" << endl;
            cout << "3. Mammal" << endl;
            cout << "4. Archaropteryx" << endl;

            cout << "Enter an option: ";
            cin >> option;

            if(option == '1'){

          ch4 : cout << "Choose the second species:" << endl;
                cout << "1. Bird" << endl;
                cout << "2. Reptile" << endl;

                cout << endl << "Enter an option: ";
                cin >> option;

                cout << endl;


                if(option == '1'){

                    int opt1, opt2;

                    int index = 1;

                    // vector with all animals' indexes
                    vector<int> vec_idx; 

                    for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
                        if(typeid(**curent) == typeid(Bird)){
                            cout << index << ". " << (**curent).get_name() << endl;
                            vec_idx.push_back(curent - animals.begin());
                            index ++;
                        }
                    
                    }

                    cout << "Choose the first bird: ";
                    cin >> opt1;
                    cout << "Choose the second bird: ";
                    cin >> opt2;

                    Bird* aux = new Bird;
                    *aux = *(dynamic_cast<Bird*>((animals[vec_idx[opt1 - 1]]))) + *(dynamic_cast<Bird*>(animals[vec_idx[opt2 - 1]]));
                    cout << endl <<"Bredeed a Bird: " << endl << endl;
                    cout << *aux;
                    cout << endl;

                    animals.push_back((Animal*) aux);
                }
                
                else if(option == '2'){
                    int opt1, opt2;

                    int index = 1;

                    // vector with all animals' indexes
                    vector<int> vec_idx; 

                    for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
                        if(typeid(**curent) == typeid(Bird)){
                            cout << index << ". " << (**curent).get_name() << endl;
                            vec_idx.push_back(curent - animals.begin());
                            index ++;
                        }
                    
                    }

                    cout << "Choose a bird: ";
                    cin >> opt1;

                    Bird* bird = dynamic_cast<Bird*>(animals[vec_idx[opt1 -1]]);

                    index = 1;
                    vec_idx.clear();

                    for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
                        if(typeid(**curent) == typeid(Reptile)){
                            cout << index << ". " << (**curent).get_name() << endl;
                            vec_idx.push_back(curent - animals.begin());
                            index ++;
                        }
                    }

                    cout << "Choose a reptile: ";
                    cin >> opt2;

                    Reptile* reptile = dynamic_cast<Reptile*>(animals[vec_idx[opt2 -1]]);

                    Archaeopteryx* aux = new Archaeopteryx(*bird);
                    (*aux).set_name((*bird).get_name() + "-" + (*reptile).get_name());
                    (*aux).set_is_venomous((*reptile).get_is_venomous());

                    cout << endl <<"Bredeed an Archaeopteryx" << endl;
                    cout << *aux;

                    animals.push_back((Animal*) aux);
                }

                else{
                    goto ch4;
                }
            }

            else if(option == '2'){

                
          ch3 : cout << "Choose a species:" << endl;
                cout << "1. Bird" << endl;
                cout << "2. Reptile" << endl;

                cout << "Enter an option: ";
                cin >> option;
                cout << endl;


                if(option == '2'){

                    int opt1, opt2;

                    int index = 1;

                    // vector with all animals' indexes
                    vector<int> vec_idx; 

                    for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
                        if(typeid(**curent) == typeid(Reptile)){
                            cout << index << ". " << (**curent).get_name() << endl;
                            vec_idx.push_back(curent - animals.begin());
                            index ++;
                        }
                    
                    }

                    cout << "Choose the first reptile: ";
                    cin >> opt1;
                    cout << "Choose the first reptile: ";
                    cin >> opt2;
                    cout << endl;

                    Reptile* aux = new Reptile;
                    *aux = *(dynamic_cast<Reptile*>((animals[vec_idx[opt1 - 1]]))) + *(dynamic_cast<Reptile*>(animals[vec_idx[opt2 - 1]]));
                    cout << endl << "Bredeed a Reptile: " << endl << endl;
                    cout << *aux;

                    animals.push_back((Animal*) aux);
                }

                else if(option == '1'){
                    int opt1, opt2;

                    int index = 1;

                    // vector with all animals' indexes
                    vector<int> vec_idx; 

                    for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
                        if(typeid(**curent) == typeid(Bird)){
                            cout << index << ". " << (**curent).get_name() << endl;
                            vec_idx.push_back(curent - animals.begin());
                            index ++;
                        }
                    
                    }

                    cout << "Choose a bird: ";
                    cin >> opt1;

                    Bird* bird = dynamic_cast<Bird*>(animals[vec_idx[opt1 -1]]);

                    index = 1;
                    vec_idx.clear();

                    for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
                        if(typeid(**curent) == typeid(Reptile)){
                            cout << index << ". " << (**curent).get_name() << endl;
                            vec_idx.push_back(curent - animals.begin());
                            index ++;
                        }
                    }

                    cout << "Choose a reptile: ";
                    cin >> opt2;

                    Reptile* reptile = dynamic_cast<Reptile*>(animals[vec_idx[opt2 -1]]);

                    Archaeopteryx* aux = new Archaeopteryx(*bird);
                    (*aux).set_name((*bird).get_name() + "-" + (*reptile).get_name());
                    (*aux).set_is_venomous((*reptile).get_is_venomous());

                    cout << endl <<"Bredeed an Archaeopteryx" << endl;
                    cout << *aux;

                    animals.push_back((Animal*) aux);
                }

                else {
                    goto ch3;
                }
            }

            else if(option == '3'){
                
          ch2 : cout << "Choose the second species:" << endl;
                cout << "1. Mammal" << endl;

                cout << "Enter an option: ";
                cin >> option;

                cout << endl;

                if(option == '1'){
                    
                    int opt1, opt2;

                    int index = 1;

                    // vector with all animals' indexes
                    vector<int> vec_idx; 

                    for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
                        if(typeid(**curent) == typeid(Mammal)){
                            cout << index << ". " << (**curent).get_name() << endl;
                            vec_idx.push_back(curent - animals.begin());
                            index ++;
                        }
                    
                    }

                    cout << "Choose the first mammal: ";
                    cin >> opt1;
                    cout << "Choose the second mammal: ";
                    cin >> opt2;

                    Mammal* aux = new Mammal;
                    *aux = *(dynamic_cast<Mammal*>((animals[vec_idx[opt1 - 1]]))) + *(dynamic_cast<Mammal*>(animals[vec_idx[opt2 - 1]]));
                    cout << endl << "Bredeed a Mammal: " << endl << endl;
                    cout << *aux;

                    animals.push_back((Animal*) aux);

                }

                else{
                    goto ch2;
                }
            }

            else if(option == '4'){
                
          ch5 : cout << "Choose the second species:" << endl;
                cout << "1. Archaeopteryx" << endl;

                cout << "Enter an option: ";
                cin >> option;

                cout << endl;

                if(option == '1'){
                    
                    int opt1, opt2;

                    int index = 1;

                    // vector with all animals' indexes
                    vector<int> vec_idx; 

                    for(auto curent = animals.begin(); curent != animals.end(); curent++){
                        
                        if(typeid(**curent) == typeid(Archaeopteryx)){
                            cout << index << ". " << (**curent).get_name() << endl;
                            vec_idx.push_back(curent - animals.begin());
                            index ++;
                        }
                    
                    }

                    cout << "Enter an option 1: ";
                    cin >> opt1;
                    cout << "Enter an option 2: ";
                    cin >> opt2;

                    Archaeopteryx* aux = new Archaeopteryx;
                    *aux = *(dynamic_cast<Archaeopteryx*>((animals[vec_idx[opt1 - 1]]))) + *(dynamic_cast<Archaeopteryx*>(animals[vec_idx[opt2 - 1]]));
                    cout << endl << "Bredeed a Archaeopteryx: " << endl << endl;
                    cout << *aux;

                    animals.push_back((Animal*) aux);

                }

                else{
                    goto ch5;
                }
            }

        }

        else if(option == 'q'){
            return;
        }

        else{
            cout << "Enter a valid option!" << endl << endl;
        }

    }
}

