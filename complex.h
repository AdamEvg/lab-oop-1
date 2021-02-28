#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;
class Complex
{
    double re,im;
public:
    Complex();
    Complex(const int&);


    Complex operator*(Complex);
    Complex operator+(Complex);
    friend ostream& operator << (ostream&,Complex);
    friend istream& operator >> (istream&,Complex);
};

#endif // COMPLEX_H
