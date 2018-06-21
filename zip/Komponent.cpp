#include "Komponent.h"
#include <iostream>

Komponent::~Komponent()
{
}
std::ostream& Komponent::wyswietlWynikOperacji()
{
 return std::cout << " -> {" << operacja() << "}";
}