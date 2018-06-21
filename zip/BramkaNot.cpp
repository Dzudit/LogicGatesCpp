#include "BramkaNot.h"

BramkaNot::BramkaNot()
{
}
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
void BramkaNot::dodajDoKompozycji(std::shared_ptr<Komponent> komp)
{
 wartosci.push_back(komp);
}
std::shared_ptr<Komponent> BramkaNot::Klonuj()
{
  auto klon = std::make_shared<BramkaNot>();

  if (!wartosci.empty())
  {
   klon->dodajDoKompozycji(wartosci[0]->Klonuj());
  }
  return klon;
}
std::ostream& BramkaNot::print(std::ostream & wyjscie)
{
   wyjscie<<"[BramkaNot(";
   wartosci[0]->print(wyjscie);
   wyjscie<<")]";
   return wyjscie;
}