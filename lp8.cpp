/*********************************************************************************************
Design, develop, and execute a program in C++ to create a class
called LIST (linked list) with member functions to insert an element
at the front of the list as well as to delete an element from the front
of the list. Demonstrate all the functions after creating a list object.
*********************************************************************************************/

#include<iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
};

class list
{
    node *f;
    public:
    list()
    {
        f = NULL;
    }

    void insert(int n)
    {
        node *p=new node;
        p->info=n;
        p->next=f;
        f = p;
    }

    void del()
    {
        node *temp=f;
        if(f==NULL)
            cout<<"List is empty";
        else
        {
            cout<<"The deleted element is :"<<f->info<<endl;
            f=f->next;
            delete(temp);
        }
    }

    void display()
    {
        node *temp = f;
        if(f==NULL)
        {
            cout<<"List is Empty";
        }
        else
        {
            cout<<"The element in list:";
            while(temp!=NULL)
            {
                cout<<temp->info<<"\t";
                temp=temp->next;
            }
        }
    }
};

int main()
{
    list l;
    int ch,ele;
    while(true)
    {
        cout<<"\nEnter the choice\n1. Insert\n2. Delete\n3. Display\n4. Exit \n:";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Enter the element";
                    cin>>ele;
                    l.insert(ele);
                    break;
            case 2:l.del();break;
            case 3:l.display();break;
            case 4:return 0;
            default:cout<<"invalid choice\n";
        }
    }
    return 0;
}

/**
    Author Aman
**/
