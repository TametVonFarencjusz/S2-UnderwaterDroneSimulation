#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unistd.h>

#include "Dr3D_gnuplot_api.hh"
#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"
#include "Graniastoslup6.hh"
#include "InterfejsDrona.hh"
//#include "Przeszkoda.hh"
#include "PrzeszkodaProstopadloscian.hh"


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
    kolekcjaDron[i]->setColor("yellow");
  }
  kolekcjaDron[ID]->setColor("green");
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

  std::shared_ptr<Dno> dno = std::make_shared<Dno>(api, -20);
  kolekcjaPrzeszkoda.push_back(dno);
  dno->Draw(); 
  std::shared_ptr<Woda> woda = std::make_shared<Woda>(api, 20);
  kolekcjaPrzeszkoda.push_back(woda);
  woda->Draw();
  //std::shared_ptr<PrzeszkodaProstopadloscian> blok = std::make_shared<PrzeszkodaProstopadloscian>(api);
  //kolekcjaPrzeszkoda.push_back(blok);
  //blok->Draw();


  api->redraw();

  wait4key();
  
  std::shared_ptr<Dron> dron1 = std::make_shared<Dron>(api, 0.0, Wektor3D(10,-5,5));
  kolekcjaDron.push_back(dron1);
  kolekcjaPrzeszkoda.push_back(dron1);
  std::shared_ptr<Dron> dron2 = std::make_shared<Dron>(api, 90.0, Wektor3D(-10,-0,-10));
  kolekcjaDron.push_back(dron2);
  kolekcjaPrzeszkoda.push_back(dron2);
  std::shared_ptr<Dron> dron3 = std::make_shared<Dron>(api, 75.0, Wektor3D(5,-5,-5));
  kolekcjaDron.push_back(dron3);
  kolekcjaPrzeszkoda.push_back(dron3);
//6
  std::shared_ptr<PrzeszkodaProstopadloscian> blok1 = std::make_shared<PrzeszkodaProstopadloscian>(api, Wektor3D(0,0,45), Wektor3D(20,-10,-20), Wektor3D(5,5,5));
  kolekcjaPrzeszkoda.push_back(blok1);
  blok1 -> Draw();
  std::shared_ptr<PrzeszkodaProstopadloscian> blok2 = std::make_shared<PrzeszkodaProstopadloscian>(api, Wektor3D(0,0,0), Wektor3D(-20,-5,5), Wektor3D(2,2,2));
  kolekcjaPrzeszkoda.push_back(blok2);
  blok2 -> Draw();
  std::shared_ptr<PrzeszkodaProstopadloscian> blok3 = std::make_shared<PrzeszkodaProstopadloscian>(api, Wektor3D(45,45,45), Wektor3D(15,-15,-15), Wektor3D(3,3,3));
  kolekcjaPrzeszkoda.push_back(blok3);
  blok3 -> Draw();
  std::shared_ptr<PrzeszkodaProstopadloscian> blok4 = std::make_shared<PrzeszkodaProstopadloscian>(api, Wektor3D(-30,30,30), Wektor3D(20,-10, 0), Wektor3D(2.5,2.5,2.5));
  kolekcjaPrzeszkoda.push_back(blok4);
  blok4 -> Draw();
  std::shared_ptr<PrzeszkodaProstopadloscian> blok5 = std::make_shared<PrzeszkodaProstopadloscian>(api, Wektor3D(0,45,0), Wektor3D(20,20,20), Wektor3D(6,5,4));
  kolekcjaPrzeszkoda.push_back(blok5);
  blok5 -> Draw();
  std::shared_ptr<PrzeszkodaProstopadloscian> blok6 = std::make_shared<PrzeszkodaProstopadloscian>(api, Wektor3D(0,0,45), Wektor3D(-10,-3,3), Wektor3D(1,1,1));
  kolekcjaPrzeszkoda.push_back(blok6);
  blok6 -> Draw();



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
              if (elem->isCollision(kolekcjaDron[dronID])){
              flag = false;
              std::cout << std::endl << "!!!Wykryto przeszkode!!!" << std::endl;
              }
            }
            if (!flag)
            kolekcjaDron[dronID]->Move(-value/100, value2);
            kolekcjaDron[dronID]->Draw();
            usleep(10000);
          }while (flag && i < 100);
          //kolekcjaDron[dronID]->MoveAnimation(value, value2, kolekcjaPrzeszkoda);

        } else sayLoadError();
      }
      else sayLoadError();
    break;

    case 'p':
      std::cout << "Pozycja drona" << std::endl;
      std::cout << kolekcjaDron[dronID]->getCenter() << std::endl;
    break;

    case 'z':
      std::cout << "Zmiana drona(nr)>" << std::endl;
      do{
        std::cout << "Nr Drona (MAX:0 do " << kolekcjaDron.size() - 1 << ")>";
        std::cin >> value;
        if (std::cin.good() && (dronID < 0 || dronID >= kolekcjaDron.size())) std::cout << "Wartosc poza zakresem. Podaj ponownie" << std::endl;
      }while(std::cin.good() && (dronID < 0 || dronID >= kolekcjaDron.size())); 
      if (std::cin.good())
      {
        dronID = value;
        DronColor(kolekcjaDron, dronID);
        DrawDrons(kolekcjaDron);
      } else sayLoadError();
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
