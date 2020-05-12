#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include "rozmiar.h"
#include "Macierz.hh"
#include "Wektor3D.hh"
#include <math.h>
#include <iostream>



class MacierzOb : public Macierz<double, 3>{
public:
  
  MacierzOb() : Macierz<double, 3>() 
  {
    for (int i = 0; i < 3; ++i)
    array[i][i] = 1;
  }  
  MacierzOb(Wektor3D angle)
  {
    (*this) = MacierzOb(angle[0], WymiarX) * MacierzOb(angle[1], WymiarY) * MacierzOb(angle[2], WymiarZ);
  }
  MacierzOb(double alfa, Wymiar w)
  {
    Obrot(alfa, w);
  }

  MacierzOb(const Macierz<double, 3> M) : Macierz<double, 3>(M) {}

  MacierzOb Obrot(double alfa, Wymiar w)
  {
    double tempAlfa = alfa / 180 * M_PI;
    switch (w) {
    case WymiarX:
      array[1][1] = cos(tempAlfa);
      array[1][2] = sin(tempAlfa);
      array[2][1] = -sin(tempAlfa);
      array[2][2] = cos(tempAlfa);
    //Zera
      array[0][2] = 0;
      array[0][1] = 0;
      array[2][0] = 0;
      array[1][0] = 0;
    //Jeden
      array[0][0] = 1;
    break;
    case WymiarY:
      array[2][2] = cos(tempAlfa);
      array[2][0] = sin(tempAlfa);
      array[0][2] = -sin(tempAlfa);
      array[0][0] = cos(tempAlfa);
    //Zera
      array[1][0] = 0;
      array[2][1] = 0;
      array[0][1] = 0;
      array[1][2] = 0;
    //Jeden
      array[1][1] = 1;
    break;
    case WymiarZ:

      array[0][0] = cos(tempAlfa);
      array[0][1] = sin(tempAlfa);
      array[1][0] = -sin(tempAlfa);
      array[1][1] = cos(tempAlfa);
    //Zera
      array[2][0] = 0;
      array[2][1] = 0;
      array[0][2] = 0;
      array[1][2] = 0;
    //Jeden
      array[2][2] = 1;
    break;
    }
    return (*this);
  }
};

#endif
