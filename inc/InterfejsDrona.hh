#ifndef INTDRON_HH
#define INTDRON_HH


#include "rozmiar.h"
#include "Dron.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include <unistd.h>
#include <iostream>

class InterfejsDrona{
  protected:
  Dron dron;
  bool picked; 

  void colorPicked()
  { 
    if(picked) dron.setColor("green");
    else  dron.setColor("yellow");
  }
  public:
  InterfejsDrona(std::shared_ptr<drawNS::Draw3DAPI> A, double Alfa, const Wektor3D & Srod, const Wektor3D & Punkt = Wektor3D(3,2,2), std::string C = "yellow") : dron(A, Alfa, Srod, Punkt, C), picked(false){};
  ~InterfejsDrona(){UnDraw();}
  void setDron(const Dron & D){dron = D;}
  Dron getDron() const {return dron;}
  /*!
   * \brief calls Move(), DrawAll() and usleep(10000) 100 times
   * move dron - animation takes 1 sec to complete.
   * \param speed - distance that dron will go,
   * \param angleY - angle in degrees.
   */  
  void MoveAnimation(double speed, double angleY){dron.MoveAnimation(speed, angleY);}
  /*!
   * \brief calls addAngle(), DrawAll() and usleep(10000) 100 times
   * rotate dron - animation takes 1 sec to complete.
   * \param angleZ - angle in degrees.
   */  
  void setPicked(bool P){picked = P; colorPicked();}
  void addAngleAnimation(double angleZ) {dron.addAngleAnimation(angleZ);}
  void Draw() {dron.DrawAll();}
  void UnDraw() {dron.UnDrawAll();}
};

#endif
