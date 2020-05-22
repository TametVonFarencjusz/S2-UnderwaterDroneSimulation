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
  int size;

  public:
  Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> A, double Z = 0, std::string color = "purple", int s = PLANEPOINT) : Obiekt3D(A, Wektor3D(0,0,Z), color), size(PLANEPOINT){};
  Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D & W = Wektor3D(0,0,0), std::string color = "purple", int s = PLANEPOINT) : Obiekt3D(A, W, color), size(PLANEPOINT){};

  //void setZLevel(double Z){zLevel = Z;}
  //double getZLevel() const {return zLevel;}
  /*!
   * \brief draws plane
   */
  virtual void Draw() override;
};

#endif
