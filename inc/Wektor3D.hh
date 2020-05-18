#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <math.h>
#include <iostream>


/*!
 * \brief Vector in 3D
 * Class represents vector in 3D. 
 */
class Wektor3D : public Wektor<double, 3>{
protected:
  static int countAll;
  static int countDestroyed;

public:
  static int howManyAll(){return countAll;}
  static int howManyNow(){return countAll - countDestroyed;}


  Wektor3D() : Wektor<double, 3>() {++countAll;} //34
  Wektor3D(const Wektor3D & W) : Wektor<double, 3>(W) {++countAll;}
  Wektor3D(double x, double y, double z) {array[0] = x; array[1] = y; array[2] = z; ++countAll;} //8
  Wektor3D(const Wektor<double, 3> & M) : Wektor<double, 3>(M)  {++countAll;} //30
  /*!
   * \brief destructor, also add 1 to countDestroyed.
   */ 
  ~Wektor3D(){++countDestroyed;} //127
  /*!
   * \brief reverse one dimention of Vector3D
   * \param W - dimention (WymiarX, WymiarY, WymiarZ)
   */ 
  Wektor3D Reverse(Wymiar W) const;
};

#endif
