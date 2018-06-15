#include <memory>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lisc.h"
#include "BramkaNot.h"
#include "BramkaAnd.h"
#include "BramkaOr.h"
#include "BramkaXOr.h"
#include <vector>


#ifndef FABRYKA_H
#define FABRYKA_H


class Bramka 
{ 
private:
  std::string nazwaBramki;
  std::vector<Bramka> bramki;
  bool mamLiscie;
  std::string liscie;

public:
  Bramka(std::string gate);
  std::string getNazwaBramki();
  std::vector<Bramka> getBramki();
  bool getMamLiscie();
  std::string getLiscie();

};
class Fabryka
{
 public:
  std::shared_ptr<Komponent> stworz(Bramka strukturaBramek);
  void dodajWartosci(std::shared_ptr<Komponent> komp, std::string liscie);

};

#endif