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
  std::shared_ptr<drawNS::Draw3DAPI> api;
  MacierzOb orientation;
  Wektor3D center;
  std::string color;
  int id;

  public:
  /*!
   * \brief deleted non-parametric constructor to force using parametric.
   */ 
  Obiekt3D() = delete;
  /*!
   * \brief Constructor.
   * \param A - pointer api,
   * \param C - color name (std::string); basic is "black".
   */
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A, std::string C = "black") : api(A), color(C), id(-1) {}
  /*!
   * \brief Constructor
   * \param A - pointer on api,
   * \param M - rotation matrix (Orientation),
   * \param S - vector3D (Center),
   * \param C - color name (std::string); basic is "black",
   */
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A, MacierzOb M, Wektor3D S, std::string C = "black") :  api(A), orientation(M), center(S), color(C) , id(-1) {}
  /*!
   * \brief destructor that undraw Obiekt3D
   */ 
  ~Obiekt3D() {UnDraw();}
  /*!
   * \brief Setter - center
   * \param Wektor3D.
   */
  void setCenter(const Wektor3D & W){center = W;}
  /*!
   * \brief Getter - center
   * \return Wektor3D.
   */
  Wektor3D getCenter() const {return center;}
  /*!
   * \brief Setter - orientation
   * \param MacierzOb.
   */
  void setOrientation(const MacierzOb & M){orientation = M;}
  /*!
   * \brief Getter - orientation
   * \return MacierzOb.
   */
  MacierzOb getOrientation() const {return orientation;}
  /*!
   * \brief Setter - color
   * \param std::string.
   */
  void setColor(const std::string & C){color = C;}
  /*!
   * \brief Getter - color
   * \return std::string.
   */
  std::string getColor() const {return color;}
  /*!
   * \brief Getter - id
   * \return int.
   */
  int getID() const {return id;}

  virtual void Draw() = 0;
  void UnDraw() {if (id != -1) {api->erase_shape(id); id = -1;}}
};

#endif
