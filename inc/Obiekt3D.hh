#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH

#include "rozmiar.h"
#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>
#include <string>

class Obiekt3D{
  protected:
  MacierzOb orientation;
  Wektor3D center;
  std::shared_ptr<drawNS::Draw3DAPI> api;
  std::string color;
  int id;

  public:
  //Obiekt3D() : id(-1) {}
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A, std::string C = "black") : api(A), color(C), id(-1) {}
  Obiekt3D(MacierzOb M, Wektor3D S, Wektor3D P, std::string C = "black") : orientation(M), center(S), color(C) , id(-1) {}

  void setCenter(const Wektor3D & W){center = W;}
  Wektor3D getCenter() const {return center;}

  void setOrientation(const MacierzOb & M){orientation = M;}
  MacierzOb getOrientation() const {return orientation;}

  void setColor(const std::string & C){color = C;}
  std::string getColor() const {return color;}

  int getID() const {return id;}

  virtual void Draw() = 0;
  //void UnDraw(xx) {if (id != -1) {api->erase_shape(id); id = -1;}}
  void UnDraw() {if (id != -1) {api->erase_shape(id); id = -1;}}
  //virtual Draw(std::shared_ptr<drawNS::Draw3DAPI> api) {};
};

#endif
