#ifndef PRZEPROSTOPAD_HH
#define PRZEPROSTOPAD_HH

#include "rozmiar.h"
#include "Prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

class PrzeszkodaProstopadloscian : public Przeszkoda, public Prostopadloscian{
  public:
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, std::string C = "yellow") : Prostopadloscian(A, "red"){}

  bool isCollision(std::shared_ptr<InterfejsDrona> inDron) override
  {
    if ((inDron->getDron().getCenter() - center).dlugosc() < point0.dlugosc() + inDron->getDron().getPoint0().dlugosc())
      return true;
    return false;
  }
};


#endif
