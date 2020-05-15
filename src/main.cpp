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

#include "Dno.hh"
#include "Woda.hh"

using std::vector;
using std::string;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void sayLoadError(){
  std::cout << "ERROR: Blad podczas wczytywania!!!!" << std::endl;
}

void sayCountWektor3D(){
      std::cout << "Aktualna ilosc obiektow Wektor3D: " << Wektor3D::howManyNow() << std::endl ; //Aktualna  
      std::cout << "Laczna ilosc obiektow Wektor3D: "   << Wektor3D::howManyAll() << std::endl;
}

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-20,20,-20,20,-20,20)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  api->change_ref_time_ms(-1); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  
  Wektor3D A(2,3,2);

  Dno dno(api, -10, "orange");
  dno.Draw();  

  Woda woda(api, 10);
  woda.Draw();

  api->redraw();

  wait4key();
  

  Dron D(api);
  D.DrawAll();

  api->redraw();
  char option = 'm'; 
  double value;
  double value2;

  std::cout << std::endl;
  do
  {
    switch (option){
    case 'm':
      std::cout << "r - zadaj ruch na wprost" << std::endl;
      std::cout << "o - zadaj zmiane orientacji" << std::endl;
      std::cout << "m - wyswietl menu" << std::endl;
      std::cout << "p - pozycja drona" << std::endl;
      std::cout << "k - koniec dzialania programu" << std::endl;
    break;
    case 'o':
      std::cout << std::endl << "Podaj wartosc kata obrotu w stopniach." << std::endl;
      std::cout << "Wartosc kata>" << std::endl;
      std::cin >> value; 
      if (std::cin.good()){
        D.addAngleAnimation(value);
      } else sayLoadError();
    break;
    case 'r':
      std::cout << std::endl << "Podaj wartosc kata (opadania/wznoszenia) w stopniach." << std::endl;
      do{
        std::cout << "Wartosc kata [-90,90]>";
        std::cin >> value2; 
        if (std::cin.good() && (value2 < -90 || value2 > 90)) std::cout << "Wartosc poza ograniczeniem. Podaj ponownie" << std::endl;
      }while(std::cin.good() && (value2 < -90 || value2 > 90));      
      if (std::cin.good()){
        std::cout << std::endl << "Podaj wartosc odleglosci, na ktora ma sie przemiescic dron." << std::endl;
        do{
          std::cout << "Wartosc odleglosci>";
          std::cin >> value;
          if (std::cin.good() && value < 0) std::cout << "Wartosc ujemna. Podaj ponownie" << std::endl;
        }while(std::cin.good() && value < 0); 
        if (std::cin.good()){
          D.MoveAnimation(value, value2);
        } else sayLoadError();
      }
      else sayLoadError();
    break;
    case 'p':
      std::cout << "Pozycja drona" << std::endl;
      std::cout << D.getCenter() << std::endl;
      
    break;
    }
    if (!std::cin.good())
    {
      std::cin.clear( ); 
      std::cin.ignore(10000,'\n');
    }
    //D.DrawAll();
    std::cout << std::endl; sayCountWektor3D(); std::cout << std::endl;
    std::cout << "Twoj wybor, m - menu>";
    std::cin >> option;
    std::cout << std::endl;
  } while(option != 'k');
  //4 - 35
  wait4key();
}
