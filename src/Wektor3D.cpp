#include "Wektor3D.hh"
#include <iostream>

int Wektor3D::countAll = 0;
int Wektor3D::countDestroyed = 0;

Wektor3D Wektor3D::Reverse(Wymiar W) const
{
  Wektor3D temp = (*this);
  switch(W)
  {
    case WymiarX: temp[0] *= -1; break;
    case WymiarY: temp[1] *= -1; break;
    case WymiarZ: temp[2] *= -1; break;
  }
  return temp; 
}



