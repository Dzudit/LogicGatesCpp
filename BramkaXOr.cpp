#include "BramkaXOr.h"

BramkaXOr::BramkaXOr()
{
}
bool BramkaXOr::operacja()
{
    if(wartosci.size() == 2)
    {
        if(wartosci[0]->operacja() == wartosci[1]->operacja())
        {
           return false;
        }
        else return true;

    }
    else return false;

}
void BramkaXOr::dodajDoKompozycji(std::shared_ptr<Komponent> komp)
{
   if(wartosci.size()<3)
   {
        wartosci.push_back(komp);
   }
}
void BramkaXOr::Accept( Visitator *v)
{
     v->operacja(this);
}
std::vector<std::shared_ptr<Komponent>> BramkaXOr::getVector()
{
    return wartosci; 
} 
void BramkaXOr::setVectorValue(int index, bool value){

    if(index < 2)
    {
        this->wartosci[index]->setVectorValue(index,value);
    }
}
bool BramkaXOr::sprawdzCzyJestemLisciem()
{
    return false;
}
std::shared_ptr<Komponent> BramkaXOr::Klonuj()
{
  auto klon = std::make_shared<BramkaXOr>();
    
    if(!wartosci.empty())
    {
        for( size_t i = 0; i < wartosci.size(); i++ )
        {             
                klon->dodajDoKompozycji(wartosci[i]->Klonuj());    
        }
    
    }
    return klon;

}
std::ostream& BramkaXOr::print(std::ostream &wyjscie)
{
    wyjscie<<"[BramkaXOr(";
    
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