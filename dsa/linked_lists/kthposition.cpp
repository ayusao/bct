//insert and delete a node at Kth position
#include<iostream>
using namespace std;
struct node{
    int data;
    node *prev, *next;
};
node *createnode(int val)
{
    node* newnode = new node;
    if (newnode==NULL)
    {
        cout<<"No memory available.";
        return NULL;
    }
    else
    {
        newnode->data= val;
        newnode->prev= NULL;
        newnode->next= NULL;
        return newnode;
    }   
}
class dllist
{
    public:
    node *temp, *ptr, *start;
    dllist()
    {
        start = NULL; // initialize start to NULL
    }
    void insertion(int val, int pos)
    {
        temp = createnode(val);
         while (pos--) {
            ptr = start;
            if (pos == 0) {
  
                // Making the new Node to point to 
                // the old Node at the same position
                temp->prev = ptr->prev;
                ptr->prev = temp;
                
                temp->next = ptr;
                
            }
            else
              // Assign double pointer variable to point to the 
              // pointer pointing to the address of next Node 
              ptr= ptr->next;
        }
    }
    void display()
    {
       temp= start;
       //cout<<"Data:";
       while(temp!=NULL)
       {
           cout<<temp->data<<"\t";
           temp=temp->next;
       }
       cout<<endl;
    }
};
int main()
{
    dllist ll;
    ll.insertion(3,1);
    ll.display();
}