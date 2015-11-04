/**********************************************************************
Design, develop, and execute a program in C to implement a doubly
linked list where each node consists of integers. The program should
support the following operations:
i. Create a doubly linked list by adding each node at the front.
ii. Insert a new node to the left of the node whose key value is
    read as an input.
iii. Delete the node of a given data if it is found, otherwise
    display appropriate message.
iv. Display the contents of the list.
**********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,n,type)\
p=(type*)malloc(n*sizeof(type));\
if(p==NULL)\
{\
printf("insufficient memory");\
free(p);\
exit(0);}

struct node
{
int info;
struct node *llink;
struct node *rlink;
};

typedef struct node *NODE;

NODE insert_front(NODE head,int item)
{
    NODE temp,cur;
    MALLOC(temp,1,struct node);
    temp->info=item;
    cur=head->rlink;
    head->rlink=temp;
    temp->llink=head;
    temp->rlink=cur;
    cur->llink=temp;
    return head;
}
NODE insert_leftspec(NODE head,int key,int elem)
{
    NODE temp,prev,cur;
    MALLOC(temp,1,struct node);
    temp->info=elem;
    if(head->rlink==head)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        cur=head->rlink;
        while(cur!=head)
        {
            cur=cur->rlink;
            if(key==cur->info)
                break;
        }
        if(cur==head)
        {
            printf("unsuccessful search\n");
            return;
        }
        prev=cur->llink;
        cur->llink=temp;
        temp->rlink=cur;
        temp->llink=prev;
        prev->rlink=temp;
        return head;
    }
}

NODE delete_spec(NODE head,int key)
{
NODE prev,cur,next;
    if(head->rlink==head)
    {
        printf("list is empty");
        return;
    }
    else
    {
        cur=head->rlink;
        while(cur!=head)
        {
            if(cur->info==key)
                break;
            cur=cur->rlink;
        }
        if(cur==head)
        {
            printf("unsuccessful search\n");
            return;
        }
        prev=cur->llink;
        next=cur->rlink;
        prev->rlink=next;
        next->llink=prev;
        free(cur);
        return (head);
    }
}

void display(NODE head)
{
    NODE cur;
    if(head->rlink==head)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        cur=head->rlink;
        while(cur!=head)
        {
            printf("%d\t",cur->info);
            cur=cur->rlink;
        }
    }
}

int key,elem;

int main()
{
    NODE head;
    int choice;
    MALLOC(head,1,struct node);
    head->llink=head->rlink=head;
    while(1)
    {
        printf("enter the choice\n1.insert from front\n2.insert at specific point\n3.delete specific node\n4.display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter  the element to be inserted at front:");
                    scanf("%d",&elem);
                    insert_front(head,elem);
                    break;
            case 2:printf("enter the key :");
                    scanf("%d",&key);
                    printf("\nenter the element:");
                    scanf("%d",&elem);
                    insert_leftspec(head,key,elem);
                    break;
            case 3:printf("enter the key to be deleted:");
                    scanf("%d",&key);
                    delete_spec(head,key);
                    break;
            case 4:display(head);
                    break;
            default:exit(1);
        }
    }
    return 0;
}
/*Author-Dhanya*/
