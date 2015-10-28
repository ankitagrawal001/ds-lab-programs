/***********************************************************************************
Design, develop, and execute a program in C++ to create a class
called
BIN_TREE that represents a Binary Tree, with member
functions to perform inorder, preorder and postorder traversals.
Create a BIN_TREE object and demonstrate the traversals.
************************************************************************************/

#include<iostream>

using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node tree;

tree *root=NULL;

class Bin
{
    int num;
    tree *prev,*p,*temp;
    public:
    void insert();
    void preorder(tree*);
    void inorder(tree*);
    void postorder(tree*);
    void display();
};

void Bin::insert()
{
    p=new (tree);
    cout<<"Enter number\t:";
    cin>>num;
    p->info=num;
    p->left=p->right=NULL;
    if(root==NULL)
    {
        root=p;
        return;
    }
    temp=root;
    while(temp!=NULL)
    {
        if(num>=temp->info)
        {
            prev=temp;
            temp=temp->right;
        }
        else
        {
            prev=temp;
            temp=temp->left;
        }
    }
    if(num>=prev->info)
    {
        prev->right=p;
    }
    else
    {
        prev->left=p;
    }
}

void Bin::preorder(tree *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void Bin::inorder(tree *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->info<<"\t";
        inorder(temp->right);
    }
}

void Bin::postorder(tree *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->info<<"\t";
    }
}

void Bin::display()
{
    if(root==NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    cout<<"\nPreorder \t";preorder(root);
    cout<<"\nInorder  \t";inorder(root);
    cout<<"\nPostorder\t";postorder(root);
}

int main()
{
    Bin ob;
    int ch;
    while(true)
    {
        cout<<"\n1. Insert\n2. Display\n3. Exit\n Enter choice\n:";
        cin>>ch;
        switch(ch)
        {
            case 1:ob.insert();
                    break;
            case 2:ob.display();
                    break;
            case 3:return 0;
        }
    }
    return 0;
}

/**
    Author - Aman
**/
