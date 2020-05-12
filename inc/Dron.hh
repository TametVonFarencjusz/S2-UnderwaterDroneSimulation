#ifndef DRON_HH
#define DRON_HH


#include "rozmiar.h"
#include "Prostopadloscian.hh"
#include "Wektor3D.hh"
#include "Graniastoslup6.hh"
#include "Dr3D_gnuplot_api.hh"
#include <unistd.h>
#include <iostream>

class Dron : public Prostopadloscian{
  protected:
  //Wektor3D position;

  double angle;
  //Prostopadloscian body;
  Graniastoslup6 propellerLeft;
  Graniastoslup6 propellerRight;

  public:
  Dron(std::shared_ptr<drawNS::Draw3DAPI> A) : Prostopadloscian(A), propellerLeft(A, "yellow"), propellerRight(A, "yellow")
  {
    //api = A;
    point0 = {3,2,2}; 
    //point0Propeller = {1,1,1}; 
  }

  //void setSpeed(double S){speedXYZ = S;}
  //double getSpeed() const {return speedXYZ;}
  
  void setAngle(double A){angle = A; orientation.Obrot(angle, WymiarZ);}
  double getAngle() const {return angle;}
  void addAngle(double A){angle += A; orientation.Obrot(angle, WymiarZ);}

  //void setAngleUpDown(double A){angle[0] = A;}
  //double getAngleUpDown() const {return angle[0];}

  //void setPosition(Wektor3D W){position = W;}
  //Wektor3D getPosition() const {return position;}

  void DrawAll();
  void Move(double speed, double angle);
  void MoveAnimation(double speed, double angle);
  void addAngleAnimation(double angleZ);
  //Rysowanie
  void UnDrawAll();
  void DrawPropellerLeft();
  void DrawPropellerRight();
  //int DrawBody();
};

#endif
