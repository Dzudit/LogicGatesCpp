#include "VisitatorZaneguj.h"
#include <iostream>

void VisitatorZaneguj::operacja(Komponent* k)
{
    if (k->getVector().front()->sprawdzCzyJestemLisciem() == false)
    {
     k->getVector().front()->Accept(this);
    }
    else 
    {
        k->setVectorValue(0, (!k->getVector().front()->operacja()));
    }

}