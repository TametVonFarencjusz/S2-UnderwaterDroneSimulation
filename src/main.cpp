#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unistd.h>
#include <memory>

#include "Dr3D_gnuplot_api.hh"
#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"
#include "Graniastoslup6.hh"
#include "InterfejsDrona.hh"
#include "Przeszkoda.hh"

#include "Dno.hh"
#include "Woda.hh"

using std::vector;
using std::string;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void DrawDrons(std::vector<std::shared_ptr<InterfejsDrona>> kolekcjaDron){
  for (uint i = 0; i < kolekcjaDron.size(); i++)
  {
    kolekcjaDron[i]->Draw();
  }
}

void DronColor(std::vector<std::shared_ptr<InterfejsDrona>> kolekcjaDron, uint ID){
  for (uint i = 0; i < kolekcjaDron.size(); i++)
  {
    kolekcjaDron[i]->setPicked(false);
  }
  kolekcjaDron[ID]->setPicked(true);
}

void sayLoadError(){
  std::cout << "ERROR: Blad podczas wczytywania!!!!" << std::endl;
}

void sayCountWektor3D(){
      std::cout << "Aktualna ilosc obiektow Wektor3D: " << Wektor3D::howManyNow() << std::endl ; //Aktualna  
      std::cout << "Laczna ilosc obiektow Wektor3D: "   << Wektor3D::howManyAll() << std::endl;
}

void sayCountObiekt3D(){
      std::cout << "Aktualna ilosc obiektow Obiekt3D: " << Obiekt3D::howManyNow() << std::endl ; //Aktualna  
      std::cout << "Laczna ilosc obiektow Obiekt3D: "   << Obiekt3D::howManyAll() << std::endl;
}

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-30,30,-30,30,-30,30,-1));

  //std::vector<>> pointVectorBig
  std::vector<std::shared_ptr<InterfejsDrona>> kolekcjaDron;
  std::vector<std::shared_ptr<Przeszkoda>> kolekcjaPrzeszkoda;

  //Dno dno(api, -20, "orange");
  std::shared_ptr<Dno> dno = std::make_shared<Dno>(api, -20, "orange");
  kolekcjaPrzeszkoda.push_back(dno);
  dno->Draw();  

  Woda woda(api, 20);
  woda.Draw();

  api->redraw();

  wait4key();
  
  std::shared_ptr<InterfejsDrona> dronA = std::make_shared<InterfejsDrona>(api, 90.0, Wektor3D(3,3,3));
  kolekcjaDron.push_back(dronA);
  std::shared_ptr<InterfejsDrona> dronB = std::make_shared<InterfejsDrona>(api, 90.0, Wektor3D(-10,-3,-3));
  kolekcjaDron.push_back(dronB);
  //InterfejsDrona dronB(api, 90.0, Wektor3D(-3,-3,-3));
  //kolekcjaDronow.push_back(dronB);
  //dronA.Draw();

  //Dron D(api);
  //D.DrawAll();

  
  uint dronID = 0;
  char option = 'm'; 
  double value;
  double value2;

  DronColor(kolekcjaDron, dronID); 
  DrawDrons(kolekcjaDron);

  std::cout << std::endl;
  do
  {
    switch (option){
    case 'm':
      std::cout << "r - zadaj ruch na wprost" << std::endl;
      std::cout << "o - zadaj zmiane orientacji" << std::endl;
      std::cout << "m - wyswietl menu" << std::endl;
      std::cout << "p - pozycja drona" << std::endl;
      std::cout << "z - zmien drona" << std::endl;
      std::cout << "k - koniec dzialania programu" << std::endl;
    break;

    case 'o':
      std::cout << std::endl << "Podaj wartosc kata obrotu w stopniach." << std::endl;
      std::cout << "Wartosc kata>" << std::endl;
      std::cin >> value; 
      if (std::cin.good()){
        kolekcjaDron[dronID]->addAngleAnimation(value);
      } else sayLoadError();
    break;

    case 'r':
      std::cout << std::endl << "Podaj wartosc kata (opadania/wznoszenia) w stopniach." << std::endl;
      do 
      {
        std::cout << "Wartosc kata [-90,90]>";
        std::cin >> value2; 
        if (std::cin.good() && (value2 < -90 || value2 > 90)) std::cout << "Wartosc poza ograniczeniem. Podaj ponownie" << std::endl;
      } while(std::cin.good() && (value2 < -90 || value2 > 90));      
      if (std::cin.good())
      {
        std::cout << std::endl << "Podaj wartosc odleglosci, na ktora ma sie przemiescic dron." << std::endl;
        do 
        {
          std::cout << "Wartosc odleglosci>";
          std::cin >> value;
          if (std::cin.good() && value < 0) std::cout << "Wartosc ujemna. Podaj ponownie" << std::endl;
        } while(std::cin.good() && value < 0); 
        if (std::cin.good())
        {
          bool flag = true; 
          uint i = 0;
          do{
            i++;  
            kolekcjaDron[dronID]->Move(value/100, value2);
            for (auto elem : kolekcjaPrzeszkoda)
            {
              if (elem->isCollision(kolekcjaDron[dronID]))
              flag = false;
            }
            if (!flag)
            kolekcjaDron[dronID]->Move(-value/100, value2);
            kolekcjaDron[dronID]->Draw();
            usleep(10000);
          }while (flag && i < 100);
          //kolekcjaDron[dronID]->MoveAnimation(value, value2);


        } else sayLoadError();
      }
      else sayLoadError();
    break;

    case 'p':
      std::cout << "Pozycja drona" << std::endl;
      std::cout << kolekcjaDron[dronID]->getDron().getCenter() << std::endl;
    break;

    case 'z':
      std::cout << "Zmiana drona(nr)>" << std::endl;
      do{
        std::cout << "Nr Drona (MAX:0 do " << kolekcjaDron.size() - 1 << ")>";
        std::cin >> dronID;
        if (std::cin.good() && (dronID < 0 || dronID >= kolekcjaDron.size())) std::cout << "Wartosc poza zakresem. Podaj ponownie" << std::endl;
      }while(std::cin.good() && (dronID < 0 || dronID >= kolekcjaDron.size())); 
     DronColor(kolekcjaDron, dronID); 
     DrawDrons(kolekcjaDron);
    break;
    }
    if (!std::cin.good())
    {
      std::cin.clear( ); 
      std::cin.ignore(10000,'\n');
    }
    std::cout << std::endl; sayCountWektor3D(); std::cout << std::endl;
    std::cout << std::endl; sayCountObiekt3D(); std::cout << std::endl;
    std::cout << "Twoj wybor, m - menu>";
    std::cin >> option;
    std::cout << std::endl;
  } while(option != 'k');
  //4 - 35
  wait4key();
}
