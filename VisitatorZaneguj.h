#include "Visitator.h"
#include "Komponent.h"
#include <memory>

class VisitatorZaneguj : public Visitator
{
    public:
         void operacja(Komponent* k) override; 
};