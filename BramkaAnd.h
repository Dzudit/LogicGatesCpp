#include "Komponent.h"
#include "Visitator.h"
#include <memory>
#include <iostream>
#include <cstdlib>

class BramkaAnd : public Komponent
{
    private:
        std::vector<std::shared_ptr<Komponent>> wartosci;

    public:
        BramkaAnd();
        bool operacja() override;
        void dodajDoKompozycji(std::shared_ptr<Komponent> komp);
        void Accept( Visitator *v) override;
        std::vector<std::shared_ptr<Komponent>> getVector() override; 
        void setVectorValue(int index , bool value) override;
        bool sprawdzCzyJestemLisciem() override;
        std::shared_ptr<Komponent>  Klonuj() override;
        std::ostream& print(std::ostream &wyjscie) override;
};