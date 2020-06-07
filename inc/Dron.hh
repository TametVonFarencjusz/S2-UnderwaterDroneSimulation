#ifndef DRON_HH
#define DRON_HH


#include "rozmiar.h"
#include "Prostopadloscian.hh"
#include "Wektor3D.hh"
#include "Przeszkoda.hh"
#include "InterfejsDrona.hh"
#include "Graniastoslup6.hh"
#include "Dr3D_gnuplot_api.hh"
#include <unistd.h>
#include <iostream>

class Dron : public Prostopadloscian, public InterfejsDrona, public Przeszkoda, public std::enable_shared_from_this<Dron>{
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
  public:
  /*!
   * \brief Constructor
   * \param A - pointer on api,
   */
  Dron(std::shared_ptr<drawNS::Draw3DAPI> A) : Prostopadloscian(A), propellerLeft(A, "yellow"), propellerRight(A, "yellow")
  {
    point0 = {3,2,2};
    angle = 0;
    anglePropeller = 0;
    //propellerRight.setOrientation(MacierzOb(90, WymiarY));
  }
  /*!
   * \brief Constructor
   * \param A - pointer on api,
   * \param Alfa - Angle in Z axis,
   * \param Srod - Wekto3D on position of the dron,
   * \param Punkt - Wekto3D on point0 of the dron (size of the dron),
   * \param C - color of the dron,
   */
  Dron(std::shared_ptr<drawNS::Draw3DAPI> A, double Alfa, const Wektor3D & Srod, const Wektor3D & Punkt = Wektor3D(3,2,2), std::string C = "yellow") : Prostopadloscian(A, Wektor3D(0,0,-Alfa), Srod, Punkt, C), propellerLeft(A, "yellow"), propellerRight(A, "yellow")
  {
    point0 = Punkt;
    angle = Alfa;
    anglePropeller = 0;
  }
  /*!
   * \brief Destructor - UnDraw the dron
   */
  ~Dron() {UnDraw();}
  /*!
   * \brief Setter - angle
   * \param A - angle in degrees.
   */
  void setAngle(double A) override {angle = A; orientation = MacierzOb(angle, WymiarZ);}
  /*!
   * \brief Getter - angle
   * \return angle in degrees.
   */
  double getAngle()  override {return angle;}
  /*!
   * \brief adding degrees to dron's angle 
   * \param A - angle in degrees.
   */
  void addAngle(double A) override {angle += A; orientation = MacierzOb(angle, WymiarZ);}
  /*!
   * \brief move dron - changes center parametrs
   * \param speed - distance that dron will go,
   * \param angleY - angle in degrees.
   */  
  void Move(double speed, double angleY) override;
  /*!
   * \brief calls UnDrawAll(), RefreshPropellerLeft(), RefreshPropellerRight() and Draw() for Dron and Propellers
   */
  void Draw() override;
  /*!
   * \brief undraws dron body (cuboid) and 2 propellers
   */
  void UnDraw() override;
  /*!
   * \brief calls Move(), DrawAll() and usleep(10000) 100 times
   * move dron - animation takes 1 sec to complete.
   * \param speed - distance that dron will go,
   * \param angleY - angle in degrees.
   */  
  void MoveAnimation (double speed, double angleY, std::vector<std::shared_ptr<Przeszkoda>> kolekcjaPrzeszkoda);
  /*!
   * \brief calls addAngle(), DrawAll() and usleep(10000) 100 times
   * rotate dron - animation takes 1 sec to complete.
   * \param angleZ - angle in degrees.
   */  
  void addAngleAnimation(double angleZ) override;

  Wektor3D getCenter() override {return Obiekt3D::getCenter();}

  double getRadius() {return point0.dlugosc();}
  void setColor (const std::string & C) override {color = C;}
  /////////////////////////////////////////
  bool isCollision(std::shared_ptr<InterfejsDrona> inDron) override;
};

#endif
