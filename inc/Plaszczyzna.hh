#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Obiekt3D.hh"
#include <vector>
#include "Dr3D_gnuplot_api.hh"
#include <iostream>
#include <string>

using std::vector;
using std::string;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Plaszczyzna : public Obiekt3D{
  protected:
  double zLevel;

  public:
  //virtual Plaszczyzna() : zLevel(0),noise(0),color("black"){};
  Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = 0, std::string color = "purple") : Obiekt3D(A, color), zLevel(Z){};

  void setZLevel(double Z){zLevel = Z;}
  double getZLevel() const {return zLevel;}

  //void setColor(string C){color = C;}
  //string getColor() const {return color;}

  void Draw() override;
};

#endif
