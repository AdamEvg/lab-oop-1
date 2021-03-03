#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational
{
    // Числитель
    int numerator;

    // Знаменатель. По условию задачи знаменатель > 0
    unsigned int denominator;
    // Сокращение дроби
    void reduce();
    // НОК
    unsigned int getNOK(const Rational&);
    // НОД
    int getNOD(const int&,const int&);

public:
    Rational ();
    Rational(const int&);

    // Перегруженный оператор +
    Rational operator+ (const Rational&);

    // Бинарный перегруженный оператор -
    Rational operator- (const Rational&);

    // Унарный перегруженный оператор -
    Rational operator- ();

    // Перегруженный оператор *
    Rational operator* (const Rational&);

    // Перегруженный оператор * на число
    Rational operator* (const int&);

    // // Перегруженный оператор /
    Rational operator/ (const Rational&);

    // Перегруженный оператор == для сравнения дробей
    bool operator == (Rational);

    // Перегруженный операторы сравнения с числом
    bool operator > (int);
    bool operator < (int);
    bool operator == (int);

    //Дружественная функция вычисления корня
    friend Rational sqrt(Rational);
    // Перегрузка сout
    friend ostream& operator<< (ostream& os, const Rational&);
    // Перегрузка сin
    friend istream& operator>> (istream& is, Rational&);
};
#endif // RATIONAL_H
