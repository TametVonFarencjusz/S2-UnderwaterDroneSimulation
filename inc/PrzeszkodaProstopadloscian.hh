#ifndef PRZEPROSTOPAD_HH
#define PRZEPROSTOPAD_HH

#include "rozmiar.h"
#include "Prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

class PrzeszkodaProstopadloscian : public Przeszkoda, public Prostopadloscian{
  public:
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, std::string C = "red") : Prostopadloscian(A, C){}
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D & Alfa, const Wektor3D & Srod, const Wektor3D & Punkt = Wektor3D(1,1,1), std::string C = "red") : Prostopadloscian(A, Alfa, Srod, Punkt, C){}

  bool isCollision(std::shared_ptr<InterfejsDrona> inDron) override
  {
    if ((inDron->getCenter() - center).dlugosc() < point0.dlugosc() + inDron->getRadius())
      return true;
    return false;
  }
};


#endif
