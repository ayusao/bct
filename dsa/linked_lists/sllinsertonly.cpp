//singly linear linked lists
//Insertion operations
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next= NULL;
    }
};
//insertion at beginning
void insertathead(node* &head, int val)
{
    node* n= new node(val);
    n->next= head;
    head=n;
}
//insertion at the end
void insertatend(node* &head, int val)
{
    node* n= new node(val);
    if (head==NULL) //if it is empty
    {
        head= n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL) //position at the end
    {
        temp= temp->next;
    }
    temp->next= n;
    n->next= NULL;
}
//after specific node
void insertafter(node* head, int val, int aft)
{
    node* n= new node(val);
    node* temp= head;
    node* ptr;
    while(temp->data!=aft)
    {
        temp= temp->next;
        ptr= temp->next;
    }
     
    temp->next= n;
    n->next= ptr;
}
void insertbefore(node* head, int val, int bfr)
{
    node* n= new node(val);
    node* ptr= head;
    node* preptr;
    while(ptr->data!=bfr)
    {
        preptr= ptr;
        ptr= ptr->next;       
    }
    preptr->next= n; 
    n->next= ptr;   
}
//deletion at the beginning
void deletehead(node* head)
{
    if (head==NULL)
    {
        cout<<"Empty list.";
    }
    else
    {
        node* temp= head;
        head= head->next;
        delete temp; //free temp
    }
}

void display(node* head)
{
    node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node* head=NULL;
    insertathead(head, 1);
    insertatend(head, 2);
    insertathead(head, 3);
    insertafter(head, 4, 1);
    insertbefore(head, 5, 1);
    display(head);
    deletehead(head);
    display(head);
}