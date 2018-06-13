#include "BramkaNot.h"

BramkaNot::BramkaNot(std::shared_ptr<Komponent> a)
{
    wartosci.push_back(a);
};
bool BramkaNot::operacja()
{
    return ! this->wartosci[0]->operacja(); //dostajemy sie do Liscia, operacja dla Liscia zwraca wartosc bool
};
void BramkaNot::Accept( Visitator *v)
{
    v->operacja(this);
}
std::vector<std::shared_ptr<Komponent>> BramkaNot::getVector(){
    return this->wartosci;
}; 
void BramkaNot::setVectorValue(int index, bool value ){
    this->wartosci[index]->setVectorValue(0,value);
}
bool BramkaNot::sprawdzCzyJestemLisciem()
{
 return false;
}
std::shared_ptr<Komponent> BramkaNot::Klonuj()
{
  return std::make_shared<BramkaNot>(wartosci[0]->Klonuj());
}
std::ostream& BramkaNot::print(std::ostream & wyjscie)
{
   wyjscie<<"[BramkaNot(";
   wartosci[0]->print(wyjscie);
   wyjscie<<")]";
   return wyjscie;
}