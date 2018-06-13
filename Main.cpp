#include <iostream>
#include <cstdlib>
#include "Lisc.h"
#include <memory>
#include "BramkaNot.h"
#include "BramkaAnd.h"
#include "BramkaOr.h"
#include "BramkaXOr.h"
#include "Kompozyt.h"
#include "Visitator.h"
#include "VisitatorZaneguj.h"
#include <vector>

using namespace std;
ostream& operator<< (ostream &wyjscie, Komponent &s)
 {
      s.print(wyjscie);
      return wyjscie;
 }
 int zliczZagniezdzenie(string a){
    
    auto l=1;
    for(int i=1; i<a.length(); i++)
    {
         if(a[i]=='[' && a[i-1]!=',')
         {
                l++;
         }
    }
    return l;
 }
int main()
{
  // zagniezdzenie bramek
  // 8 wartosci wejsciowych 
  auto LNOT = make_shared<Lisc>(true);
  auto LOR1 = make_shared<Lisc>(true);
  auto LOR2 = make_shared<Lisc>(false);
  auto LOR3 = make_shared<Lisc>(false);
  auto LAND1 = make_shared<Lisc>(true);
  auto LAND2 = make_shared<Lisc>(true);
  auto LAND3 = make_shared<Lisc>(true);
  
  auto BNOT = make_shared <BramkaNot>(LNOT);
  auto BOR = make_shared<BramkaOr>();
  BOR->dodajDoKompozycji(LOR1);
  BOR->dodajDoKompozycji(LOR2);
  BOR->dodajDoKompozycji(LOR3);
  auto BAND = make_shared<BramkaAnd>();
  BAND->dodajDoKompozycji(LAND1);
  BAND->dodajDoKompozycji(LAND2);
  BAND->dodajDoKompozycji(LAND3);

  std::cout << "testowanie bramek: " << std::endl;

  std::cout << *BNOT;
  BNOT->wyswietlWynikOperacji() << std::endl;

  std::cout << *BOR;
  BOR->wyswietlWynikOperacji() << std::endl;

  std::cout << *BAND;
  BAND->wyswietlWynikOperacji() << std::endl;

  auto BXOR  = make_shared <BramkaXOr>();
  BXOR->dodajDoKompozycji(std::shared_ptr<Komponent> (BNOT));
  BXOR->dodajDoKompozycji(std::shared_ptr<Komponent> (BOR));

  std::cout << *BXOR;
  BXOR->wyswietlWynikOperacji() << std::endl;

  auto BAND2 = make_shared <BramkaAnd>();
  BAND2->dodajDoKompozycji(std::shared_ptr<Komponent> (BXOR));
  BAND2->dodajDoKompozycji(std::shared_ptr<Komponent> (BAND));

  std::cout << *BAND2;
  BAND2->wyswietlWynikOperacji() << std::endl << std::endl;

  std::cout << "TESET WIZYTORA: WizyturZaneguj, neguje pierwsza wartosc wejsciowa pierwszej bramki czyli w tym wypadku Bramki NOT z true na false" << std::endl;
  
  std::cout<< "ORGINAL BRAMKI:" <<std::endl;
  std::cout << *BAND2;
  BAND2->wyswietlWynikOperacji() << std::endl << std::endl;
 
  std::cout<< "KOPIA BRAMKI:" <<std::endl; 
  auto Klon = BAND2->Klonuj();
  std::cout<<*Klon;
  Klon->wyswietlWynikOperacji() << std::endl << std::endl;

  std::cout<< "ZMIANA KOPI BRAMKI PIERWSZEJ WARTOSCI PRZEZ WIZYTORA" <<std::endl; 
  Visitator *visitor1 = new VisitatorZaneguj();
  Klon->Accept(visitor1);
  std::cout << *Klon;
  Klon->wyswietlWynikOperacji() << std::endl << std::endl;

  std::cout<< "SPRAWDZENIE CZY ORGINAL SIE NIE ZMIENIL:" <<std::endl; 
  std::cout << *BAND2;
  BAND2->wyswietlWynikOperacji() << std::endl << std::endl;

  auto bramka = "[BramkaAnd([BramkaXOr([BramkaNot({0})],[BramkaOr({1},{0},{0})])],[BramkaAnd({1},{1},{1})])]";
  std::cout << "Zagniezdzenie bramki: " << zliczZagniezdzenie(bramka) << std::endl;


  system("pause");

  return 0;

}