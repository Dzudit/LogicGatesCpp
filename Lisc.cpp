#include "Lisc.h"
#include <iostream>

Lisc::Lisc(bool value):q(value)
{
  wartosci.push_back(nullptr);
};
bool Lisc::operacja() 
{
  return q;
};
void Lisc::Accept( Visitator *v)
{
  v->operacja(this);
}
std::vector<std::shared_ptr<Komponent>> Lisc::getVector()
{
  return wartosci;
}; 
void Lisc::setVectorValue(int i, bool value){
    q=value;
}
bool Lisc::sprawdzCzyJestemLisciem()
{
    return true;
}
std::shared_ptr<Komponent> Lisc::Klonuj()
{
  return std::make_shared<Lisc>(operacja());
}
std::ostream& Lisc::print(std::ostream &wyjscie)
{
    return wyjscie<<"{"<<q<<"}";
}
