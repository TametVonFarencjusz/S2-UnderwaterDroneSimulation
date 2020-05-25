#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "rozmiar.h"
#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include "InterfejsDrona.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>
#include <string>

class Przeszkoda{
  protected:

  public:
  virtual bool isCollision(std::shared_ptr<InterfejsDrona> inDron) = 0; 
};

#endif
