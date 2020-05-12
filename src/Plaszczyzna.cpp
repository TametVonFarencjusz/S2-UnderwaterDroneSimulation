#include "Plaszczyzna.hh"
#include <iostream>


using std::vector;
using std::string;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

  void Plaszczyzna::Draw()
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

