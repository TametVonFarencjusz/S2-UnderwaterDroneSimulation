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

  Woda(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = -10, std::string color = "blue") : Plaszczyzna(A, Z, color){};

  void Draw() override
  {
    id = api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-10,-10,zLevel), drawNS::Point3D(-10,-5,zLevel), drawNS::Point3D(-10,0,zLevel), drawNS::Point3D(-10,5,zLevel), drawNS::Point3D(-10,10,zLevel)
	  },{
	drawNS::Point3D(-5,-10,zLevel), drawNS::Point3D(-5,-5,zLevel), drawNS::Point3D(-5,0,zLevel), drawNS::Point3D(-5,5,zLevel), drawNS::Point3D(-5,10,zLevel)      
	  },{
	drawNS::Point3D(0,-10,zLevel), drawNS::Point3D(0,-5,zLevel), drawNS::Point3D(0,0,zLevel), drawNS::Point3D(0,5,zLevel), drawNS::Point3D(0,10,zLevel)
          },{
	drawNS::Point3D(5,-10,zLevel), drawNS::Point3D(5,-5,zLevel), drawNS::Point3D(5,0,zLevel), drawNS::Point3D(5,5,zLevel), drawNS::Point3D(5,10,zLevel)
          },{
        drawNS::Point3D(10,-10,zLevel), drawNS::Point3D(10,-5,zLevel), drawNS::Point3D(10,0,zLevel), drawNS::Point3D(10,5,zLevel), drawNS::Point3D(10,10,zLevel) 
	  }},color);//rysuje zolta powierzchnie
  }
};

#endif
