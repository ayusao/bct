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
        //return NULL;
        exit(1);
    }
    ptr->data= x;
    ptr->next= NULL;
    return ptr;

}
class sllist{
public:
    node *start, *ptr, *temp;
    sllist()
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
        ptr->next= start;
        start = ptr;
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
void insertafter(int val, int y)
{
   node* n= createnode(val);
   temp = start;
   if (start==NULL) //if it is empty
    {
       cout << "Empty list" << endl;
      start= n;
      return;
   }
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
    if (start==NULL) //if it is empty
    {
       cout << "Empty list" << endl;
       start= n;
       return;
   }
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
        exit(1);
    }

        temp = start;
        start= start->next;
        cout << "Deleted item: "<<temp->data<<endl;
        delete temp;
}
void deleteend()
{
    if (start==NULL)
    {
        cout<<"Empty list.";
        exit(1);
    }
    temp = start;
    while (temp->next!=NULL)
    {
        ptr = temp;
        temp= temp->next;
    }
    ptr->next = NULL;
    cout << "Deleted item: "<<temp->data<<endl;
    delete temp;
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
    cout << "Deleted item: "<<ptr->data<<endl;
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
    sllist ll;
    ll.insertathead(15);
    ll.insertathead(1);
    ll.insertafter(5,15);
    ll.insertbefore(12,15);
    ll.insertatend(4);
    ll.display();
    ll.deletehead();
    ll.deleteend();
    ll.deleteafter(12);
    ll.display();
    return 0;
}
