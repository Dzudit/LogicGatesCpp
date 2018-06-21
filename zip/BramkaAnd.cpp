#include "BramkaAnd.h"

BramkaAnd::BramkaAnd()
{
}
bool BramkaAnd::operacja()
{
    bool result = true;
 
    if(!wartosci.empty())
    {
        for( size_t i = 0; i < wartosci.size(); i++ )
        {
                result &= wartosci[i]->operacja();
        }
    
    return result;
    }
    
    else return false;

}
void BramkaAnd::dodajDoKompozycji(std::shared_ptr<Komponent> komp)
{
   wartosci.push_back(komp);
}
void BramkaAnd::Accept( Visitator *v)
{
    v->operacja(this);
}
std::vector<std::shared_ptr<Komponent>> BramkaAnd::getVector()
{
    return wartosci; 
} 
void BramkaAnd::setVectorValue(int index, bool value){
    this->wartosci[index]->setVectorValue(index,value);
}
bool BramkaAnd::sprawdzCzyJestemLisciem() 
{
     return false;
}
std::shared_ptr<Komponent> BramkaAnd::Klonuj()
{
  auto klon = std::make_shared<BramkaAnd>();
    
    if(!wartosci.empty())
    {
        for( size_t i = 0; i < wartosci.size(); i++ )
        {             
                klon->dodajDoKompozycji(wartosci[i]->Klonuj());    
        }
    
    }
    
    return klon;

}
std::ostream& BramkaAnd::print(std::ostream &wyjscie)
{
    wyjscie<<"[BramkaAnd(";
      
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