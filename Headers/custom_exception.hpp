#include <exception>

using namespace std;

#ifndef EXCEPTION_FILE_INCLUDED
#define EXCEPTION_FILE_INCLUDED


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

#endif