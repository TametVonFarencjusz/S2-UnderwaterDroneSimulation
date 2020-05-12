//#include "Wektor.hh"
//#include <math.h>
#include <iostream>
#include <iomanip>

#include "Wektor.cpp"



template class Wektor<double,2>;
template Wektor<double,2> operator*(double a, const Wektor<double,2> & W2);
template std::istream & operator>>(std::istream & strm, Wektor<double,2> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,2> &Wek);

template class Wektor<double,3>;
template Wektor<double,3> operator*(double a, const Wektor<double,3> & W2);
template std::istream & operator>>(std::istream & strm, Wektor<double,3> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,3> &Wek);

//template class Wektor<double,4>;
