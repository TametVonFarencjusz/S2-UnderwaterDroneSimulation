#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Obiekt3D.hh"
#include "rozmiar.h"
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
  Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = 0, std::string color = "purple") : Obiekt3D(A, color), zLevel(Z){};

  void setZLevel(double Z){zLevel = Z;}
  double getZLevel() const {return zLevel;}
  /*!
   * \brief draws plane
   */
  void Draw() override;
};

#endif
