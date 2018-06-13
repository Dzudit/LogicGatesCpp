#include "Kompozyt.h"

Kompozyt::Kompozyt()
{
}
bool Kompozyt::operacja()
{
    return true;
}
void Kompozyt::dodajDoKompozycji(std::shared_ptr<Komponent> komp)
{
   bramki.push_back(komp);
}
void Kompozyt::Accept( Visitator *v)
{
   v->operacja(this);
}
std::vector<std::shared_ptr<Komponent>> Kompozyt::getVector()
{
    return bramki; 
} 
void Kompozyt::setVectorValue(int index, bool value){
    this->bramki[index]->setVectorValue(index, value);
}
bool Kompozyt::sprawdzCzyJestemLisciem()
{
    return false;
}
std::shared_ptr<Komponent> Kompozyt::Klonuj()
{
  auto klon = std::make_shared<Kompozyt>();
    
    if(!wartosci.empty())
    {
        for( size_t i = 0; i < wartosci.size(); i++ )
        {             
                klon->dodajDoKompozycji(wartosci[i]->Klonuj());    
        }
    
    }
    return klon;

}
std::ostream& Kompozyt::print(std::ostream &wyjscie)
{
    wyjscie<<"(Kompozyt";

    if(!wartosci.empty())
    {
        for( size_t i = 0; i < wartosci.size(); i++ )
        {
            wartosci[i]->print(wyjscie);
            if(i<wartosci.size()-1)
            {
                wyjscie<<",";
            }
        }
    }
   wyjscie<<" -> ["<<operacja()<<"])";
   return wyjscie;
}