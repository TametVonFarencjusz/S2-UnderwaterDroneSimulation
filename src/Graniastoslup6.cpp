#include "Graniastoslup6.hh"
#include <iostream>


  void Graniastoslup6::Refresh(Wektor3D punkty[])
  {
    MacierzOb tempMac;

    punkty[0]  = center + tempMac.Obrot(0 , WymiarZ)  * orientation * point0;
    punkty[1]  = center + tempMac.Obrot(60, WymiarZ)  * orientation * point0;
    punkty[2]  = center + tempMac.Obrot(120, WymiarZ) * orientation * point0;
    punkty[3]  = center + tempMac.Obrot(180, WymiarZ) * orientation * point0;
    punkty[4]  = center + tempMac.Obrot(240, WymiarZ) * orientation * point0;
    punkty[5]  = center + tempMac.Obrot(300, WymiarZ) * orientation * point0;

    punkty[6]  = center + tempMac.Obrot(0 , WymiarZ)  * orientation * point0.Reverse(WymiarZ);
    punkty[7]  = center + tempMac.Obrot(60, WymiarZ)  * orientation * point0.Reverse(WymiarZ);
    punkty[8]  = center + tempMac.Obrot(120, WymiarZ) * orientation * point0.Reverse(WymiarZ);
    punkty[9]  = center + tempMac.Obrot(180, WymiarZ) * orientation * point0.Reverse(WymiarZ);
    punkty[10] = center + tempMac.Obrot(240, WymiarZ) * orientation * point0.Reverse(WymiarZ);
    punkty[11] = center + tempMac.Obrot(300, WymiarZ) * orientation * point0.Reverse(WymiarZ);
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
