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
    int getQuantityOfRoots();
    number getDiscriminant();
public:
    TPolinom();
    TPolinom(number,number,number);
    friend ostream& operator << (ostream&, TPolinom&);
    number value(number);
    void setPrintMethod(EPrintMode);
    number *getRoots();
};

#endif // TPOLINOM_H
