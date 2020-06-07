#ifndef PRZEPROSTOPAD_HH
#define PRZEPROSTOPAD_HH

#include "rozmiar.h"
#include "Prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>
#include <stdlib.h>

class PrzeszkodaProstopadloscian : public Przeszkoda, public Prostopadloscian{
  public:
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, std::string C = "red") : Prostopadloscian(A, C){}
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D & Alfa, const Wektor3D & Srod, const Wektor3D & Punkt = Wektor3D(1,1,1), std::string C = "red") : Prostopadloscian(A, Alfa, Srod, Punkt, C){}

  bool isCollision(std::shared_ptr<InterfejsDrona> inDron) override
  {
    Wektor3D tempW = orientation * point0;
    Wektor3D tempD = orientation * inDron->getCenter();
    Wektor3D tempC = orientation * center;

    //if (center == Wektor3D(20,-10, 0))std::cout << tempW;
    bool flag = true;
    if (!(abs(tempD[0] - tempC[0]) < tempW[0] + inDron->getRadius()))
      flag = false;
    if (!(abs(tempD[1] - tempC[1]) < tempW[1] + inDron->getRadius()))
      flag = false;
    if (!(abs(tempD[2] - tempC[2]) < tempW[2] + inDron->getRadius()))
      flag = false;
    return flag;

    /*bool flag = true;
    if (!(abs(inDron->getCenter()[0] - center[0]) < point0[0] + inDron->getRadius()))
      flag = false;
    if (!(abs(inDron->getCenter()[1] - center[1]) < point0[1] + inDron->getRadius()))
      flag = false;
    if (!(abs(inDron->getCenter()[2] - center[2]) < point0[2] + inDron->getRadius()))
      flag = false;
    return flag;*/
  }
};


#endif
