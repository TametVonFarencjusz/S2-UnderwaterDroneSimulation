#ifndef WODA_HH
#define WODA_HH

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"
#include <iostream>
#include <string>

class Woda : public Plaszczyzna, public Przeszkoda{
  protected:
  double noise;

  public:
  Woda(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = 10, std::string color = "blue", int s = PLANEPOINT, double N = 0.5) : Plaszczyzna(A, Z, color,s), noise(N){};
  Woda(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D & W = Wektor3D(0,0,10), std::string color = "blue", int s = PLANEPOINT, double N = 0.5) : Plaszczyzna(A, W, color,s), noise(N){};

  bool isCollision(std::shared_ptr<InterfejsDrona> inDron) override
  {
    if (inDron->getDron().getCenter()[2] > center[2])
      return true;
    return false;
  }

  void Draw() override
  {
    vector<vector<Point3D>> pointVectorBig;
    
    for (int j = -size; j <= size; ++j)
    {
      vector<Point3D> pointVectorSmall;
      for (int i = -size; i <= size; ++i)
      {
        Wektor3D tempWektor(center[0] + i*PLANESKIP, center[1] + j*PLANESKIP, center[2] + noise * (i%2==0?-1:1));
        tempWektor = orientation * tempWektor;
        pointVectorSmall.push_back(tempWektor);
      }
      pointVectorBig.push_back(pointVectorSmall);
    }
     id = api->draw_surface(pointVectorBig,color);//rysuje zolta powierzchnie
  }
};

#endif
