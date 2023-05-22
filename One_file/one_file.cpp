#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <map>
#include <string>
#include <windows.h>
#include <exception>
#include <set>
#include <list>


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


class FileNotFound : public exception{
    public:
        virtual const char* what() const throw(){
            return "File not found";
        }
};


class InvalidOption : public exception{
    public:
        virtual const char* what() const throw(){
            return "Invalid option";
        }
};


class AuthFailed: public exception{
    public:
        const char* what() const throw(){
            return "Authentication failed! Contact the admin for more details.";
        }
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
        void write_to_file(string filename) throw(FileNotFound);
        void read_from_line(string line);

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
        template<typename Return, typename T>
        Return operator+(const T& copy);

        // friend
        friend istream& operator>>(istream& in, Bird& copy);
        friend ostream& operator<<(ostream& out, const Bird& copy);

        // virtual
        void make_sound();
        void multiply(vector<Animal*> animals);
        void write_to_file(string filename) throw(FileNotFound);
        void read_from_line(string line);


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
        void write_to_file(string filename) throw(FileNotFound);
        void read_from_line(string line);

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
        template<typename Return, typename T>
        Return operator+(const T& copy);

        // friends
        friend istream& operator >> (istream& in, Reptile& copy);
        friend ostream& operator << (ostream& out, const Reptile& copy);

        // virtual
        void make_sound();
        void multiply(vector<Animal*> animals);
        void write_to_file(string filename) throw(FileNotFound);
        void read_from_line(string line);


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
        void write_to_file(string filename) throw(FileNotFound);
        void read_from_line(string line);

};



template<class T_animal>
class Corral{

    private:
        vector<T_animal*> animals;
        string corral_name;

    public:

        // constructor
        Corral();
        Corral(string corral_name, vector<T_animal*> animals);
        Corral(const Corral&);

        // destructor
        // ~Corral();

        // getters
        vector<T_animal*> get_animals() const { return this->animals; }
        string get_corral_name() const { return this->corral_name; }

        // setters
        void set_animals(vector<T_animal*> animals) { this->animals = animals; }
        void set_corral_name(string corral_name) { this->corral_name = corral_name; }

        // operators
        Corral& operator=(const Corral&);
        T_animal* operator[](int index) const;
        Corral& operator+=(T_animal* animal);
        Corral operator+(Corral copy);

        // friend operators
        template<class T>
        friend ostream& operator<<(ostream&, const Corral<T>&);
        template<class T>
        friend istream& operator>>(istream&, Corral<T>&);

        // methods
        void add_animal(T_animal* animal);
        void remove_animal(T_animal* animal);
        size_t size() const;

        // friend
        template<class T>
        friend void operator+=(Corral<T>&, T*);

};


class Menu{
    private:

        // admin
        string admin_username;
        string admin_password;

        static Menu* instance;
        vector<Animal*> animals;
        map<string, set<string>> parties;
        vector<Corral<Mammal>*> mammal_corral;

        // constructor
        Menu();
        Menu(const Menu&);
        Menu& operator=(const Menu&);

        // destructor
        ~Menu();

        // aux methods
        int select_species(string text_to_display) throw(InvalidOption);
        template<typename T>
        int select_animal_from_species(T species);
        string select_species_from(list<string> species) throw (InvalidOption);

        string get_type_of_animal(string name);
        string get_name_of_class_from_typid_name(string name);

        // main methods
        void read_from_file(string filename, bool append_to_vector) throw(FileNotFound);
        void write_to_file(string filename, bool append);

        void display_animals_names();
        void display_animal_info();

        void delete_animals();
        void add_animal();
        void remove_animal();

        void breed_animals();
        
        void display_parties();
        void add_party(string hour, string host) throw(InvalidOption);
        void remove_party(string hour) throw(InvalidOption);
        void add_guest(string hour, string guest) throw(InvalidOption);
        void remove_guest(string hour, string guest) throw(InvalidOption);
        
        // corral
        void display_corrals();
        void display_animals_from_corral();
        void add_animal_to_corral();
        void remove_animal_from_corral();
        void create_corral();
        void remove_corral();


        // binary files
        void save_parties_to_file(string filename) throw(FileNotFound);
        void read_parties_from_file(string filename) throw(FileNotFound);

        // corral menu
        int get_option_for_corral() throw(InvalidOption);
        void corral_menu();

        // menu

        int get_option_for_admin() throw(InvalidOption);
        int get_option_for_user() throw (InvalidOption);

        void admin_auth() throw(AuthFailed);
        void admin_menu();
        void user_menu();

    public:

        static Menu* get_instance();

        void run();
        
};




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

    try{

        cout << "Number of feet: ";
        in >> copy.no_of_feet;

        if(copy.no_of_feet < 0){
            throw InvalidOption();
        }
    }
    catch(InvalidOption& e){

        while(copy.no_of_feet < 0){
            cout << endl << e.what() << endl;
            
            cout << "Please provide a number greater than 0!" << endl;
            cout << "Number of feet: ";
            in >> copy.no_of_feet;
        }
    }

    
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


// we write the Animal info separrated by spaces
// on the same line, and we end the file with " "
void Animal::write_to_file(string filename) throw(FileNotFound){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // we write the name, number of feet and type of skin
    // on the same line separrated by spaces

    file << this->name << " " << this->no_of_feet << " ";

    if(this->type_of_skin == Skin::Fur){
        file << "fur";
    }
    else if(this->type_of_skin == Skin::Leather){
        file << "leather";
    }
    else if(this->type_of_skin == Skin::Scales){
        file << "scales";
    }
    else if(this->type_of_skin == Skin::Feathers){
        file << "feathers";
    }
    else{
        file << "none";
    }

    file << " ";
}


void Animal::read_from_line(string line){
    // we read the name, number of feet and type of skin
    // from the same line separrated by spaces

    char aux[30];
    strcpy(aux, line.c_str());
    char* token = strtok(aux, " ");
    this->name = token;
    token = strtok(NULL, " ");
    this->no_of_feet = atoi(token);
    token = strtok(NULL, " ");

    if (strcmp(token, "fur") == 0)
        this->type_of_skin = Skin::Fur;
    else if (strcmp(token, "leather") == 0)
        this->type_of_skin = Skin::Leather;
    else if (strcmp(token, "scales") == 0)
        this->type_of_skin = Skin::Scales;
    else if (strcmp(token, "feathers") == 0)
        this->type_of_skin = Skin::Feathers;
    else
        this->type_of_skin = Skin::None;
}


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

    try{
    
        cout << "Number of eggs: ";
        in >> copy.no_of_eggs;
    
        if(copy.no_of_eggs < 0){
            throw InvalidOption();
        }
    }
    catch(InvalidOption& e){
    
        while(copy.no_of_eggs < 0){

            cout << endl << e.what() << endl;

            cout << "Please provide a number of eggs greater than 0!" << endl;
            cout << "Number of eggs: ";
            in >> copy.no_of_eggs;
        }
    }

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


void Bird::write_to_file(string filename) throw(FileNotFound){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // Animal info
    Animal::write_to_file(filename);

    // we write the bird traits separated by a space
    // wing color, number of eggs

    if(this->wing_color == Color::Blue)
        file << "blue" << " ";
    else if(this->wing_color == Color::Red)
        file << "red" << " ";
    else if(this->wing_color == Color::White)
        file << "white" << " ";
    else if(this->wing_color == Color::Green)
        file << "green" << " ";
    else if(this->wing_color == Color::Purple)
        file << "purple" << " ";
    else
        file << "none" << " ";

    file << no_of_eggs << " ";


}


void Bird::read_from_line(string line){
    
        // we read the animal info
        Animal::read_from_line(line);
    
        // we read the bird traits separated by a space
        // wing color, number of eggs
    
        char aux[30];
        strcpy(aux, line.c_str());
        // get the name
        char* token = strtok(aux, " ");
        // no of feet
        token = strtok(NULL, " ");
        // type of skin
        token = strtok(NULL, " ");

    
        token = strtok(NULL, " ");
        if(strcmp(token, "red") == 0)
            this->wing_color = Color::Red;
        else if(strcmp(token, "blue") == 0)
            this->wing_color = Color::Blue;
        else if(strcmp(token, "green") == 0)
            this->wing_color = Color::Green;
        else if(strcmp(token, "purple") == 0)
            this->wing_color = Color::Purple;
        else if(strcmp(token, "white") == 0)
            this->wing_color = Color::White;
        else
            this->wing_color = Color::None;
    
        token = strtok(NULL, " ");
        this->no_of_eggs = atoi(token);
}


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

    try{

        cout << "Number of mammal glands: ";
        in >> copy.no_of_mammal_glands;

        if(copy.no_of_mammal_glands < 0){
            throw InvalidOption();
        }
    }
    catch(InvalidOption& e){

        while(copy.no_of_mammal_glands < 0){
            cout << endl << e.what() << endl;
    
            cout << "Please provide a number greater than 0!" << endl;
            cout << "Number of mammal glands: ";
            in >> copy.no_of_mammal_glands;
        }
    }

    try{

        cout << "Reproductive maturity year: ";
        in >> copy.reproductive_maturity_year;

        if(copy.reproductive_maturity_year < 0){
            throw InvalidOption();
        }
    }
    catch(InvalidOption& e){

        while(copy.reproductive_maturity_year < 0){
            cout << endl << e.what() << endl;
    
            cout << "Please provide a number greater than 0!" << endl;
            cout << "Reproductive maturity year: ";
            in >> copy.reproductive_maturity_year;
        }
    }

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


void Mammal::write_to_file(string filename) throw(FileNotFound){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // Animal info
    Animal::write_to_file(filename);

    // we write the mammal info separated by a space
    // no_of_mammal_glands, reproductive_maturity_year
    file << this->no_of_mammal_glands << " " << this->reproductive_maturity_year << " ";
    

    file.close();

}


void Mammal::read_from_line(string line){
    
        // we read the animal info
        Animal::read_from_line(line);
    
        // we read the mammal info
        // no_of_mammal_glands, reproductive_maturity_year

        char aux[30];
        strcpy(aux, line.c_str());

        // get the name
        char* token = strtok(aux, " ");
        // no of feet
        token = strtok(NULL, " ");
        // type of skin
        token = strtok(NULL, " ");


        // no_of_mammal_glands
        token = strtok(NULL, " ");
        this->no_of_mammal_glands = atoi(token);

        // reproductive_maturity_year
        token = strtok(NULL, " ");
        this->reproductive_maturity_year = atoi(token);


}


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

    char venom;

    try{
        cout << "Is venomous(1/0): ";
        in >> venom;

        if(venom != '0' && venom != '1')
            throw InvalidOption();
        
        copy.is_venomous = venom - '0';
    }
    catch(InvalidOption& e){

        while(venom != '0' && venom != '1'){
            cout << endl << e.what() << endl;

            cout << "Please provide a valid option!" << endl;
            cout << "Is venomous(1/0): ";
            in >> venom;
        }

        copy.is_venomous = venom - '0';
    }

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


void Reptile::write_to_file(string filename) throw(FileNotFound){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // Animal info
    Animal::write_to_file(filename);

    // we write reptile info to file separated by a space
    // is_venomous
    file << this->is_venomous << " ";
    
}


void Reptile::read_from_line(string line){
        
     // we read the animal info
    Animal::read_from_line(line);

    // we read the mammal info
    // no_of_mammal_glands, reproductive_maturity_year

    char aux[30];
    strcpy(aux, line.c_str());

    // get the name
    char* token = strtok(aux, " ");
    // no of feet
    token = strtok(NULL, " ");
    // type of skin
    token = strtok(NULL, " ");

    // is venomous
    token = strtok(NULL, " ");
    this->is_venomous = atoi(token);

}


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

    try{
        cout << "Number of eggs: ";
        in >> copy.no_of_eggs;

        if(copy.no_of_eggs < 0)
            throw InvalidOption();
    }
    catch(InvalidOption& e){

        while(copy.no_of_eggs < 0){
            cout << endl << e.what() << endl;

            cout << "Please provide a number of eggs greater than 0!" << endl;
            cout << "Number of eggs: ";
            in >> copy.no_of_eggs;
        }
    }


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

    char venom;

    try{
        cout << "Is venomous(1/0): ";
        in >> venom;

        if(venom != '0' && venom != '1')
            throw InvalidOption();
        
        copy.is_venomous = venom - '0';
    }
    catch(InvalidOption& e){

        while(venom != '0' && venom != '1'){
            cout << endl << e.what() << endl;

            cout << "Please provide a valid option!" << endl;
            cout << "Is venomous(1/0): ";
            in >> venom;
        }

        copy.is_venomous = venom - '0';
    }

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


void Archaeopteryx::write_to_file(string filename) throw(FileNotFound){

    ofstream file(filename, ios::app);

    if(file.is_open() == false){
        throw FileNotFound();
    }

    // Bird info
    Bird::write_to_file(filename);

    // Reptile info
    file << this->is_venomous << " ";

}


void Archaeopteryx::read_from_line(string line){

     // we read the bird info
    Bird::read_from_line(line);


    // we read the reptile info

    char aux[30];
    strcpy(aux, line.c_str());

    // get the name
    char* token = strtok(aux, " ");
    // no of feet
    token = strtok(NULL, " ");
    // type of skin
    token = strtok(NULL, " ");
    // wing color
    token = strtok(NULL, " ");
    // no of eggs
    token = strtok(NULL, " ");

    // is venomous
    token = strtok(NULL, " ");
    this->is_venomous = atoi(token) == 1 ? "true" : "false";

}


template<>
Archaeopteryx Bird::operator+(const Reptile& copy){
    
        Archaeopteryx archaeopteryx;
    
        archaeopteryx.name = this->name + "-" + copy.get_name();
        archaeopteryx.no_of_feet = this->no_of_feet + copy.get_no_of_feet();
        archaeopteryx.type_of_skin = this->type_of_skin;
        archaeopteryx.wing_color = this->wing_color;
        archaeopteryx.no_of_eggs = this->no_of_eggs;
        archaeopteryx.set_is_venomous(copy.get_is_venomous());

    
        return archaeopteryx;
}


template<>
Archaeopteryx Reptile::operator+(const Bird& copy){
    
        Archaeopteryx archaeopteryx;
    
        archaeopteryx.name = this->name + "-" + copy.get_name();
        archaeopteryx.no_of_feet = this->no_of_feet + copy.get_no_of_feet();
        archaeopteryx.type_of_skin = this->type_of_skin;
        archaeopteryx.set_wing_color(copy.get_wing_color());
        archaeopteryx.set_no_of_eggs(copy.get_no_of_eggs());
        archaeopteryx.set_is_venomous(this->is_venomous);

    
        return archaeopteryx;
}



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

    Corral<Mammal>* corral = new Corral<Mammal>;

    *corral = Corral<Mammal>("beer-corral", {dynamic_cast<Mammal*>(animals[4])});
    mammal_corral.push_back(corral);


    corral = new Corral<Mammal>;
    *corral = Corral<Mammal>("forest-corral", {dynamic_cast<Mammal*>(animals[5])});
    mammal_corral.push_back(corral);


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


void Menu::read_from_file(string filename, bool append_to_vector) throw (FileNotFound){

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
int Menu::select_species(string text_to_display) throw (InvalidOption){

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
// throws InvalidOption and catch itself the error
template <typename T>
int Menu::select_animal_from_species(T species){

    int option;

    // we bind the displayed option to the index in the vector
    map<int, int> option_to_index;

    start_select_animal_from_species: try{
    
        option_to_index.clear();

        int index = 1;

        for(int i = 0; i < animals.size(); i++){
            if(typeid(*(animals[i])) == typeid(species)){
                cout << index << ". " << animals[i]->get_name() << endl;
                option_to_index[index] = i;
                index ++;
            }
        }


        cout << endl << "Enter an option: ";
        cin >> option;
        cout << endl;

        if(option < 1 || option >= index){
            throw InvalidOption();
        }
    }
    catch(InvalidOption& e){
        cout << endl << e.what() << endl;
        cout << "Please provide a valid option!" << endl;
        goto start_select_animal_from_species;
    }

    return option_to_index[option];

}


void Menu::add_animal(){

    int species;
    
    try{
        species = select_species("add");
    }
    catch(InvalidOption& e){
        
        while(true){
            cout << endl << e.what() << endl;

            cout << "Please provide a valid option!" << endl;
            
            try{
                species = select_species("add");
                break;
            }
            catch(InvalidOption& e){
                continue;
            }
        }
    }

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

    int species;
    
    try{
        species = select_species("remove");
    } 
    catch(InvalidOption& e){
        
        while(true){
            cout << endl << e.what() << endl;

            cout << "Please provide a valid option!" << endl;
            
            try{
                species = select_species("remove");
                break;
            }
            catch(InvalidOption& e){
                continue;
            }
        }
    }
        
    
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
string Menu::select_species_from(list<string> species) throw (InvalidOption){

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

    int first_species;
    try{
        first_species = select_species("breed");
    } 
    catch(InvalidOption& e){

        while(true){
            cout << endl << e.what() << endl;

            cout << "Please provide a valid option!" << endl;
            
            try{
                first_species = select_species("breed");
                break;
            }
            catch(InvalidOption& e){
                continue;
            }
        }
    }

    map<int, list<string>> species_to_list_of_species;

    species_to_list_of_species[1] = {"Bird", "Reptile"};
    species_to_list_of_species[2] = {"Reptile", "Bird"};
    species_to_list_of_species[3] = {"Mammal"};
    species_to_list_of_species[4] = {"Archaeopteryx"};

    string second_species_name;
    
    try{
     second_species_name = select_species_from(species_to_list_of_species[first_species]);
    }
    catch(InvalidOption& e){

        while(true){
            cout << endl << e.what() << endl;

            cout << "Please provide a valid option!" << endl;
            
            try{
                second_species_name = select_species_from(species_to_list_of_species[first_species]);
                break;
            }
            catch(InvalidOption& e){
                continue;
            }
        }
    }

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

    int selected_species;
    try{
        selected_species = select_species("display info");
    }
    catch(InvalidOption& e){
        while(true){
            cout << endl << e.what() << endl;

            cout << "Please provide a valid option!" << endl;
            
            try{
                selected_species = select_species("display info");
                break;
            }
            catch(InvalidOption& e){
                continue;
            }
        }
    }
    
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


void Menu::display_parties(){
    
        cout << "Parties:" << endl;

        for(auto it = parties.begin(); it != parties.end(); it++){

            if(it->second.size() == 0){
                continue;
            }
    
            cout << "Hour: " << it->first << endl;
    
            for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
                cout << *it2 << endl;
            }
    
            cout << endl;
        }
    
        cout << endl;
}


bool is_hour_valid(string hour) {
    if (hour[0] >= '0' && hour[0] < '3') {
        if ((hour[1] >= '0' && hour[1] <= '9' && (hour[0] == '1' || hour[0] == '0'))
            || (hour[1] >= '0' && hour[1] < '4' && hour[0] == '2')) {
            if (hour[2] == ':') {
                if (hour[3] >= '0' && hour[3] <= '5' && hour[4] >= '0' && hour[4] <= '9') {
                    return true;
                }
            }
        }
    }
    return false;
}


// throws InvalidOption if the hour is not in the correct format
void Menu::add_party(string hour, string host) throw(InvalidOption){

    if(is_hour_valid(hour) && parties.find(hour) == parties.end() && hour.size() == 5 && hour[2] == ':' ){
        parties[hour] = {host};
        cout << endl << "Created party at " << hour << " hosted by " << host << endl << endl;
    }
    else{

        if(parties.find(hour) != parties.end()){
            cout << endl << "There is already a party at this hour!" << endl << endl;
        }
        else{
            throw InvalidOption();
        }
    }

    
}


// throws InvalidOption if the party doesnt exist
void Menu::remove_party(string hour) throw(InvalidOption){

    if(is_hour_valid(hour) && parties.find(hour) != parties.end()){
        parties.erase(hour);
        cout << endl << "Party at " << hour << " has been removed!" << endl << endl;
    }
    else{
        throw InvalidOption();
    }

}


void Menu::add_guest(string hour, string guest) throw(InvalidOption){

    if(is_hour_valid(hour) && parties.find(hour) != parties.end()){
        parties[hour].insert(guest);
        cout << endl << "Guest " << guest << " has been added to the party at " << hour << endl << endl;
    }
    else{
        throw InvalidOption();
    }

}


void Menu::remove_guest(string hour, string guest) throw(InvalidOption){

    if(is_hour_valid(hour) && parties.find(hour) != parties.end()){
        parties[hour].erase(guest);
        cout << endl << "Guest " << guest << " has been removed from the party at " << hour << endl << endl;
    }
    else{
        throw InvalidOption();
    }

}


// saves the parties to a binary file
void Menu::save_parties_to_file(string filename) throw(FileNotFound){

    ofstream file(filename, ios::binary);

    if (file.is_open()) {
        for (const auto& party : parties) {
            // Write hour
            file.write(party.first.c_str(), party.first.size() + 1);

            // Write number of guests
            int number_of_guests = party.second.size();
            file.write(reinterpret_cast<char*>(&number_of_guests), sizeof(number_of_guests));

            // Write guests
            for (const auto& guest : party.second) {
                file.write(guest.c_str(), guest.size() + 1);
            }
        }
        file.close();
    }
    else{
        throw FileNotFound();
    }


}


// reads the parties from a binary file
void Menu::read_parties_from_file(string filename) throw(FileNotFound){

    ifstream file(filename, ios::binary);

    if (file.is_open()) {
        while (!file.eof()) {
            string hour;
            int number_of_guests;

            // Read hour
            getline(file, hour, '\0');

            // Read number of guests
            file.read(reinterpret_cast<char*>(&number_of_guests), sizeof(number_of_guests));

            // Read guests
            for (int i = 0; i < number_of_guests; i++) {
                string guest;
                getline(file, guest, '\0');
                parties[hour].insert(guest);
            }
        }
        file.close();
    }
    else{
        throw FileNotFound();
    }

}


// throws AuthFailed if cant login as admin
void Menu::admin_auth() throw(AuthFailed){
    
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


int Menu::get_option_for_user() throw (InvalidOption){

    cout << endl << "=== User === Menu ===" << endl << endl;
    cout << "1. Display all animlas" << endl;
    cout << "2. Select an animal" << endl;
    cout << "3. Create a party" << endl;
    cout << "4. Remove a party" << endl;
    cout << "5. Add a guest to a party" << endl;
    cout << "6. Remove a guest from a party" << endl;
    cout << "7. Display all parties" << endl;
    cout << "8. Log out" << endl;
    cout << "0. Exit the application" << endl;

    int option;
    cout << endl << "Enter an option: ";
    cin >> option;

    if(option < 0 || option >= 9){
        throw InvalidOption();
    }

    return option;
}


void Menu::user_menu(){

    cout << "Loading parties" << endl;
    for(int i = 0; i < 10; i++){
        Sleep(100);
        cout << ".";
    }
    cout << endl << "Done" << endl << endl;

    read_parties_from_file("parties.bin");

    while(true){
        int option;
        try{
            option = get_option_for_user();
        } 
        catch(InvalidOption& e){
            while(true){
                cout << e.what() << endl;

                try{
                    option = get_option_for_user();
                    break;
                }
                catch(InvalidOption& e){
                    continue;
                }
            }
        }

        system("cls");

        if(option == 1){
            display_animals_names();
        }

        else if(option == 2){
            display_animal_info();
        }

        else if(option == 3){

            string name;
            cout << "What is your name?: ";
            cin >> name;
            cout << endl;

            string hour;
            cout << "Enter the starting hour of the party(HH:MM): ";
            cin >> hour;
            cout << endl;

            try{
                add_party(hour, name);
            }
            catch(InvalidOption& e){

                while(true){

                    cout << e.what() << endl;

                    cout << "Please provide a valid hour(HH:MM)!";
                    cout << "Enter the starting hour of the party(HH:MM): ";
                    cin >> hour;
                    cout << endl;

                    try{
                        add_party(hour, name);
                        break;
                    }
                    catch(InvalidOption& e){
                        continue;
                    }
                }
            }

        }
        
        else if(option == 4){

            string name, hour;

            cout << "What is your name?: ";
            cin >> name;
            cout << endl;

            cout << "Enter the starting hour of the party(HH:MM): ";
            cin >> hour;
            cout << endl;

            try{

                if( parties[hour].find(name) != parties[hour].end()){
                    remove_party(hour);
                }
                else{
                    cout << "You are not the host of this party!" << endl;
                }
            }
            catch(InvalidOption& e){

                cout << hour << " " << is_hour_valid(hour) << endl;

                while(true){

                    cout << e.what() << endl;

                    cout << "Please provide a valid hour(HH:MM)!";
                    cout << "Enter the starting hour of the party(HH:MM): ";
                    cin >> hour;
                    cout << endl;

                    try{
                        remove_party(hour);
                        break;
                    }
                    catch(InvalidOption& e){
                        continue;
                    }
                }
            }

        }

        else if(option == 5){

            string name, hour;

            cout << "What is your name?: ";
            cin >> name;
            cout << endl;

            cout << "Enter the starting hour of the party(HH:MM): ";
            cin >> hour;
            cout << endl;

            if( parties[hour].find(name) != parties[hour].end()){
                string guest;
                cout << "Enter the name of the guest: ";
                cin >> guest;
                cout << endl;

                try{
                    add_guest(hour, guest);
                }
                catch(InvalidOption& e){

                    while(true){

                        cout << e.what() << endl;

                        cout << "Please provide a valid hour(HH:MM)!";
                        cout << "Enter the starting hour of the party(HH:MM): ";
                        cin >> hour;
                        cout << endl;

                        try{
                            add_guest(hour, guest);
                            break;
                        }
                        catch(InvalidOption& e){
                            continue;
                        }
                    }
                }
            }
            else{
                cout << "You are not the host of this party!" << endl;
            }
        }

        else if(option == 6){
                
            string name, hour;

            cout << "What is your name?: ";
            cin >> name;
            cout << endl;

            cout << "Enter the starting hour of the party(HH:MM): ";
            cin >> hour;
            cout << endl;

            if( parties[hour].find(name) != parties[hour].end()){
                string guest;
                cout << "Enter the name of the guest: ";
                cin >> guest;
                cout << endl;

                try{
                    remove_guest(hour, guest);
                }
                catch(InvalidOption& e){

                    while(true){

                        cout << e.what() << endl;

                        cout << "Please provide a valid hour(HH:MM)!";
                        cout << "Enter the starting hour of the party(HH:MM): ";
                        cin >> hour;
                        cout << endl;

                        try{
                            remove_guest(hour, guest);
                            break;
                        }
                        catch(InvalidOption& e){
                            continue;
                        }
                    }
                }
            }
            else{
                cout << "You are not the host of this party!" << endl;
            }
            }

        else if(option == 7){
            display_parties();
        }

        else if(option == 8){

            char c;

            cout << "Do you want to save the progress?(y/n): ";
            cin >> c;

            if(c == 'y' || c == 'Y'){
                save_parties_to_file("parties.bin");
                cout << "Progress saved!" << endl;
            }

            return;
        }

        else if(option == 0){
            
            char c;

            cout << "Do you want to save the progress?(y/n): ";
            cin >> c;

            if(c == 'y' || c == 'Y'){
                save_parties_to_file("parties.bin");
                cout << "Progress saved!" << endl;
            }

            exit(0);
        }
    }

}


void Menu::display_corrals(){
    
        cout << "Corrals:" << endl;
        
        for(int i = 0; i < mammal_corral.size(); i++){
            cout << i + 1 << ". " << mammal_corral[i]->get_corral_name() << endl;
        }

        cout << endl;
}


void Menu::display_animals_from_corral(){

    corral_read:int option;
    cout << "Choose a corral: " << endl;
    
    for(int i = 0; i < mammal_corral.size(); i++){
        cout << i + 1 << ". " << mammal_corral[i]->get_corral_name() << endl;
    }

    cout << endl << "Enter an option: ";
    cin >> option;
    cout << endl;

    if(option < 1 || option > mammal_corral.size()){
        cout << "Please provide a valid option!" << endl;
        goto corral_read;
    }

    option --;

    cout << "Animals from " << mammal_corral[option]->get_corral_name() << ":" << endl;

    for(int i = 0; i < mammal_corral[option]->get_animals().size(); i++){
        cout << i + 1 << ". " << mammal_corral[option]->get_animals()[i]->get_name() << endl;
    }

    cout << endl;

}


void Menu::add_animal_to_corral(){

    corral_read_2:int option;
    cout << "Choose a corral: " << endl;
    
    for(int i = 0; i < mammal_corral.size(); i++){
        cout << i + 1 << ". " << mammal_corral[i]->get_corral_name() << endl;
    }

    cout << endl << "Enter an option: ";
    cin >> option;
    cout << endl;

    if(option < 1 || option > mammal_corral.size()){
        cout << "Please provide a valid option!" << endl;
        goto corral_read_2;
    }

    Mammal* mammal = new Mammal;

    cin >> *mammal;

    mammal_corral[option]->add_animal(mammal);

    cout << "Animal added successfully!" << endl << endl;

}


void Menu::remove_animal_from_corral(){

    corral_read_3:int option;
    cout << "Choose a corral: " << endl;
    
    for(int i = 0; i < mammal_corral.size(); i++){
        cout << i + 1 << ". " << mammal_corral[i]->get_corral_name() << endl;
    }

    cout << endl << "Enter an option: ";
    cin >> option;
    cout << endl;

    if(option < 1 || option > mammal_corral.size()){
        cout << "Please provide a valid option!" << endl;
        goto corral_read_3;
    }

    option --;
    
    read_corral_4:int index = 1;

    for(int i = 0; i < mammal_corral[option]->get_animals().size(); i++){
        cout << index << ". " << mammal_corral[option]->get_animals()[i]->get_name() << endl;
        index ++;
    }

    cout << endl;

    cout << endl << "Enter an option: ";
    cin >> option;
    cout << endl;

    if(option < 1 || option > mammal_corral.size()){
        cout << "Please provide a valid option!" << endl;
        goto read_corral_4;
    }

    option --;

    mammal_corral[option]->remove_animal(*(mammal_corral[option]->get_animals().begin() + option));

    cout << "Animal removed successfully!" << endl << endl;

}


void Menu::create_corral(){

    Corral<Mammal>* corral = new Corral<Mammal>;

    cin >> *corral;

    mammal_corral.push_back(corral);

    cout << "Corral created successfully!" << endl << endl;

}


void Menu::remove_corral(){

    corral_read_5:int option;
    cout << "Choose a corral: " << endl;
    
    for(int i = 0; i < mammal_corral.size(); i++){
        cout << i + 1 << ". " << mammal_corral[i]->get_corral_name() << endl;
    }

    cout << endl << "Enter an option: ";
    cin >> option;
    cout << endl;

    if(option < 1 || option > mammal_corral.size()){
        cout << "Please provide a valid option!" << endl;
        goto corral_read_5;
    }

    option --;

    mammal_corral.erase(mammal_corral.begin() + option);

    cout << "Corral removed successfully!" << endl << endl;

}


int Menu::get_option_for_corral() throw (InvalidOption){

    cout << "::::Corral::::Menu::::" << endl << endl;

    cout << "[1] Display all corrals" << endl;
    cout << "[2] Select a corral" << endl;
    cout << "[3] Add an animal to a corral" << endl;
    cout << "[4] Remove an animal from a corral" << endl;
    cout << "[5] Create a new corral" << endl;
    cout << "[6] Remove a corral" << endl;
    cout << "[7] Log Out" << endl;
    cout << "[0] Exit the application" << endl;

    int option;
    cout << "Choose an option from above: ";
    cin >> option;
    cout << endl;

    if(option < 0 || option >= 8){
        throw InvalidOption();
    }

    return option;

}


void Menu::corral_menu(){

    while(true){

        int option;
        
        try{
            option = get_option_for_corral();
        }
        catch(InvalidOption& e){
            cout << endl << e.what() << endl;
            
            while(option < 0 || option >= 8){
                cout << "Choose an option from above: ";
                cin >> option;
                cout << endl;
            }
        }

        system("cls");

        if(option == 1){
            display_corrals();
        }

        else if(option == 2){
            display_animals_from_corral();
        }

        else if(option == 3){
            add_animal_to_corral();
        }

        else if(option == 4){
            remove_animal_from_corral();
        }

        else if(option == 5){
            create_corral();
        }

        else if(option == 6){
            remove_corral();
        }

        else if(option == 7){
            return;
        }

        else if(option == 0){
            exit(0);
        }
    }

}


int Menu::get_option_for_admin() throw (InvalidOption){

    cout << "::::Admin::::Menu::::" << endl << endl;

    cout << "[1] Add an animal" << endl;
    cout << "[2] Remove an animal" << endl;
    cout << "[3] Breed two animals" << endl;
    cout << "[4] Display all animals" << endl;
    cout << "[5] Select an animal" << endl;
    cout << "[6] Update the zoo from a file" << endl;
    cout << "[7] Save the zoo to a file" << endl;
    cout << "[8] Delete the zoo" << endl;
    cout << "[9] Corral Menu" << endl;
    cout << "[10] Log Out" << endl;
    cout << "[0] Exit the application" << endl;

    int option;
    cout << "Choose an option from above: ";
    cin >> option;
    cout << endl;

    if(option < 0 || option >= 11){
        throw InvalidOption();
    }

    return option;

}


void Menu::admin_menu(){

    while(true){

        int option;
        
        try{
            option = get_option_for_admin();
        }
        catch(InvalidOption& e){
            cout << endl << e.what() << endl;
            
            while(option < 0 || option >= 11){
                cout << "Choose an option from above: ";
                cin >> option;
                cout << endl;
            }
        }

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
            bool append = false;

            try{

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
            }
            catch(InvalidOption& e){
                while(append_to_vector != "y" && append_to_vector != "yes" && append_to_vector != "Y" && append_to_vector != "n" && append_to_vector != "no" && append_to_vector != "N"){
                    cout << endl << e.what() << endl;

                    cout << "Do you want to append to the existing animals?(y/n): ";
                    cin >> append_to_vector;
                    cout << endl;
                }

                if(append_to_vector == "y" || append_to_vector == "yes" || append_to_vector == "Y"){
                    append = true;
                }
            }

            try{
                read_from_file(filename, append);
            }
            catch(FileNotFound& e){
                cout << e.what() << endl;
                
                cout << "Last chance to enter the filename: ";
                cin >> filename;

                read_from_file(filename, append);
            }
        }

        else if(option == 7){
            string filename, append_to_vector;
            bool append = false;

            try{
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

            }
            catch(InvalidOption& e){
                while(append_to_vector != "y" && append_to_vector != "yes" && append_to_vector != "Y" && append_to_vector != "n" && append_to_vector != "no" && append_to_vector != "N"){
                    cout << endl << e.what() << endl;

                    cout << "Do you want to append to the existing animals from file?(y/n): ";
                    cin >> append_to_vector;
                }

                append = append_to_vector == "y" || append_to_vector == "yes" || append_to_vector == "Y";

            }

            try{
                write_to_file(filename, append);
            }
            catch(FileNotFound& e){

                cout << endl << e.what() << endl;

                cout << "Last chance to enter the filename: ";
                cin >> filename;

                write_to_file(filename, append);

            }

        }

        else if(option == 8){
            delete_animals();
        }

        else if(option == 9){
            corral_menu();
        }

        else if(option == 10){
                        
            char c;

            cout << "Do you want to save the progress?(y/n): ";
            cin >> c;

            if(c == 'y' || c == 'Y'){
                write_to_file("animals.txt", false);
                cout << "Progress saved!" << endl;
            }

            return;
        }

        else if (option == 0){

            char c;

            cout << "Do you want to save the progress?(y/n): ";
            cin >> c;

            if(c == 'y' || c == 'Y'){
                write_to_file("animals.txt", false);
                cout << "Progress saved!" << endl;
            }
            
            exit(0);
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


int main() {

    Menu* menu = Menu::get_instance();
    menu->run();

    return 0;
}