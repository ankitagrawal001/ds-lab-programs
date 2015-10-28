/*****************************************************************************
Design, develop, and execute a program in C to create a max heap
of integers by accepting one element at a time and by inserting it
immediately in to the heap. Use the array representation for the
heap. Display the array at the end of insertion phase.
*****************************************************************************/

#include<stdio.h>
#define MAX_SIZE 20

int insert_heap(int item ,int *a,int n)
{
    int c,p;
    if(n==MAX_SIZE)
    {
        printf("Heap is full!\n");
        return 0;
    }
    c=n;
    p=(c-1)/2;
    while(c!=0 && item>a[p])
    {
        a[c]=a[p];
        c=p;
        p=(c-1)/2;
    }
    a[c]=item;
    return n+1;
}

int delete_heap(int *a, int n)
{
    int p,c;
    if(n==0)
    {
        printf("Heap is Empty!\n");
        return 0;
    }
    printf("Item deleted = %d",a[0]);
    p=0;
    c=2*p+1;
    while(c>n)
    {
        if(c+1<n)
        {
            if(a[c]<a[c+1])
                c++;
        }
        a[p]=a[c];
        p=c;
        c=2*p+1;
    }
    return n-1;
}

void display(int *a,int n)
{
    int i;
    if (n==0)
    {
        printf("Heap is Empty!\n");
        return 0;
    }
    printf("The Elements of the max heap are:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

int main()
{
    int a[MAX_SIZE];
    int n=0,ch,item;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the item to insert : ");
                    scanf("%d",&item);
                    n=insert_heap(item,a,n);break;
            case 2:n=delete_heap(a,n);break;
            case 3:display(a,n);break;
            case 4:return 0;
            default:printf("Invalid Choice");
        }
    }
    return 0;
}
