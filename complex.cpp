#include "complex.h"

Complex::Complex()
{

}

Complex::Complex(const int& r)
{
    re = r;
    im = 0;
}

Complex Complex:: operator*(Complex c){
    Complex t;
    t.re = re*c.re - im*c.im;
    t.im = re*c.im - im*c.re;
    return t;
}

Complex Complex:: operator+(Complex c){
    Complex t;
    t.re = re+c.re;
    t.im = im+c.im;
    return t;
}

ostream& operator << (ostream& os,Complex complex)
{
    os<<"("<<complex.re<<"+"<<complex.im<<"i"<<")";
    return os;
}

istream& operator >> (istream& is,Complex complex)
{
    is>>complex.re>>complex.im;
    return is;
}
