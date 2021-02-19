#include "tapplication.h"

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
        cout <<"0- exit"+">"<< endl;
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
            cout <<"P("<<x<<")="<<p.value(x) << endl;
        } break;
        case 3: {
            TPolinom p(a,b,c);
            number *x = new number[2];
            int num_roots = p.roots(x);
            if (num_roots == 2) {
                cout <<"Roots:" << x[0] << "," << x[1] << endl;
            }
            if (num_roots == 1){
                cout <<"Root: "<<x[0]<< endl;
            }
            if (num_roots == 0){
                cout <<"No roots!" << endl;
            }
            delete x;
        } break;
        case 4:{
            TPolinom p(a,b,c);
            cout << p << endl;
        } break;
        case 5:{

        } break;
        default:break;
        }
        if (ch == 0)
            break;
        }
    return 0;
}
