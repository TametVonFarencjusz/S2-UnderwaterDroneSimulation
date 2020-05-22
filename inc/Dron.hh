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
  /*!
   * \brief angle of dron
   */
  double angle;
  /*!
   * \brief angle of propellers (axis z)
   */
  double anglePropeller;
  /*!
   * \brief Left propeller (Graniastoslup6)
   */
  Graniastoslup6 propellerLeft;
  /*!
   * \brief Right propeller (Graniastoslup6)
   */
  Graniastoslup6 propellerRight;
  /*!
   * \brief refreshes left propeller's parametrs
   */
  void RefreshPropellerLeft();
  /*!
   * \brief refreshes right propeller's parametrs
   */
  void RefreshPropellerRight();
  /*!
   * \brief adding degrees to dron's angle 
   * \param A - angle in degrees.
   */
  void addAngle(double A){angle += A; orientation = MacierzOb(angle, WymiarZ);}
  /*!
   * \brief move dron - changes center parametrs
   * \param speed - distance that dron will go,
   * \param angleY - angle in degrees.
   */  
  void Move(double speed, double angleY);

  public:
  /*!
   * \brief Constructor
   * \param A - pointer on api,
   */
  Dron(std::shared_ptr<drawNS::Draw3DAPI> A) : Prostopadloscian(A), propellerLeft(A, "yellow"), propellerRight(A, "yellow")
  {
    point0 = {3,2,2};
    anglePropeller = 0;
    //propellerRight.setOrientation(MacierzOb(90, WymiarY));
  }
  /*!
   * \brief Destructor
   */
  ~Dron() {UnDrawAll();}
  /*!
   * \brief Setter - angle
   * \param A - angle in degrees.
   */
  void setAngle(double A){angle = A; orientation = MacierzOb(angle, WymiarZ);}
  /*!
   * \brief Getter - angle
   * \return angle in degrees.
   */
  double getAngle() const {return angle;}
  /*!
   * \brief calls Move(), DrawAll() and usleep(10000) 100 times
   * move dron - animation takes 1 sec to complete.
   * \param speed - distance that dron will go,
   * \param angleY - angle in degrees.
   */  
  void MoveAnimation(double speed, double angleY);
  /*!
   * \brief calls addAngle(), DrawAll() and usleep(10000) 100 times
   * rotate dron - animation takes 1 sec to complete.
   * \param angleZ - angle in degrees.
   */  
  void addAngleAnimation(double angleZ);
  /*!
   * \brief calls UnDrawAll(), RefreshPropellerLeft(), RefreshPropellerRight() and Draw() for Dron and Propellers
   */
  void DrawAll();
  /*!
   * \brief undraws dron body (cuboid) and 2 propellers
   */
  void UnDrawAll();
};

#endif
