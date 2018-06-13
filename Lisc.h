#include "Komponent.h"
#include "Visitator.h"
#include <memory>
#include <iostream>
#include <cstdlib>

class Lisc : public Komponent
{
    private:   
        bool q; 
        std::vector<std::shared_ptr<Komponent>> wartosci;

    public:
        Lisc(bool value);
        bool operacja() override;
        void Accept( Visitator *v) override;
        std::vector<std::shared_ptr<Komponent>> getVector() override; 
        void setVectorValue(int index, bool value) override;
        bool sprawdzCzyJestemLisciem() override;
        std::shared_ptr<Komponent>  Klonuj() override;
        std::ostream& print(std::ostream &wyjscie) override;
};