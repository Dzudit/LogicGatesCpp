#include <memory>
#include "Komponent.h"
#ifndef  VISITOR_H
#define VISITOR_H 

class Visitator
{
    public:
        virtual ~Visitator();
        virtual void operacja(Komponent* k) = 0;
};

#endif