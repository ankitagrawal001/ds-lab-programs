#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int s[100];
double compute(char symbol,double op1,double op2)
{
	switch(symbol)
	{
		case'+':return op1+op2;
		case'-':return op1-op2;
		case'*':return op1*op2;
		case'/':return op1/op2;
		case'^':
		case'$':return pow(op1,op2);
		}
	}
	
int main()
{
	double res,op1,op2;
	int top,i;
	char postfix[20],ch;
	printf("Enter postfix exp:");
	scanf("%s",postfix);
	top=-1;
	for(i=0;i<strlen(postfix);i++)
	{
		ch=postfix[i];
		
		if(isdigit(ch))
			s[++top]=ch-'0';
		else
		{
			op2=s[top--];
			op1=s[top--];
			res=compute(ch,op1,op2);
			s[++top]=res;
		}
	}
		res=s[top--];
		printf("\nthe result=%f\n",res);
}	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				
			
