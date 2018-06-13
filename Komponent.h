#ifndef  identyfikator
#define identyfikator  
#include <vector>
#include <cstdio>
#include <memory>
#include <iostream>
#include <cstdlib>
class Visitator;

class Komponent
{
    public:
        virtual ~Komponent();
        virtual bool operacja() = 0;
        virtual void Accept( Visitator *v) = 0;
        virtual std::vector<std::shared_ptr<Komponent>> getVector() = 0; 
        virtual void setVectorValue( int index , bool value) = 0;
        virtual bool sprawdzCzyJestemLisciem() = 0;
        virtual std::shared_ptr<Komponent>  Klonuj() = 0;
        virtual std::ostream& print(std::ostream &wyjscie) = 0;
        virtual std::ostream& wyswietlWynikOperacji();
};

#endif