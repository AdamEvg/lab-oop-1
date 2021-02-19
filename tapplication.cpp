#include "tapplication.h"
#include "tpolinom.h"
#include "number.h"
#include <iostream>
using namespace std;
TApplication::TApplication()
{

}


    void TApplication:: exec(){
        int ch;
        number a=1, b=-2, c=1;
            while (true){
                ch = menu();
                switch (ch){
                case 1:{
                    cout <<"Enter a,b,c:" << endl;
                    cout << ">"; cin >>a>>b>>c;
                    break;
                }
                case 2:{
                        TPolinom p(a,b,c);
                        number x;
                        cout <<"Enter x:" << endl;
                        cout <<">";
                        cin >> x;
                        cout <<"P("<<x<<")="<<p.getValue(x) << endl;
                        break;
                }

                case 3:{
                    TPolinom p(a,b,c);
                    number* x=p.getRoots();
                    cout<<p.getA()<<p.getB()<<p.getC();
                    if(isIntegerRoots(x,p.getQuantityOfRoots(),p.getA(),p.getB(),p.getC())){
                        if(p.getQuantityOfRoots()==2){
                            cout<<"There are two roots:"<<" "
                                <<"x1="<<x[0]<<"\t"<<"x2="<<x[1];
                        }
                        if(p.getQuantityOfRoots()==1){
                             cout<<"There is one root:"<<" ""x="<<x[0];
                        }
                    }else{
                        cout<<"There are not roots on field on integer numbers";
                    }
                    delete x;
                     break;
                }
                case 4:
                {
                    TPolinom p(a,b,c);
                    p.setPrintMethod(EPrintModeClassic);
                    cout << p << endl;
                    break;
                }

                case 5:{
                    TPolinom p(a,b,c);
                    p.setPrintMethod(EPrintModeCanonic);
                    cout << p << endl;
                    break;
                }
                case 0:{
                    return;
                }

                default:{
                     break;
                }

                }
            }
        }

    int TApplication::menu(){
        int ch;
        cout <<"1- coefficients" << endl;
        cout <<"2- value" << endl;
        cout <<"3- roots" << endl;
        cout <<"4- print (classic)"<< endl;
        cout <<"5- print (canonical)"<<endl;
        cout <<"0- exit"<<">"<< endl;
        cout <<">";
        cin >> ch;
        return ch;
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
