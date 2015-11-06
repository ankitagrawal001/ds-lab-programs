/*****************************************************************************
Design, develop, and execute a program in C++ to create a class
called OCTAL, which has the characteristics of an octal number.
Implement the following operations by writing an appropriate
constructor and an overloaded operator +.
    i. OCTAL h = x ; where x is an integer
    ii. int y = h + k ; where h is an OCTAL object and k is an
    integer.
Display the OCTAL result by overloading the operator <<. Also
display the values of h and y.
*****************************************************************************/

#include<iostream>

using namespace std;

class octal
{
    int oct,y;
    public:
    octal(int x)
    {
        y=x;
        int rem,a=0,p=1;
        while(x!=0)
        {
            rem=x%8;
            a+=(p*rem);
            p*=10;
            x=x/8;
        }
        oct=a;
    }
    int operator +(int k)
    {
        return y+k;
    }
    friend ostream& operator <<(ostream &,octal);
};

ostream & operator <<(ostream &out, octal o)
{
    out<<o.oct;
    return out;
}

int main()
{
    int x,k,y=0;
    cout<<"\nEnter the int value :";
    cin>>x;
    octal h = x;
    cout<<"\nThe octal value  = "<<h;
    cout<<"\nEnter the int value :";
    cin>>k;
    y=h+k;
    cout<<"\nThe int value :"<<y;
    return 0;
}

/**
    Author - Aman
**/
