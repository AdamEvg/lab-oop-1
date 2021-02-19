#include "tpolinom.h"
#include "number.h"
#include<iostream>
#include<math.h>
using namespace std;
TPolinom::TPolinom(number a,number b,number c)
{
    printMode = EPrintModeClassic;
    this->a = a;
    this->b = b;
    this->c = c;
}
number TPolinom::getA(){
    return this->c;
}
number TPolinom::getB(){
    return this->c;
}
number TPolinom::getC(){
    return this->c;
}
void TPolinom::setPrintMethod(EPrintMode ePrintMethod)
{
    this->printMode = ePrintMethod;
}

number TPolinom::getValue(number x){
    return this->a*x*x+this->b+this->c;
}

int TPolinom::getQuantityOfRoots(){
    if(getDiscriminant()>0){
        return 2;
    }
    if(getDiscriminant()==0){
        return 1;
    }
    if(getDiscriminant()<0){
        return 0;
    }
    return -1;
}

number TPolinom::getDiscriminant(){
    return this->b*this->b - 4*this->a*this->c;
}


number* TPolinom::getRoots(){
    number * roots;
    if(getQuantityOfRoots()==2){
        roots = new int[2];
        roots[0] = (-b + sqrt(getDiscriminant()))/(2*a);
        roots[1] = (-b - sqrt(getDiscriminant()))/(2*a);
    }else if(getQuantityOfRoots()==1){
        roots = new int[1];
         roots[0] = -b/(2*a);
    }else{
        roots = NULL;
    }
    return roots;
}


ostream& operator << (ostream& os, TPolinom& p){
    if(p.printMode==EPrintModeClassic){
        if ((p.a > 0) || (p.a < 0))
        {
                os<< p.a<<"x^2";
                if (p.b > 0)
                {
                    os << "+" << p.b <<"x";
                    if (p.c == 0)
                        os << "";
                    if (p.c > 0)
                        os<<"+"<< p.c<<"";
                    else
                        os << p.c << "";
                }
                if (p.b < 0)
                {
                    os << p.b << "x";
                    if (p.c == 0)
                        os << "";
                    if (p.c > 0)
                        os<<"+"<< p.c<<"";
                    else
                        os << p.c << "";
                }
                if (p.b == 0)
                {
                    if (p.c == 0)
                        os << "";
                    if (p.c > 0)
                        os<<"+"<< p.c<<"";
                    else
                        os << p.c << "";
                }
        }
        if (p.a == 0)
        {
            if ((p.b > 0) || (p.b < 0))
            {
                os << p.b << "x";
                if (p.c == 0)
                    os << "";
                if (p.c > 0)
                    os<<"+"<< p.c<<"";
                else
                    os << p.c << "";
            }
            if (p.b == 0)
            {
                if (p.c == 0)
                    os << "";
                if (p.c > 0)
                    os<<"+"<< p.c<<"";
                else
                    os << p.c << "";
            }

        }
    }

    //TODO: Доделать канонический вид приусловии, что корни будут - => x+x1
    //TODO: Если корень один, надо сделать скобку, где квадрат умноженный на скобку
    number*roots = p.getRoots();
    if(p.printMode == EPrintModeCanonic){
        if(p.getQuantityOfRoots()==2){
             os<<p.a<<"(x-"<<roots[0]<<")"<<"(x-"<<roots[1]<<")";
        }else if(p.getQuantityOfRoots()==1){
              os<<p.a<<"(x-"<<roots[0]<<")"<<"^2";
        }else{
            os<<"There are not roots,\n so print with canonic mode is impossible!";
        }
    }
    return os;
    delete [] roots;
}




