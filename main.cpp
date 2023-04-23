#include <iostream>
#include "Headers/animal.hpp"
#include "Headers/bird.hpp"
#include "Headers/mammal.hpp"
#include "Headers/reptile.hpp"
#include "Headers/archaeopteryx.hpp"

using namespace std;


void menu(){

    char option;

    Bird birds[1000];
    Mammal mammals[1000];
    Reptile reptiles[1000];
    Archaeopteryx archaeopteryxs[1000];

    int birds_index = 0, mammals_index = 0, reptiles_index = 0, archaeopteryxs_index = 0;

    while(1){

        cout << "----Meniu----" << endl;
        cout << "1. Add animal" << endl;
        cout << "2. Delete animal" << endl;
        cout << "3. Show animals" << endl;
        cout << "Press q to exit" << endl;

        cout << "Enter an option: ";
        cin >> option;

        system("cls");
        
        if(option == '1'){

   choose : cout << "Which animal would you like to add?" << endl;
            cout << "1. Bird" << endl;
            cout << "2. Reptile" << endl;
            cout << "3. Mammal" << endl;
            cout << "4. Archaropteryx" << endl;

            cout << "Enter an option: ";
            cin >> option;

            switch(option){
                case '1':{
                    Bird aux;
                    cin >> aux;

                    birds[birds_index++] = aux;
                    break;

                }

                case '2':{
                    Reptile aux;
                    cin >> aux;

                    reptiles[reptiles_index++] = aux;

                    break;
                }

                case '3':{
                    Mammal aux;
                    cin >> aux;

                    mammals[mammals_index++] = aux;
                    break;
                }

                case '4':{
                    Archaeopteryx aux;
                    cin >> aux;

                    archaeopteryxs[archaeopteryxs_index++] = aux;
                }

                default:{
                    goto choose;
                    break;
                }
            }

        }

        else if(option == '2'){
 
 choose_2 : int index = 0;

            cout << "Choose an animal:";
            
            cout << "Birds\n";
            for(int i = 0; i < birds_index; i++, index++){
                cout << index << ". " << birds[i].get_name() << endl;
            }

            cout << "\nMammals\n";
            for(int i = index; i - birds_index < mammals_index; i++, index++){
                cout << index << ". " << mammals[i].get_name() << endl;
            }

            cout << "\nReptiles\n";
            for(int i = index; i - (birds_index + mammals_index) < reptiles_index; i++, index++){
                cout << index << ". " << reptiles[i].get_name() << endl;
            }

            cout << "\nArchaeopteryxs\n";
            for(int i = index; i - (birds_index + mammals_index + reptiles_index) < archaeopteryxs_index; i++, index++){
                cout << index << ". " << archaeopteryxs[i].get_name() << endl; 
            }

            int opt;
            cout << "Enter an option: ";
            cin >> opt;

            if(opt < birds_index){
                for(int i = 0; i < birds_index; i++){
                    if(birds[i].get_name() == birds[opt].get_name()){
                        birds[i] = birds[--birds_index];
                        break;
                    }
                }
            }
            else if(opt < birds_index + mammals_index){
                for(int i = 0; i < mammals_index; i++){
                    if(mammals[i].get_name() == mammals[opt - birds_index].get_name()){
                       mammals[i] =mammals[--mammals_index];
                        break;
                    }
                }
            }

            else if(opt < birds_index + mammals_index + reptiles_index){
                for(int i = 0; i < reptiles_index; i++){
                    if(reptiles[i].get_name() == reptiles[opt - birds_index - mammals_index].get_name()){
                       reptiles[i] =reptiles[--reptiles_index];
                        break;
                    }
                }
            }

            else if(opt < birds_index + mammals_index + reptiles_index + archaeopteryxs_index){
                for(int i = 0; i < archaeopteryxs_index; i++){
                    if(archaeopteryxs[i].get_name() == archaeopteryxs[opt - birds_index - mammals_index - reptiles_index].get_name()){
                       archaeopteryxs[i] =archaeopteryxs[--archaeopteryxs_index];
                        break;
                    }
                }
            }

            else{
                goto choose_2;
            }

        }

        else if(option == '3'){

            cout << "Birds\n";
            for(int i = 0; i < birds_index; i++){
                cout << birds[i] << endl;
            }

            cout << "\nMammals\n";
            for(int i = 0; i < mammals_index; i++){
                cout << mammals[i] << endl;
            }

            cout << "\nReptiles\n";
            for(int i = 0; i < reptiles_index; i++){
                cout << reptiles[i] << endl;
            }

            cout << "\nArchaeopteryxs\n";
            for(int i = 0; i < archaeopteryxs_index; i++){
                cout << archaeopteryxs[i] << endl; 
            }

        }

        else if(option == 'q'){
            return;
        }

        else{
            cout << "Enter a valid option!" << endl;
        }

    }   

}


int main(){

    // Mammal g("om", 2, Skin::Feather, 2, 18);
    // g.make_sound();
    // Bird().make_sound();

    // Bird().greed();
    // g.greed();

    // Bird pasare("uliu", 2, Skin::Feather, Color::Purple, 4);
    // Reptile reptila("sarpe", 0, Skin::Scales, true);
    // //  cout << r;
    // //  cin >> r;
    // //  cout << r;
    // //  r.greed();
    // //  r.make_sound();

    // Archaeopteryx a("uliu", 2, Skin::Feather, Color::Purple, 4, true), b;
    // cout << a;
    // a.make_sound();
    // a.greed();

    menu();

    // pasare + reptila;

    return 0;
}