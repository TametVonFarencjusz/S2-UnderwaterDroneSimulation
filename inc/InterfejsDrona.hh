#ifndef INTDRON_HH
#define INTDRON_HH


#include "rozmiar.h"
#include "Dron.hh"
#include "Wektor3D.hh"
//#include "Przeszkoda.hh"
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

  /*bool collision(std::vector<std::shared_ptr<Przeszkoda>> kolekcjaPrzeszkoda)
  {
    for (uint i = 0; i < kolekcjaPrzeszkoda.size(); i++)
    {
      if (kolekcjaPrzeszkoda[i]->isCollision(*this)) return true;
    }
    return false;
  }*/

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
  void MoveAnimation(double speed, double angleY){ 
    for (int i = 0; i < 100; ++i)
    {
      dron.Move(speed/100, angleY);
      //if (collision(kolekcjaPrzeszkoda))
      //dron.Move(-speed/100, angleY);
      dron.DrawAll();
      dron.getAPI()->redraw();
      usleep(10000);
    }
  }
  /*!
   * \brief calls addAngle(), DrawAll() and usleep(10000) 100 times
   * rotate dron - animation takes 1 sec to complete.
   * \param angleZ - angle in degrees.
   */ 
  void addAngleAnimation(double angleZ){ 
    for (int i = 0; i < 100; ++i)
    {
      dron.addAngle(angleZ/100);
      dron.DrawAll();
      dron.getAPI()->redraw();
      usleep(10000);
    }
  } 
  void Move(double speed, double angleY) {dron.Move(speed, angleY);};
  void setPicked(bool P){picked = P; colorPicked();}
  void Draw() {dron.DrawAll();}
  void UnDraw() {dron.UnDrawAll();}
};

#endif
