CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17 

__start__: Dron
	./Dron

Dron: obj/Dr3D_gnuplot_api.o obj/main.o obj/Wektor.o obj/Macierz.o obj/Dron.o obj/Prostopadloscian.o obj/Graniastoslup6.o obj/Plaszczyzna.o obj/Wektor3D.o
	g++ -o Dron obj/main.o obj/Dr3D_gnuplot_api.o obj/Wektor.o obj/Macierz.o obj/Dron.o obj/Prostopadloscian.o obj/Plaszczyzna.o obj/Graniastoslup6.o obj/Wektor3D.o -lpthread

obj/main.o: src/main.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/Macierz.o: src/Macierz.cpp src/MacierzC.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/MacierzC.cpp


obj/Wektor.o: src/Wektor.cpp src/WektorC.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/WektorC.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Graniastoslup6.o: src/Graniastoslup6.cpp inc/Graniastoslup6.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o obj/Graniastoslup6.o src/Graniastoslup6.cpp

obj/Plaszczyzna.o: src/Plaszczyzna.cpp inc/Plaszczyzna.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o obj/Plaszczyzna.o src/Plaszczyzna.cpp

AllHH: inc/MacierzOb.hh inc/Obiekt3D.hh
	touch inc/MacierzOb.hh inc/Obiekt3D.hh

clear:
	rm -f obj/*.o Dron
