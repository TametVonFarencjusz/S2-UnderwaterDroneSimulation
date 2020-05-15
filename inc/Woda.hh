#ifndef WODA_HH
#define WODA_HH

#include "Plaszczyzna.hh"
#include <iostream>
#include <string>

class Woda : public Plaszczyzna{
  protected:
  double noise;

  public:
  //Woda() : zLevel(10),noise(0.5){};
  //Woda(double Z = 10, double N = 0) : zLevel(Z),noise(N){};

  Woda(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = -10, double N = 0.5, std::string color = "blue") : Plaszczyzna(A, Z, color), noise(N){};

  void Draw() override
  {
    vector<vector<Point3D>> pointVectorBig;
    
    for (int j = -PLANEPOINT; j <= PLANEPOINT; ++j)
    {
      vector<Point3D> pointVectorSmall;
      for (int i = -PLANEPOINT; i <= PLANEPOINT; ++i)
      {
        Wektor3D tempWektor(i*PLANESKIP,j*PLANESKIP,zLevel + noise * (i%2==0?-1:1));
        tempWektor = orientation * tempWektor;
        pointVectorSmall.push_back(tempWektor);
      }
      pointVectorBig.push_back(pointVectorSmall);
    }
     id = api->draw_surface(pointVectorBig,color);//rysuje zolta powierzchnie
  }
};

#endif
