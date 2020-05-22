#include "Plaszczyzna.hh"
#include <iostream>


using std::vector;
using std::string;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

  void Plaszczyzna::Draw()
  {
    vector<vector<Point3D>> pointVectorBig;
    
    for (int j = -size; j <= size; ++j)
    {
      vector<Point3D> pointVectorSmall;
      for (int i = -size; i <= size; ++i)
      {
        Wektor3D tempWektor(center[0] + i*PLANESKIP,center[1] + j*PLANESKIP,center[2]);
        tempWektor = orientation * tempWektor;
        pointVectorSmall.push_back(tempWektor);
      }
      pointVectorBig.push_back(pointVectorSmall);
      //pointVectorBig.pop_back();
    }
     id = api->draw_surface(pointVectorBig,color);//rysuje zolta powierzchnie
  }

