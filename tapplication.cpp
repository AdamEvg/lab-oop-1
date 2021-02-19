#include "tapplication.h"
#include "tpolinom.h"
#include "number.h"
#include <iostream>
using namespace std;
TApplication::TApplication()
{

}
int TApplication:: exec(){
    int ch;
    number a=1, b=-2, c=1;
    while (true)
    {
        cout <<"1- coefficients" << endl;
        cout <<"2- value" << endl;
        cout <<"3- roots" << endl;
        cout <<"4- print (classic)"<< endl;
        cout <<"5- print (canonical)"<<endl;
        cout <<"0- exit"<<">"<< endl;
        cout <<">";
        cin >> ch;

        switch(ch)
        {
        case 1: {
            cout <<"Enter a,b,c:" << endl;
            cout << ">"; cin >>a>>b>>c;
        } break;
        case 2: {
            TPolinom p(a,b,c);
            number x;
            cout <<"Enter x:" << endl;
            cout <<">"; cin >> x;
            cout <<"P("<<x<<")="<<p.getValue(x) << endl;
        } break;
        case 3: {
            TPolinom p(a,b,c);
            number *x;
            x = p.getRoots();
            if(isIntegerRoots(x,p.getQuantityOfRoots(),p.getA(),p.getB(),p.getC())){
                //TODO напечатать корни в зависимости от того, что вернет getQuantityOfRoots()
            }else{
                //TODO корней над полем целых чисел нет
            }
            delete x;
        } break;
        case 4:{
            TPolinom p(a,b,c);
            p.setPrintMethod(EPrintModeClassic);
            cout << p << endl;
        } break;
        case 5:{
            TPolinom p(a,b,c);
            p.setPrintMethod(EPrintModeCanonic);
            cout << p << endl;
        } break;
        default:break;
        }
        if (ch == 0)
            break;
        }
    return 0;
}

//Функция принимает массив корней, количество корней и 3 коэфициента полинома
//Возвращается логическое значение, которое будет true, если существует
//решение над полем целых чисел и false, если решения над полем вещественных чисел не существует.
bool TApplication:: isIntegerRoots(number*roots,int quantityOfRoots,number a,number b,number c){
    if(quantityOfRoots==2){
        return (roots[0]+roots[1])==-(b/a) && roots[0]*roots[1]==(c/a) ;
    }else if(quantityOfRoots==1){
        return (roots[0]+roots[0])==-(b/a) && roots[0]*roots[0]==(c/a) ;
    }else{
        return false;
    }
}
