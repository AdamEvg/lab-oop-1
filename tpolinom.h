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
    EPrintMode printMode;
    number a,b,c;
    bool isIntegerRoots(number*,int);
    number getDiscriminant();
public:
    TPolinom();
    TPolinom(number,number,number);
    int getQuantityOfRoots();
    friend ostream& operator << (ostream&, TPolinom&);
    number getValue(number);
    void setPrintMethod(EPrintMode);
    number *getRoots();
};

#endif // TPOLINOM_H
