/*****************************************************************************
Design, develop, and execute a program in C to simulate the
working of a queue of integers using an array. Provide the following
operations:
a. Insert
b. Delete
c. Display
*****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define N 10

int queue[N],front=0,rear=-1;item;

void qinsert()
{
    if(rear==N-1)
        printf("\n Queue Overflow");
    else
    {
        printf("\n Enter item : ");
        scanf("%d",&item);
        queue[++rear]=item;
    }
    return;
}

void qdelete()
{
    if(rear==front-1)
        printf("\n Queue Underflow");
    else if(front==rear)
    {
        printf("\n the deleted items is %d",queue[front++]);
        front=0;rear=-1;
    }
    else
        printf("\ The deleted item is %d",queue[front++]);
    return;
}

void qdisplay()
{
    int i;
    if(rear==front-1)
        printf("\n Queue is empty");
    else
    {
        for(i=front;i<rear;i++)
        {
            printf("\n %d \t",queue[i]);
        }
        printf("\n Front of Queue is : %d\n Rear of queue is : %d",queue[front],queue[rear]);
    }
    return;
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n Queue Implementation using array \n\t1. Queue Insert\n\t2. Queue Delete\n\t3. Queue Display\n\t4. Exit system\n\t::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:qinsert();break;
            case 2:qdelete();break;
            case 3:qdisplay();break;
            case 4:printf("\n Thank You\n");return 0;
        }
    }
    return 0;
}

/***
    Author - Aman
***/
