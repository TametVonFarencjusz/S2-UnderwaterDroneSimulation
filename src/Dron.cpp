#include "Dron.hh"
#include <iostream>

bool Dron::isCollision(std::shared_ptr<InterfejsDrona> inDron)
{
  if (inDron->getCenter() == center) return false;
  if ((inDron->getCenter() - center).dlugosc() < point0.dlugosc() + inDron->getRadius())
    return true;
  return false;
}

 
void Dron::MoveAnimation(double speed, double angleY, std::vector<std::shared_ptr<Przeszkoda>> kolekcjaPrzeszkoda){ 
  bool flag = true; 
  uint i = 0;
  do{
      i++;  
      Move(speed/100, angleY);
      for (auto elem : kolekcjaPrzeszkoda)
      {
        if (elem->isCollision(shared_from_this())){
        flag = false;
        std::cout << std::endl << "!!!Wykryto przeszkode!!!" << std::endl;
        }
      }
      if (!flag) Move(-speed/100, angleY);
      Draw();
      usleep(10000);
    }while (flag && i < 100);
}
 
void Dron::addAngleAnimation(double angleZ){ 
  for (int i = 0; i < 100; ++i)
  {
    addAngle(angleZ/100);
    Draw();
    api->redraw();
    usleep(10000);
  }
}

void Dron::Draw(){
  UnDraw();
  orientation = MacierzOb(angle, WymiarZ);
  //std::cout << color;
  anglePropeller+= 4;
  RefreshPropellerLeft();
  RefreshPropellerRight();
  propellerLeft.Draw();
  propellerRight.Draw();
  Prostopadloscian::Draw();
  api->redraw();
}

void Dron::Move(double speed, double angleY){ 
  center = center + speed * Wektor3D(cos(angleY / 180 * M_PI)*cos(angle / 180 * M_PI), sin(angle / 180 * M_PI)*cos(angleY / 180 * M_PI), sin(angleY / 180 * M_PI));
}

void Dron::UnDraw(){
  Prostopadloscian::UnDraw();
  propellerLeft.UnDraw();
  propellerRight.UnDraw();
}

void Dron::RefreshPropellerRight(){
  propellerRight.setColor(color);
  propellerRight.setCenter(center - orientation * point0);
  propellerRight.setOrientation(Wektor3D(-angle, 90, anglePropeller));
}

void Dron::RefreshPropellerLeft(){
  propellerLeft.setColor(color);
  propellerLeft.setCenter(center - orientation * point0.Reverse(WymiarY));
  propellerLeft.setOrientation(Wektor3D(-angle, 90, -anglePropeller));
}


