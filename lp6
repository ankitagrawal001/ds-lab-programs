#include<iostream>
#include<string.h>
using namespace std;
class string1
{
	char *str;
	public:
	string1();
	string1( const char *);
	string1(const string1&);
	friend string1 operator+(string1 &,string1 &);
	friend ostream&operator<<(ostream&,string1 &);
};
string1::string1()
{
	cout<<"in default constructor\n";
	str=NULL;
}
string1::string1(const char *x)
{
	str=new char[strlen(x)+1];
	strcpy(str,x);
}
string1::string1(const string1 &s3)
{
	str=new char[strlen(s3.str)+1];
	strcpy(str,s3.str);
}
string1 operator+(string1 &s1,string1 &s2)
{
	string1 temp(s1);
	strcat(temp.str,s2.str);
	return temp;
}
ostream &operator<<(ostream &o,string1&s)
{
	o<<s.str;
	return o;
}

int main()
{
	string1 s1="VTU";
	string1 s2="BELGAUM";
	string1 s3=s1+s2;
	cout<<"\ns1="<<s1<<endl;
	cout<<"\ns2="<<s2<<endl;
	cout<<"\nafter string catenation s3="<<s3<<endl;
	return 0;
}
