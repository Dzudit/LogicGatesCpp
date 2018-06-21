#include "BramkaOr.h"

BramkaOr::BramkaOr()
{
}
bool BramkaOr::operacja()
{
    bool result = true;
    if(!wartosci.empty())
    {
        for( size_t i = 0; i < wartosci.size(); i++ )
        {
                result |= wartosci[i]->operacja();
        }    
    return result;
    }
    else return false;

}
void BramkaOr::dodajDoKompozycji(std::shared_ptr<Komponent> komp)
{
   wartosci.push_back(komp);
}
void BramkaOr::Accept( Visitator *v)
{
   v->operacja(this);
}
std::vector<std::shared_ptr<Komponent>> BramkaOr::getVector()
{
    return wartosci; 
} 
void BramkaOr::setVectorValue(int index, bool value){
    this->wartosci[index]->setVectorValue(index,value);
}
bool BramkaOr::sprawdzCzyJestemLisciem()
{
    return false;
}
std::shared_ptr<Komponent> BramkaOr::Klonuj()
{
  auto klon = std::make_shared<BramkaOr>();
    
    if(!wartosci.empty())
    {
        for( size_t i = 0; i < wartosci.size(); i++ )
        {             
                klon->dodajDoKompozycji(wartosci[i]->Klonuj());    
        }
    
    }
    
    return klon;

}
std::ostream& BramkaOr::print(std::ostream &wyjscie)
{
    wyjscie<<"[BramkaOr(";
    
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
    wyjscie<<")]";
    return wyjscie;
       
}
