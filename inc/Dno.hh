#ifndef DNO_HH
#define DNO_HH

#include "Przeszkoda.hh"
#include "Plaszczyzna.hh"
#include <iostream>
#include <string>

class Dno : public Plaszczyzna, public Przeszkoda{
  protected:

  public:
  //Dno(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = -10, std::string color = "orange") : Plaszczyzna(A, Z, color){};
  Dno(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = -10, std::string color = "orange", int s = PLANEPOINT) : Plaszczyzna(A, Z, color,s){};
  Dno(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D & W = Wektor3D(0,0,-10), std::string color = "orange", int s = PLANEPOINT) : Plaszczyzna(A, W, color,s){};

  bool isCollision(std::shared_ptr<InterfejsDrona> inDron) override
  {
    if (inDron->getCenter()[2] - inDron->getRadius() < center[2])
      return true;
    return false;
  }
};

#endif
