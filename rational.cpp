#include "rational.h"
#include<math.h>

Rational::Rational()
{

}

Rational::Rational(const int& r)
{
    a = r;
    b = 1;
}

Rational Rational:: operator*(Rational rational){
    Rational newRational;
    newRational.a = a*rational.a;
    newRational.b = b*rational.b;
    reduce(newRational);
    return newRational;
}

Rational Rational:: operator*(int value){
    Rational newRational;
    newRational.a = a*value;
    newRational.b = b;
    reduce(newRational);
    return newRational;
}

Rational Rational:: operator/(Rational rational){
    Rational newRational;
    newRational.a = a*rational.b;
    newRational.b = b*rational.a;
    reduce(newRational);
    return newRational;
}

Rational Rational:: operator+(Rational rational){
    Rational newRational;
    if(rational.b !=b){
        newRational.a = a*rational.b+rational.a*b;
        newRational.b = rational.b*b;
    }else{
        newRational.a = a+rational.a;
        newRational.b = b;
    }
    reduce(newRational);
    return newRational;
}

//Бинарный минус
Rational Rational:: operator-(Rational rational){
    Rational newRational;
    if(rational.b !=b){
        newRational.a = a*rational.b-rational.a*b;
        newRational.b = rational.b*b;
    }else{
        newRational.a = a-rational.a;
        newRational.b = b;
    }
    reduce(newRational);
    return newRational;
}

//Унарный минус
Rational Rational:: operator-(){
    Rational newRational;
    newRational.a = -a;
    newRational.b = b;
    return newRational;
}


bool Rational::operator== (Rational rational){
    return (a==rational.a)&&(b==rational.b);
}

bool Rational::operator== (int value){
    return (a==value);
}

bool Rational::operator>(int value){
    return a > value;
}

bool Rational::operator<(int value){
    return a < value;
}

Rational sqrt(Rational rational){
    Rational newRational;
    newRational.a = sqrt(rational.a);
    newRational.b = sqrt(rational.b);
    rational.reduce(newRational);
    return newRational;
}

void Rational::reduce(Rational &rational){
    int m = (rational.a < rational.b ? rational.a : rational.b );
    while ( rational.a % m == 0 && rational.b % m == 0 && m != 1 ) rational.a /= m, rational.b /= m, --m;
}

ostream& operator << (ostream& os,Rational rational)
{
    if(rational.a % rational.b == 0){
        os<<rational.a/rational.b;
    }else{
        os<<"("<<rational.a<<"/"<<rational.b<<")";
    }

    return os;
}

istream& operator >> (istream& is,Rational& rational)
{
    is>>rational.a>>rational.b;
    return is;
}

