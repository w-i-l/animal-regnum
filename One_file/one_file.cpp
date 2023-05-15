#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;


enum class Skin{Fur,
    Scales,
    Leather,
    Feathers,
    None
};

enum class Color{
    Red,
    White,
    Blue,
    Green,
    Purple,
    None
};



class Animal{

    protected:
        string name;
        int no_of_feet;
        Skin type_of_skin;

    public:

        // getters
        string get_name() const{ return this->name; }
        int get_no_of_feet() const{ return this->no_of_feet; }
        Skin get_type_of_skin() const{ return this->type_of_skin; }

        // setters
        void set_name(string name) { this->name = name; }
        void set_no_of_feet(int no_of_feet) { this->no_of_feet = no_of_feet; }
        void set_type_of_skin(Skin type_of_skin) {this->type_of_skin = type_of_skin; }

        // constructors
        Animal();
        Animal(string name, int no_of_feet, Skin type_of_skin);
        Animal(const Animal& copy);

        // operators
        Animal& operator=(const Animal& copy);

        // friend
        friend istream& operator>>(istream& in, Animal& copy);
        friend ostream& operator<<(ostream& out, const Animal& copy);

        // virtual
        virtual void make_sound() = 0;
        virtual void multiply(vector<Animal*> animals) = 0;

        // method
        const void greed() const;

};


class Reptile: virtual public Animal{

    protected:
        bool is_venomous;

    public:
        
        // getters
        bool get_is_venomous() const{ return this->is_venomous; }

        // setters
        void set_is_venomous(bool is_venomous) { this->is_venomous = is_venomous; }

        // constructors
        Reptile();
        Reptile(string name, int no_of_feet, Skin type_of_skin, bool is_venomous);
        Reptile(const Reptile& copy);


        // operators
        Reptile& operator = (const Reptile& copy);
        Reptile operator + (Reptile copy);

        // friends
        friend istream& operator >> (istream& in, Reptile& copy);
        friend ostream& operator << (ostream& out, const Reptile& copy);

        // virtual
        void make_sound();
        void multiply(vector<Animal*> animals);

};


class Bird : virtual public Animal{

    protected: 
        Color wing_color;
        int no_of_eggs;
    
    public:

        // getters
        Color get_wing_color() const{ return this->wing_color; }
        int get_no_of_eggs() const{ return this->no_of_eggs; }
        
        // setters
        void set_wing_color(Color wing_color) { this->wing_color = wing_color; }
        void set_no_of_eggs(int no_of_eggs) { this->no_of_eggs = no_of_eggs; }

        // constructors
        Bird();
        Bird(string name, int no_of_feet, Skin type_of_skin, Color wing_color, int no_of_egs);
        Bird(const Bird& copy);

        // operators
        Bird& operator = (const Bird& copy);
        Bird operator + (Bird copy);

        // friend
        friend istream& operator>>(istream& in, Bird& copy);
        friend ostream& operator<<(ostream& out, const Bird& copy);

        // virtual
        void make_sound();
        void multiply(vector<Animal*> animals);

};


class Mammal : virtual public Animal{

    private:
        int no_of_mammal_glands;
        int reproductive_maturity_year;

    public:

        // getters
        int get_no_of_mammal_glands() const{ return this->no_of_mammal_glands; }
        int  get_reproductive_maturity_year() const{ return this->reproductive_maturity_year; }

        // setters set
        void set_no_of_mammal_glands(int no_of_mammal_glands) { this->no_of_mammal_glands = no_of_mammal_glands; }
        void set_reproductive_maturity_year(int reproductive_maturity_year) { this->reproductive_maturity_year = reproductive_maturity_year; }

        // constructors
        Mammal();
        Mammal(string name, int no_of_feet, Skin type_of_skin, int no_of_mammal_glands, int reproductive_maturity_year);
        Mammal(const Mammal& copy);

        // operators
        Mammal& operator=(const Mammal& copy);
        Mammal operator + (Mammal copy);

        // friend
        friend istream& operator>>(istream& in, Mammal& copy);
        friend ostream& operator<<(ostream& out, Mammal& copy);

        // virtual
        void make_sound();
        void multiply(vector<Animal*> animals);

}; 


class Archaeopteryx : public Bird, public Reptile{

    public:

        // constructors
        Archaeopteryx();
        Archaeopteryx(string name, int no_of_feet, Skin type_of_skin, 
            Color wing_color, int no_of_eggs, bool is_venomous);
        Archaeopteryx(const Archaeopteryx& copy);
        Archaeopteryx(const Bird& copy);

        // operators
        Archaeopteryx& operator = (const Archaeopteryx& copy);
        Archaeopteryx operator + (Archaeopteryx copy);

        // friends
        friend istream& operator >> (istream& in, Archaeopteryx& copy);
        friend ostream& operator << (ostream& out, const Archaeopteryx& copy);

        // methods
        void make_sound();
        void multiply(vector<Animal*> animals);
};


//////////////////////////////////////////////////////////////////////


Animal::Animal(){
    this->name = "none";
    this->no_of_feet = 0;
    this->type_of_skin = Skin::None;
}


Animal::Animal(string name, int no_of_feet, Skin type_of_skin){
    this->name = name;
    this->no_of_feet = no_of_feet;
    this->type_of_skin = type_of_skin;
}


Animal::Animal(const Animal& copy){
    this->name = copy.name;
    this->no_of_feet = copy.no_of_feet;
    this->type_of_skin = copy.type_of_skin;
}


Animal& Animal::operator=(const Animal& copy){
    if(this != &copy){
        this->name = copy.name;
        this->no_of_feet = copy.no_of_feet;
        this->type_of_skin = copy.type_of_skin;
    }
    
    return *this;
}


istream& operator>>(istream& in, Animal& copy){
    cout << "Animal Read: " << endl;
    cout << "Name: ";
    in >> copy.name;
    cout << "Number of feet: ";
    in >> copy.no_of_feet;
    read:cout << "Skin type (fur/leather/feathers/scales): ";
    char aux[30];
    in >> aux;

    if (strcmp(aux, "fur") == 0)
        copy.type_of_skin = Skin::Fur;
    else if (strcmp(aux, "leather") == 0)
        copy.type_of_skin = Skin::Leather;
    else if (strcmp(aux, "scales") == 0)
        copy.type_of_skin = Skin::Scales;
    else if (strcmp(aux, "feathers") == 0)
        copy.type_of_skin = Skin::Feathers;
    else
        goto read;

    return in;
}   


ostream& operator<<(ostream& out, const Animal& copy){

    out << "Animal Info:" << endl;
    out << "Name: " << copy.name << endl;
    out << "Number of feet: " << copy.no_of_feet << endl;
    out << "Type of skin: ";
    
    if(copy.type_of_skin == Skin::Fur){
        out << "fur";
    }
    else if(copy.type_of_skin == Skin::Leather){
        out << "leather";
    }
    else if(copy.type_of_skin == Skin::Scales){
        out << "scales";
    }
    else if(copy.type_of_skin == Skin::Feathers){
        out << "feathers";
    }
    else{
        out << "none";
    }
    out << endl;

    return out;
}
 

const void Animal::greed() const{
    cout << "I'm alive!" << endl;
}


//////////////////////////////////////////////////////////////////////


Bird::Bird() : Animal(){
    this->no_of_eggs = 0 ;
    this->wing_color = Color::None;
}


Bird::Bird(string name, int no_of_feet, Skin type_of_skin, Color wing_color, int no_of_eggs) : Animal(name, no_of_feet, type_of_skin){
    this->wing_color = wing_color;
    this->no_of_eggs = no_of_eggs;
}


Bird::Bird(const Bird& copy) : Animal(copy){
    this->no_of_eggs = copy.no_of_eggs;
    this->wing_color = copy.wing_color;
}


Bird& Bird::operator=(const Bird& copy){
    if(this != &copy){
        Animal::operator=(copy);
        this->no_of_eggs = copy.no_of_eggs;
        this->wing_color = copy.wing_color;
    }
    
    return *this;
}


Bird Bird::operator + (Bird copy){

    copy.name = this->name + "-"+ copy.name;
    copy.no_of_feet = max(this->no_of_feet, copy.no_of_feet);
    copy.no_of_eggs = this->no_of_eggs + copy.no_of_eggs;

    return copy;

}


istream& operator>>(istream& in, Bird& copy){
    
    in >> (Animal&)copy;
    cout << "Bird Read: " << endl;

    cout << "Number of eggs: ";
    in >> copy.no_of_eggs;

    read:cout << "Color (red/green/blue/purple/white): ";
    char aux[30];
    in >> aux;
    if(strcmp(aux, "red") == 0)
        copy.wing_color = Color::Red;
    else if(strcmp(aux, "blue") == 0)
        copy.wing_color = Color::Blue;
    else if(strcmp(aux, "green") == 0)
        copy.wing_color = Color::Green;
    else if(strcmp(aux, "purple") == 0)
        copy.wing_color = Color::Purple;
    else if(strcmp(aux, "white") == 0)
        copy.wing_color = Color::White;
    else
        goto read;

    return in;
}


ostream& operator<<(ostream& out, const Bird& copy){

    out << (Animal&)copy;
    out << "Bird Info" << endl;

    out << "Number of eggs: " << copy.no_of_eggs << endl;

    out << "Wing color: ";
    if(copy.wing_color == Color::Blue)
        out << "blue";
    else if(copy.wing_color == Color::Red)
        out << "red";
    else if(copy.wing_color == Color::White)
        out << "white";
    else if(copy.wing_color == Color::Green)
        out << "green";
    else if(copy.wing_color == Color::Purple)
        out << "purple";
    else
        out << "none";

    out << endl;

    return out;
}


void Bird::make_sound(){
    cout << "CIP CIP RIP" << endl;
}


void Bird::multiply(vector<Animal*> animals){

    Bird* bird = new Bird;

    for(int i = 0; i < rand() % this->no_of_eggs; i++){

        *bird = Bird(this->name + "-" + to_string(i), this->no_of_feet, this->type_of_skin, Color::White, rand() % 10);
        animals.push_back((Animal*) bird);
        bird = new Bird;
    }
}


//////////////////////////////////////////////////////////////////////


Mammal::Mammal() : Animal(){
    this->no_of_mammal_glands = 0;
    this->reproductive_maturity_year = 0;
}


Mammal::Mammal(string name, int no_of_feet, Skin type_of_skin,int no_of_mammal_glands, int reproductive_maturity_year) : Animal(name, no_of_feet, type_of_skin){
    this->no_of_mammal_glands = no_of_mammal_glands;
    this->reproductive_maturity_year = reproductive_maturity_year;
}


Mammal::Mammal(const Mammal& copy) : Animal(copy){
    this->no_of_mammal_glands = copy.no_of_mammal_glands;
    this->reproductive_maturity_year = copy.reproductive_maturity_year;
}


Mammal& Mammal::operator=(const Mammal& copy){
    if(this != &copy){
        Animal::operator=(copy);
        this->no_of_mammal_glands = copy.no_of_mammal_glands;
        this->reproductive_maturity_year = copy.reproductive_maturity_year;
    }

    return *this;
}  


Mammal Mammal::operator + (Mammal copy){

    copy.name = copy.name + "-" +this->name;
    copy.no_of_feet = max(this->no_of_feet, copy.no_of_feet);
    copy.no_of_mammal_glands = this->no_of_mammal_glands + copy.no_of_mammal_glands;
    copy.reproductive_maturity_year = min(copy.reproductive_maturity_year, this->reproductive_maturity_year);

    return copy;

}


istream& operator>>(istream& in, Mammal& copy){
    in >> (Animal&)copy;
    cout << "Mammal Read: " << endl;
    cout << "Number of mammal glands: ";
    in >> copy.no_of_mammal_glands;
    cout << "Reproductive maturity year: ";
    in >> copy.reproductive_maturity_year;

    return in;
}


ostream& operator<<(ostream& out, Mammal& copy){
    out << (Animal&)copy;
    out << "Mammal Info: " << endl;
    cout << "Number of mammal glands: " << copy.no_of_mammal_glands << endl;
    cout << "Reproductive maturity year: " << copy.reproductive_maturity_year << endl;

    return out;
}


void Mammal::make_sound(){
    cout << "GRHHHHH" << endl;
}


void Mammal::multiply(vector<Animal*> animals){

    Mammal* mammal = new Mammal;

    for(int i = 0; i < rand() % this->no_of_mammal_glands; i++){

        *mammal = Mammal(this->name + "-" + to_string(i), this->no_of_feet, this->type_of_skin,rand() % 10, rand() % 30);
        animals.push_back((Animal*) mammal);
        mammal = new Mammal;
    }
}


//////////////////////////////////////////////////////////////////////


Reptile::Reptile() : Animal(){
    this->is_venomous = false;
}


Reptile::Reptile(string name, int no_of_feet, Skin type_of_skin, bool is_venomous) 
    : Animal(name, no_of_feet, type_of_skin){
        this->is_venomous = is_venomous;
}


Reptile::Reptile(const Reptile& copy) : Animal(copy){
    this->is_venomous = copy.is_venomous;
}


Reptile& Reptile::operator=(const Reptile& copy){

    if(this != &copy){
        Animal::operator=(copy);
        this->is_venomous = copy.is_venomous;
    }

    return *this;
}


Reptile Reptile::operator + (Reptile copy){

    copy.name = this->name + '-' + copy.name;
    copy.no_of_feet = max(this->no_of_feet, copy.no_of_feet);
    copy.is_venomous = copy.is_venomous || this->is_venomous;

    return copy;
}


istream& operator >> (istream& in, Reptile& copy){
    in >> (Animal&)copy;
    cout << "Is venomous(1/0): ";
    in >> copy.is_venomous;

    return in;
}


ostream& operator << (ostream& out, const Reptile& copy){
    out << (Animal&)copy;
    out << "is venomous: " << copy.is_venomous << endl;

    return out;
}


void Reptile::make_sound(){
    cout << "SPRHHHH" << endl;
}


void Reptile::multiply(vector<Animal*> animals){

    Reptile* reptile = new Reptile;

    for(int i = 0; i < rand() % 12; i++){

        *reptile = Reptile(this->name + "-" + to_string(i), this->no_of_feet, this->type_of_skin, this->is_venomous);
        animals.push_back((Animal*) reptile);
        reptile = new Reptile;
    }
}


//////////////////////////////////////////////////////////////////////


Archaeopteryx::Archaeopteryx() : Animal(), Bird(), Reptile() {

}


Archaeopteryx::Archaeopteryx(string name, int no_of_feet, Skin type_of_skin, 
            Color wing_color, int no_of_eggs, bool is_venomous) 
            : Animal(name, no_of_feet, type_of_skin), Bird(name, no_of_feet, type_of_skin, wing_color, no_of_eggs),
              Reptile(name, no_of_feet, type_of_skin, is_venomous) {

}


Archaeopteryx::Archaeopteryx(const Archaeopteryx& copy) : Animal(copy), Bird(copy), Reptile(copy){

}


Archaeopteryx::Archaeopteryx(const Bird& copy) : Animal(copy), Bird(copy){

    this->is_venomous = false;

}


Archaeopteryx& Archaeopteryx::operator=(const Archaeopteryx& copy){
    
    if(this != &copy){
        Bird::operator=(copy);
        Reptile::operator=(copy);
    }

    return *this;
}


Archaeopteryx Archaeopteryx::operator + (Archaeopteryx copy){

    copy.name = copy.name + "-" + this->name;
    copy.no_of_eggs = this->no_of_eggs + copy.no_of_eggs;
    copy.is_venomous = this->is_venomous || copy.is_venomous;

    return copy;
}


istream& operator >> (istream& in, Archaeopteryx& copy){

    in >> (Animal&)copy;

    // Bird

    cout << "Number of eggs: ";
    in >> copy.no_of_eggs;

    read:cout << "Color (red/green/blue/purple/white): ";
    char aux[30];
    in >> aux;
    if(strcmp(aux, "red") == 0)
        copy.wing_color = Color::Red;
    else if(strcmp(aux, "blue") == 0)
        copy.wing_color = Color::Blue;
    else if(strcmp(aux, "green") == 0)
        copy.wing_color = Color::Green;
    else if(strcmp(aux, "purple") == 0)
        copy.wing_color = Color::Purple;
    else if(strcmp(aux, "white") == 0)
        copy.wing_color = Color::White;
    else
        goto read;

    // Reptile

    cout << "Is venomous(1/0): ";
    in >> copy.is_venomous;

    return in;

}


ostream& operator << (ostream& out, const Archaeopteryx& copy){

    out << (Animal&)copy;

    // Bird
    
    out << "Number of eggs: " << copy.no_of_eggs << endl;

    out << "Wing color: ";
    if(copy.wing_color == Color::Blue)
        out << "blue";
    else if(copy.wing_color == Color::Red)
        out << "red";
    else if(copy.wing_color == Color::White)
        out << "white";
    else if(copy.wing_color == Color::Green)
        out << "green";
    else if(copy.wing_color == Color::Purple)
        out << "purple";
    else
        out << "none";

    // Reptile

    out << "is venomous: " << copy.is_venomous << endl;

    return out;
}


void Archaeopteryx::make_sound(){
    cout << "AHHH" << endl;
}


void Archaeopteryx::multiply(vector<Animal*> animals){

    Archaeopteryx* archaeopteryx = new Archaeopteryx;

    for(int i = 0; i < rand() % this->no_of_eggs; i++){

        *archaeopteryx = Archaeopteryx(this->name + "-" + to_string(i), this->no_of_feet, this->type_of_skin, Color::Red, rand() % this->no_of_eggs, this->is_venomous);
        animals.push_back((Animal*) archaeopteryx);
        archaeopteryx = new Archaeopteryx;
    }
}


//////////////////////////////////////////////////////////////////////


void menu(){

    vector<Animal*> animals;
    
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


int main(){

    
    // Bird a("vultur", 2, Skin::Feathers, Color::Red, 3);
    // Reptile* r = new Reptile("sarpe", 0, Skin::Scales, 1);
    // cout << (*r) + (*r) << endl;
    // // Bird b("papagal", 3, Skin::Feathers, Color::Red, 5);
    // // Archaeopteryx c(a);
    // // cout << c;
    // Archaeopteryx* c = new Archaeopteryx(a);
    // (*c).set_is_venomous((*r).get_is_venomous());
    // cout << *c;
    // cout << a + b << endl;


    menu();

    return 0;
}