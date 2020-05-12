#include "Dron.hh"
#include <iostream>

void Dron::DrawAll()
{
  UnDrawAll();
  DrawPropellerLeft();
  DrawPropellerRight();
  Draw();
  api->redraw();
}

  void Dron::Move(double speed, double angleY)
  { 
    //os X i os Y
    //center = center + speed * (1 - sin(angleY / 180  * M_PI) * sin(angleY / 180  * M_PI)) * Wektor3D(cos(angle / 180  * M_PI), sin(angle / 180  * M_PI), 0);
    //os Z
    //center = center + (speed) * Wektor3D(0, 0, sin(angleY / 180  * M_PI));
  
    center = center + speed * Wektor3D(cos(angleY / 180 * M_PI)*cos(angle / 180 * M_PI), sin(angle / 180 * M_PI)*cos(angleY / 180 * M_PI), sin(angleY / 180 * M_PI));

    speed = 0;
  }
 
  void Dron::MoveAnimation(double speed, double angleY)
  { 
    for (int i = 0; i < 100; ++i)
    {
      Move(speed/100, angleY);
      DrawAll();
      api->redraw();
      usleep(10000);
    }
  }
 
  void Dron::addAngleAnimation(double angleZ)
  { 
    for (int i = 0; i < 100; ++i)
    {
      addAngle(angleZ/100);
      DrawAll();
      api->redraw();
      usleep(10000);
    }
  }
  //Rysowanie
  void Dron::UnDrawAll()
  {
    UnDraw();
    propellerLeft.UnDraw();
    propellerRight.UnDraw();
  }

  void Dron::DrawPropellerRight()
  {
    Wektor3D tempPoint = MacierzOb(angle, WymiarZ) * point0;
    
    propellerLeft.setCenter(center - tempPoint);
    //propellerLeft.setPoint0(point0Propeller);
    Wektor3D tempAngle {-angle, 90, (center).dlugosc() * 50};
    MacierzOb tempMacierz(tempAngle);
    propellerLeft.setOrientation(tempMacierz);
    propellerLeft.Draw();
  }

  void Dron::DrawPropellerLeft()
  {
    Wektor3D tempPoint = MacierzOb(angle, WymiarZ) * point0.Reverse(WymiarY);

    propellerRight.setCenter(center - tempPoint);
    //propellerRight.setPoint0(point0Propeller);
    Wektor3D tempAngle {-angle, 90, -(center).dlugosc() * 50};
    MacierzOb tempMacierz(tempAngle);
    propellerRight.setOrientation(tempMacierz);
    propellerRight.Draw();
  }


