#include "Prostopadloscian.hh"
#include <iostream>


  void Prostopadloscian::Refresh(Wektor3D punkty[])
  {
    punkty[0] = center + orientation * point0;
    punkty[1] = center + orientation * point0.Reverse(WymiarX);
    punkty[2] = center + orientation * point0.Reverse(WymiarX).Reverse(WymiarY);
    punkty[3] = center + orientation * point0.Reverse(WymiarY);
    punkty[4] = center + orientation * point0.Reverse(WymiarZ);
    punkty[5] = center + orientation * point0.Reverse(WymiarZ).Reverse(WymiarX);
    punkty[6] = center + orientation * point0.Reverse(WymiarZ).Reverse(WymiarX).Reverse(WymiarY);
    punkty[7] = center + orientation * point0.Reverse(WymiarZ).Reverse(WymiarY);
  }

  void Prostopadloscian::Draw() 
  {
    Wektor3D punkty[8];
    Refresh(punkty);
    id = api->draw_polyhedron(vector<vector<Point3D> > {
    {drawNS::Point3D(punkty[0]), drawNS::Point3D(punkty[1]), drawNS::Point3D(punkty[2]), drawNS::Point3D(punkty[3])},
    {drawNS::Point3D(punkty[4]), drawNS::Point3D(punkty[5]), drawNS::Point3D(punkty[6]), drawNS::Point3D(punkty[7])}
    },color);
    //std::cout << punkt1 << std::endl;
    //std::cout << punkty[0] << std::endl;
    //std::cout << orientacja << std::endl;
  }
