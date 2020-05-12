#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#include "rozmiar.h"
#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

using std::vector;
using drawNS::Point3D;

class Graniastoslup6 : public Obiekt3D{
  protected:
  //MacierzOb orientation;
  //Wektor3D center;
  Wektor3D point0;

  void Refresh(Wektor3D punkty[]);
  public:
  //Prostopadloscian() : Obiekt3D() {}
  Graniastoslup6(std::shared_ptr<drawNS::Draw3DAPI> A, std::string C = "green") : Obiekt3D(A), point0(1,1,1) {color = C;}
  Graniastoslup6(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D & P1, std::string C = "green") : Obiekt3D(A), point0(P1) {color = C;}  
  Graniastoslup6(std::shared_ptr<drawNS::Draw3DAPI> A, const MacierzOb & Macierz, const Wektor3D & Srod, const Wektor3D & Punkt, std::string C = "green") : Obiekt3D(A)  
  {
    color = C;
    center = Srod;
    point0 = Punkt;
    orientation = Macierz;
  }  

  Graniastoslup6(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D & Alfa, const Wektor3D & Srod, const Wektor3D & Punkt, std::string C = "green") : Obiekt3D(A)  
  {
    color = C;
    center = Srod;
    point0 = Punkt;
    orientation = MacierzOb(Alfa[0], WymiarX) * MacierzOb(Alfa[1], WymiarY) * MacierzOb(Alfa[2], WymiarZ);
  }

  void setPoint0(const Wektor3D & W){point0 = W;}
  Wektor3D getPoint0() const {return point0;}

  
  /*!
   * \brief draws cuboid
   * \param api - 
   * \return id of shape
   */
  void Draw() override;
};


#endif
