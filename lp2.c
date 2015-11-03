/****************************************************************************
Design, develop, and execute a program in C to convert a given
valid parenthesized infix arithmetic expression to postfix expression
and then to print both the expressions. The expression consists of
single character operands and the binary operators + (plus), -
(minus), * (multiply) and / (divide).
****************************************************************************/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 200

char s[MAX];
int top=-1; char elem;

char precedence(char elem)
{
    switch(elem)
    {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        case '^' : return 3;
        case ')' :
        case '#' : return 0;
    }
}

void push(char element)
{
    s[++top]=element;
}

char pop()
{
    return s[top--];
}

int main()
{
    char infix[MAX],postfix[MAX],ch;
    int i=0,j=0;
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    push('#');
    for(i=0;i<strlen(infix);i++)
    {
        ch=infix[i];
        if(isalnum(ch))
            postfix[j++]=ch;
        else if(ch=='(')
            push(ch);
        else if(ch==')')
        {
            while(s[top]!='(')
            {
                postfix[j++]=pop();
            }
            elem=pop();
        }
        else
        {
            while(precedence(s[top])>=precedence(ch))
                postfix[j++]=pop();
            push(ch);
        }
    }
    while(s[top]!='#')
        postfix[j++]=pop();
    postfix[j]='\0';
    printf("Infix expression is %s \n",infix);
    printf("Postfix expression is %s \n",postfix);
    return 0;
}
