#include "rational.h"
#include<math.h>

Rational::Rational():numerator(0),denominator(1)
{

}

Rational::Rational(const int& numerator)
{
    this->numerator = numerator;
    this->denominator = 1;
}


Rational Rational::operator+ (const Rational& Ratio)
{
    int NOK = getNOK(Ratio);
    Rational tmp;
    int c1 = NOK/denominator, c2 = NOK/Ratio.denominator;
    tmp.numerator = numerator*c1 + Ratio.numerator*c2;
    tmp.denominator = NOK;
    tmp.reduce();
    return tmp;
}

Rational Rational::operator- (const Rational& Ratio)
{
    int NOK = getNOK(Ratio);
    Rational tmp;
    int c1 = NOK/denominator, c2 = NOK/Ratio.denominator;
    tmp.numerator = numerator*c1 - Ratio.numerator*c2;
    tmp.denominator = NOK;
    tmp.reduce();
    return tmp;
}

Rational Rational::operator- (){
    Rational tmp;
    tmp.numerator = -numerator;
    tmp.denominator = denominator;
    return tmp;
}

Rational Rational::operator* (const Rational& Ratio)
{
    Rational tmp;
    tmp.numerator = numerator*Ratio.numerator;
    tmp.denominator = denominator*Ratio.denominator;
    tmp.reduce();
    return tmp;
}

Rational Rational:: operator* (const int& value){
    Rational tmp;
    tmp.numerator = numerator*value;
    tmp.denominator = denominator;
    tmp.reduce();
    return tmp;
}

Rational Rational::operator/ (const Rational& rational){
    Rational tmp;

    if(rational.numerator<0){
        tmp.numerator = -rational.denominator*numerator;
        tmp.denominator = rational.numerator*denominator;
    }else{
        tmp.numerator = rational.denominator*numerator;
        tmp.denominator = rational.numerator*denominator;
    }

    tmp.reduce();
    return tmp;
}

bool Rational::operator == (Rational rational)
{
    rational.reduce();
    return (denominator==rational.denominator && numerator==rational.numerator);

}

unsigned int Rational::getNOK(const Rational& rational)
{
    return (rational.denominator*denominator)/getNOD(rational.denominator,denominator);
}

void Rational::reduce()
{
    int nod = getNOD(numerator,denominator);
    numerator = numerator/nod;
    denominator = denominator/nod;
}

int Rational::getNOD(const int& a1,const int& b1)
{
    int a = abs(a1), b = abs(b1);
    while(a!=0 && b!=0){
        if (a>=b)
            a = a%b;
        else
            b = b%a;
    }
    return a+b;
}



bool Rational::operator > (int value){
    return this->numerator > value;
}

bool Rational::operator < (int value){
    return this->numerator < value;
}

bool Rational::operator == (int value){
    return this->numerator == value;
}

Rational sqrt(Rational rational){
    Rational newRational;
    newRational.numerator = sqrt(rational.numerator);
    newRational.denominator = sqrt(rational.denominator);
    newRational.reduce();
    return newRational;
}

ostream& operator << (ostream& os,const Rational& rational)
{
    if(rational.numerator % rational.denominator == 0){
        os<<rational.numerator/(int)rational.denominator;
    }else{
        rational.numerator<0?
                    os<<"-"<<"("<<-rational.numerator<<"/"<<rational.denominator<<")":
                    os<<"("<<rational.numerator<<"/"<<rational.denominator<<")";
    }
    return os;
}

istream& operator >> (istream& is,Rational& rational)
{
    is>>rational.numerator>>rational.denominator;
    return is;
}

