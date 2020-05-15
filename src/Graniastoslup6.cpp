#include "Graniastoslup6.hh"
#include <iostream>


  void Graniastoslup6::Refresh(Wektor3D punkty[])
  {
    punkty[0]  = center + MacierzOb(0 , WymiarZ)  * orientation * point0;
    punkty[1]  = center + MacierzOb(60, WymiarZ)  * orientation * point0;
    punkty[2]  = center + MacierzOb(120, WymiarZ) * orientation * point0;
    punkty[3]  = center + MacierzOb(180, WymiarZ) * orientation * point0;
    punkty[4]  = center + MacierzOb(240, WymiarZ) * orientation * point0;
    punkty[5]  = center + MacierzOb(300, WymiarZ) * orientation * point0;

    punkty[6]  = center + MacierzOb(0 , WymiarZ)  * orientation * point0.Reverse(WymiarZ);
    punkty[7]  = center + MacierzOb(60, WymiarZ)  * orientation * point0.Reverse(WymiarZ);
    punkty[8]  = center + MacierzOb(120, WymiarZ) * orientation * point0.Reverse(WymiarZ);
    punkty[9]  = center + MacierzOb(180, WymiarZ) * orientation * point0.Reverse(WymiarZ);
    punkty[10] = center + MacierzOb(240, WymiarZ) * orientation * point0.Reverse(WymiarZ);
    punkty[11] = center + MacierzOb(300, WymiarZ) * orientation * point0.Reverse(WymiarZ);
  }

  void Graniastoslup6::Draw() 
  {
    Wektor3D punkty[12];
    Refresh(punkty);
    id = api->draw_polyhedron(vector<vector<Point3D> > {
    {drawNS::Point3D(punkty[0]), drawNS::Point3D(punkty[1]), drawNS::Point3D(punkty[2]), drawNS::Point3D(punkty[3]), drawNS::Point3D(punkty[4]), drawNS::Point3D(punkty[5])},
    //{drawNS::Point3D(punkty[0]), drawNS::Point3D(punkty[1]), drawNS::Point3D(punkty[2]), drawNS::Point3D(punkty[3]), drawNS::Point3D(punkty[4]), drawNS::Point3D(punkty[5])}
    {drawNS::Point3D(punkty[6]), drawNS::Point3D(punkty[7]), drawNS::Point3D(punkty[8]), drawNS::Point3D(punkty[9]), drawNS::Point3D(punkty[10]), drawNS::Point3D(punkty[11])}
    },color);
    //std::cout << punkt1 << std::endl;
    //std::cout << punkty[0] << std::endl;
    //std::cout << orientacja << std::endl;
  }
