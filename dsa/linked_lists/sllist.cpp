//singly linear linked lists
//Insertion operations
#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* createnode(int x)
{
    node* ptr = new node;
    if (ptr==NULL)
    {
        cout<<"No memory available.";
        exit(1);
    }
    else
    {
        ptr->data= x;
        ptr->next= NULL;
        return ptr;
    }
    
}
class nodecls{    
public:
    node *start, *ptr, *temp;
    nodecls()
    {
        start=NULL;
    }
//insertion at beginning
void insertathead(int val)
{
    ptr = createnode(val);
    // if (start==NULL)
    //     start= ptr;
    // else
    {
        ptr->next= start;
        start = ptr;
    }
}
//insertion at the end
void insertatend(int val)
{
    ptr = createnode(val);
    if (start==NULL) //if it is empty
    {
        start= ptr; 
        return;
    }
    temp=start;
    while(temp->next!=NULL) //position at the end
    {
        temp= temp->next;
    }
    temp->next= ptr;
    ptr->next= NULL;
}
//after specific node
void insertafter(int x, int y)
{
   node* n= createnode(x);
   temp = start;
   while(temp->data!=y)
   {
        temp= temp->next;
        ptr= temp->next;
   }
   temp->next=n;
   n->next= ptr;
}
void insertbefore(int x, int y)
{
    node* n = createnode(x);
    temp= start;
    while(temp->data!=y)
    {
        ptr = temp;
        temp= temp->next;
    } 
    ptr->next = n;
    n->next= temp;
}
//deletion at the beginning
void deletehead()
{
    if (start==NULL)
    {
        cout<<"Empty list.";
    }
    else
    {
        temp = start;
        start= start->next;
        delete temp;
    }
}
void deleteend()
{
    if (start==NULL)
    {
        cout<<"Empty list.";
    }
    else
    {
        temp = start;
        while (temp->next!=NULL)
        {
            ptr = temp;
            temp= temp->next;
        }
        ptr->next = NULL;
        delete temp;
    }
}
void deleteafter(int val)
{
    if (start==NULL)
    {
        cout<<"Empty list.";
        exit(1);
    }
    temp= start;
    while (temp->data!=val)
    {
        temp = temp->next;
        ptr= temp->next;
    }
    temp->next = ptr->next;
    delete ptr;

}
void display()
{
    node* temp= start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
};
int main()
{
    nodecls ll;
    ll.insertathead(1);
    ll.insertathead(15);
    ll.insertafter(5,1);
    ll.insertbefore(12,1);
    ll.insertafter(2,1);
    ll.insertatend(4);
    ll.display();
    ll.deletehead();
    ll.deleteend();
    ll.deleteafter(1);
    ll.display();
}