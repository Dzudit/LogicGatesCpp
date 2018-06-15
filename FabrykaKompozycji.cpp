#include "FabrykaKompozycji.h"

Bramka::Bramka(std::string wejscie) : mamLiscie(false) {

 nazwaBramki = wejscie.substr(wejscie.find('[') + 1, wejscie.find('(') - 1);
 wejscie = wejscie.substr(wejscie.find('(') + 1, wejscie.rfind(')') - wejscie.find('(') - 1);

 if (wejscie[0] == '{')
 {
  mamLiscie = true; // bramka ktora zawiera na wejscie juz tylko liscie 
  liscie = wejscie;
 }
 else
 {
  int liczba_otwartych_nawiasow = 0;
  int liczba_zamknietych_nawiasow = 0;
  int poczatek = 0;

  for (int i = 0; i <= wejscie.size(); i++)
  {
   if (wejscie[i] == '[') { liczba_otwartych_nawiasow++; }
   if (wejscie[i] == ']') { liczba_zamknietych_nawiasow++; }

   if (liczba_otwartych_nawiasow == liczba_zamknietych_nawiasow)
   {
    auto bramka = wejscie.substr(poczatek, i - poczatek + 1);
    Bramka B(bramka);
    bramki.push_back(B);
    poczatek = i + 2;
    i++;
   }
  }
 }
}
std::string Bramka::getNazwaBramki()
{
 return nazwaBramki;
}
std::vector<Bramka> Bramka::getBramki()
{
 return bramki;
}
bool Bramka::getMamLiscie()
{
 return mamLiscie;
}
std::string Bramka::getLiscie()
{
 return liscie;
}
void Fabryka::dodajWartosci(std::shared_ptr<Komponent> komp, std::string liscie)
{
 for (int i = 0; i < liscie.size(); i++)
 {
  if (isdigit(liscie[i]))
  {
   auto lisc = std::make_shared<Lisc>(liscie[i]);
  // komp->dodajDoKompozycji(lisc);
  }
 }
}
std::shared_ptr<Komponent> Fabryka::stworz(Bramka strukturaBramek) {

 auto nazwa = strukturaBramek.getNazwaBramki();
 if (nazwa == "NOT")
 {
  auto NOT = std::make_shared<BramkaOr>();
  if (strukturaBramek.getMamLiscie())
  {
   dodajWartosci(NOT, strukturaBramek.getLiscie());
  }
  else
  {
   std::vector<Bramka> br = strukturaBramek.getBramki();
   if (!br.empty())
   {
    for (size_t i = 0; i < br.size(); i++)
    {
     NOT->dodajDoKompozycji(stworz(br[i]));
    }
   }
  }
  return NOT;
 }
 if (nazwa == "AND")
 {
  auto AND = std::make_shared<BramkaOr>();
  if (strukturaBramek.getMamLiscie())
  {
   dodajWartosci(AND, strukturaBramek.getLiscie());

  }
  else
  {
   std::vector<Bramka> br = strukturaBramek.getBramki();
   if (!br.empty())
   {
    for (size_t i = 0; i < br.size(); i++)
    {
     AND->dodajDoKompozycji(stworz(br[i]));
    }
   }
  }
  return AND;

 }
 if (nazwa == "XOR")
 {
  auto XOR = std::make_shared<BramkaOr>();
  if (strukturaBramek.getMamLiscie())
  {
   dodajWartosci(XOR, strukturaBramek.getLiscie());
  }
  else
  {
   std::vector<Bramka> br = strukturaBramek.getBramki();
   if (!br.empty())
   {
    for (size_t i = 0; i < br.size(); i++)
    {
     XOR->dodajDoKompozycji(stworz(br[i]));
    }
   }
  }
  return XOR;
 }
 if (nazwa == "OR")
 {

  auto OR = std::make_shared<BramkaOr>();
  if (strukturaBramek.getMamLiscie())
  {
   dodajWartosci(OR, strukturaBramek.getLiscie());
  }
  else
  {
   std::vector<Bramka> br = strukturaBramek.getBramki();
   if (!br.empty())
   {
    for (size_t i = 0; i < br.size(); i++)
    {
     OR->dodajDoKompozycji(stworz(br[i]));
    }
   }
  }
  return OR;
 }
 else
 {
  return nullptr;
 }

}
