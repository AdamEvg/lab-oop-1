#ifndef TPOLINOM_H
#define TPOLINOM_H
#include "number.h"
#include<iostream>
using namespace std;

enum EPrintMode{
    EPrintModeClassic,EPrintModeCanonic
};

class TPolinom
{
    //Область видимости по умолчанию приватная
    EPrintMode printMode;
    number a,b,c;

    number getDiscriminant();
public:
    TPolinom();
    TPolinom(number,number,number);
    int getQuantityOfRoots();
    friend ostream& operator << (ostream&, TPolinom&);
    number getValue(number);
    number getA();
    number getB();
    number getC();
    void setPrintMethod(EPrintMode);
    number *getRoots();
};

#endif // TPOLINOM_H
