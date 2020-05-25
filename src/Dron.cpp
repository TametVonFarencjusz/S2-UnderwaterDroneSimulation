#include "Dron.hh"
#include <iostream>

void Dron::DrawAll(){
  UnDrawAll();
  orientation = MacierzOb(angle, WymiarZ);
  //std::cout << color;
  anglePropeller+= 4;
  RefreshPropellerLeft();
  RefreshPropellerRight();
  propellerLeft.Draw();
  propellerRight.Draw();
  Draw();
  api->redraw();
}

void Dron::Move(double speed, double angleY){ 
  center = center + speed * Wektor3D(cos(angleY / 180 * M_PI)*cos(angle / 180 * M_PI), sin(angle / 180 * M_PI)*cos(angleY / 180 * M_PI), sin(angleY / 180 * M_PI));
}

void Dron::UnDrawAll(){
  UnDraw();
  propellerLeft.UnDraw();
  propellerRight.UnDraw();
}

void Dron::RefreshPropellerRight(){
  //static double angleStaticRight;
  //angleStaticRight += 4;
  propellerRight.setColor(color);
  propellerRight.setCenter(center - orientation * point0);
  propellerRight.setOrientation(Wektor3D(-angle, 90, anglePropeller));
}

void Dron::RefreshPropellerLeft(){
  //static double angleStaticLeft;
  //angleStaticLeft -= 4;
  propellerLeft.setColor(color);
  propellerLeft.setCenter(center - orientation * point0.Reverse(WymiarY));
  propellerLeft.setOrientation(Wektor3D(-angle, 90, -anglePropeller));
}


