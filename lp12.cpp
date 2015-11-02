/*****************************************************************************
Design, develop, and execute a program in C++ to create a class
called DATE with methods to accept two valid dates in the form
dd/mm/yy and to implement the following operations by
overloading the operators + and -. After every operation the results
are to be displayed by overloading the operator <<.
i. no_of_days = d1 – d2; where d1 and d2 are DATE objects,
d1 >=d2 and no_of_days is an integer.
ii. d2 = d1 + no_of_days; where d1 is a DATE object and
no_of_days is an integer.
*****************************************************************************/

#include<iostream>

using namespace std;

bool isleap(int yy)
{
    if(yy%100)
    {
        if(yy%400) return true;
        else return false;
    }
    else
    {
        if(yy%4) return true;
        else return false;
    }
}



int m[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
            {0,31,29,31,30,31,30,31,31,30,31,30,31}};

class date
{
    public:
    int dd,mm,yy;
    bool isvalid()
    {
        bool valid=false;
        if(mm>=1 && mm<=12)
        {
            if(isleap(yy) && (dd<=m[0][mm] && dd>=1))
                valid=true;
            else if(!isleap(yy) && (dd<=m[1][mm] && dd>=1))
                valid=true;
        }
    }

    void getdate()
    {
        DATE:
        cout<<"Enter day";cin>>dd;
        cout<<"Enter month";cin>>mm;
        cout<<"Enter year";cin>>yy;
        if(!isvalid())
        {
            cout<<"Enterd date is not valid:";
            goto DATE;
        }
    }

    date operator + (int no_of_days)
    {
        dd+=no_of_days;
        while(dd>m[isleap(yy)][mm])
        {
            dd=dd-m[isleap(yy)][mm];
            mm++;
            if(mm>12)
            {
                yy++;
                mm=1;
            }
        }
        return *this;
    }

    friend int operator - (date d1,date d2);
    friend ostream& operator <<(ostream & ,date);
};

int operator - (date d1,date d2)
{
    int no_of_days=0;
    int nd1=0,nd2=0,yd=0;
    // to calculate no of days for d1 date
    for(int i=1;i<d1.mm;i++)
    {
        nd1+=m[isleap(d1.yy)][i];
    }
    nd1+=d1.dd;
    // to calculate no of days for d2 date
    for(int i=1;i<d2.mm;i++)
    {
        nd2+=m[isleap(d2.yy)][i];
    }
    nd2+=d2.dd;
    for(int i=d1.yy;i>d2.yy;i--)
    {
        if(isleap(i))
            yd+=366;
        else
            yd+=365;
    }
    no_of_days=yd+(nd1-nd2);
    return no_of_days;
}

ostream& operator <<(ostream & strem,date d1)
{
    strem<<d1.dd<<"/"<<d1.mm<<"/"<<d1.yy<<endl;
    return strem;
}

int main()
{
    date d1,d2;
    int nod;
    cout<<"Enter The date 1\n";d1.getdate();
    cout<<"Enter The date 2\n";d2.getdate();
    nod=d1-d2;
    cout<<nod;
    cout<<"Enter no of days added to date 1";cin>>nod;
    d2=d1+nod;
    cout<<d2;
    return 0;
}

/***
    Author - Aman
***/
