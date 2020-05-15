#ifndef DNO_HH
#define DNO_HH

#include "Plaszczyzna.hh"
#include <iostream>
#include <string>

class Dno : public Plaszczyzna{
  protected:

  public:
  Dno(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = -10, std::string color = "orange") : Plaszczyzna(A, Z, color){};

  /*void Draw() override
  {
    vector<vector<Point3D>> pointVectorBig;
    
    for (int j = -PLANEPOINT; j <= PLANEPOINT; ++j)
    {
      vector<Point3D> pointVectorSmall;
      for (int i = -PLANEPOINT; i <= PLANEPOINT; ++i)
      {
        pointVectorSmall.push_back(drawNS::Point3D(i*PLANESKIP,j*PLANESKIP,zLevel));
      }
      pointVectorBig.push_back(pointVectorSmall);
    }
     id = api->draw_surface(pointVectorBig,color);
  }*/
};

#endif
