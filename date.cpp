#include<iostream>
using namespace std;

int leapm[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int nleapm[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int leapyear=0;
class date{
		public:
			int dd,mm,yy;

			void getData(){
					int valid=0;
					do{
						cout<<"enter year:";
						cin>>yy;
						if(yy%4 ==0)
							leapyear=1;
						cout<<"enter month:";
						cin>>mm;
						if(mm<13)
							valid=1;
						cout<<"\n enter day:";
						cin>>dd;
						if((leapyear==1 && dd<=leapm[mm])||(leapyear==0 && dd<=nleapm[mm]))
							valid=1;
					}
					while(valid==0);
					return;

					}

			date operator + (int nod){
				nod+=dd;
				dd=0;
			
				while((leapyear==1 && nod>leapm[mm])||(leapyear==0 && nod>nleapm[mm])){
					if(leapyear==1)
						nod=nod-leapm[mm];
					else
						nod=nod-leapm[mm];
					mm++;
					if(mm>12)
					{
						mm=1;
						yy++;
						if(yy%4==0)
							leapyear=1;

					}
				}//end while
			dd=nod;
			return *this;
			}

			friend int operator -(date,date);
			friend ostream &operator <<(ostream &, date);

};

	int operator -(date d1, date d2){
		int count=0;
		while(d1.mm!=d2.mm || d1.yy != d2.yy){
			if(leapyear==1)
				count+=leapm[d2.mm];
			else
				count+=nleapm[d2.mm];
			d2.mm++;
			if(d2.mm>12){
				d2.mm=1;
				d2.yy++;
				if(d2.yy%4==0)
					leapyear=1;
					}
		}//end while
		count+=d1.dd-d2.dd;
		return count;
	}

	ostream &operator << (ostream &out , date ob){
		out<<ob.dd<<"/"<<ob.mm<<"/"<<ob.yy<<endl;
		return out;
		}

	int main()
	{
			date d1,d2;
			int nod,res;
			cout<<"INPUT CONDITION: date1 >= date 2\n";
			cout<<"enter date1:";
			d1.getData();
			cout<<"enter date2:";
			d2.getData();
			res=d1-d2;
			cout<<"\nThe difference between the dates:"<<res;
			cout<<"\nenter day to add:";
			cin>>nod;
			cout<<d1+nod;
			return 0;
	}	
	
	/* There are some minor errors in this program ... well rectify it soon. 
	
	
	Author - Melrick  */
