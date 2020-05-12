#include <iostream>
#include <iomanip>

#include "Macierz.cpp"



template class Macierz<double,3>;
template std::istream& operator >> (std::istream &Strm, Macierz<double,3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double,3> &Mac);
template Macierz<double,3> operator *(double B, const Macierz<double,3> M);

