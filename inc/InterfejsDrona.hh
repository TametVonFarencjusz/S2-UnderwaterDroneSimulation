#ifndef INTDRON_HH
#define INTDRON_HH

#include "rozmiar.h"
#include "Przeszkoda.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include <unistd.h>
#include <iostream>

class InterfejsDrona{
  protected:
  public:
  //InterfejsDrona(std::shared_ptr<drawNS::Draw3DAPI> A, double Alfa, const Wektor3D & Srod, const Wektor3D & Punkt = Wektor3D(3,2,2), std::string C = "yellow") : dron(A, Alfa, Srod, Punkt, C), picked(false){};
  //~InterfejsDrona(){UnDraw();}
  virtual Wektor3D getCenter() = 0;
  virtual double getRadius() = 0;
  virtual void setColor(const std::string & C) = 0;

  virtual void setAngle(double A) = 0;
  virtual double getAngle() = 0;
  virtual void addAngle(double A) = 0;
  virtual void MoveAnimation(double speed, double angleY) = 0;
  virtual void addAngleAnimation(double angleZ) = 0;
  virtual void Move(double speed, double angleY) = 0;
  virtual void Draw() = 0;
  virtual void UnDraw() = 0;
};

#endif
