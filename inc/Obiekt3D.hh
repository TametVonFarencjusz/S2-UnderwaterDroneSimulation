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

  static int countAll;
  static int countDestroyed;

  public:
  /*!
   * \brief getter of static countAll
   * \return all created Obiekt3D - static int.
   */ 
  static int howManyAll(){return countAll;}
  /*!
   * \brief getter of static countAll - countDestroyed
   * \return count of existing Obiekt3D - static int.
   */ 
  static int howManyNow(){return countAll - countDestroyed;}
  /*!
   * \brief deleted non-parametric constructor to force using parametric.
   */ 
  Obiekt3D() = delete;
  /*!
   * \brief Constructor.
   * \param A - pointer api,
   * \param C - color name (std::string); basic is "black".
   */
  Obiekt3D(const Obiekt3D & O) : api(O.api), orientation(O.orientation), center(O.center), color(O.color), id(-1) {countAll++;}
  /*!
   * \brief Constructor.
   * \param A - pointer api,
   * \param C - color name (std::string); basic is "black".
   */
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A, std::string C = "black") : api(A), color(C), id(-1) {countAll++;}
  /*!
   * \brief Constructor
   * \param A - pointer on api,
   * \param M - rotation matrix (Orientation),
   * \param S - vector3D (Center),
   * \param C - color name (std::string); basic is "black",
   */
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A, const MacierzOb & M, const Wektor3D & S, std::string C = "black") :  api(A), orientation(M), center(S), color(C) , id(-1) {countAll++;}
  /*!
   * \brief Constructor
   * \param A - pointer on api,
   * \param S - vector3D (Center),
   * \param C - color name (std::string); basic is "black",
   */
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D & S, std::string C = "black") :  api(A), center(S), color(C) , id(-1) {countAll++;}
  /*!
   * \brief destructor that undraw Obiekt3D
   */ 
  ~Obiekt3D() {UnDraw(); countDestroyed++;}
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
   * \brief Getter - api
   * \return std::shared_ptr<drawNS::Draw3DAPI>.
   */
  std::shared_ptr<drawNS::Draw3DAPI> getAPI() const {return api;}
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
