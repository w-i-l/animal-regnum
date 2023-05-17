#ifndef CORRAL_FILE_INCLUDED
#define CORRAL_FILE_INCLUDED

#include <vector>

using namespace std;

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

#endif