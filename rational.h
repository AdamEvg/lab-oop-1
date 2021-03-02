#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;
class Rational
{
    int a,b;
    //По условию b>0
    void reduce(Rational&); //Сокращение
public:
    Rational();
    Rational(const int&);


    Rational operator*(Rational);//Дробь на дробь
    Rational operator*(int);//Дробь на число

    bool operator>(int);
    bool operator==(int);
    bool operator<(int);

    Rational operator/(Rational);
    Rational operator+(Rational);

    Rational operator-();//Унарный
    Rational operator-(Rational);//Бинарный

    bool operator==(Rational);

    friend Rational sqrt(Rational);

    friend ostream& operator << (ostream&,Rational);
    friend istream& operator >> (istream&,Rational&);
};

#endif // RATIONAL_H
