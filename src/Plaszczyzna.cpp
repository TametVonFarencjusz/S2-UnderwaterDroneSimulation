#include "Plaszczyzna.hh"
#include <iostream>


using std::vector;
using std::string;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

  void Plaszczyzna::Draw()
  {
    
    vector<vector<Point3D>> pointVectorBig;
    
    for (int j = -PLANEPOINT; j <= PLANEPOINT; ++j)
    {
      vector<Point3D> pointVectorSmall;
      for (int i = -PLANEPOINT; i <= PLANEPOINT; ++i)
      {
        Wektor3D tempWektor(i*PLANESKIP,j*PLANESKIP,zLevel);
        tempWektor = orientation * tempWektor;
        pointVectorSmall.push_back(tempWektor);
      }
      pointVectorBig.push_back(pointVectorSmall);
      //pointVectorBig.pop_back();
    }
     id = api->draw_surface(pointVectorBig,color);//rysuje zolta powierzchnie
  }

