//Doubly linked list
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
    void insertathead(int val)
    {
        ptr = createnode(val);

        if (start == NULL) {
            start = ptr;
        }
        
        
            ptr->next= start;
            ptr->prev= NULL;
            start= ptr;
        
    }
    void insertatend(int val)
    {
        ptr = createnode(val);
        if (start==NULL) //if it is empty
        {
            start= ptr;
            return;
        }

        temp = start;
        while (temp->next!=NULL)
        {
            temp = temp->next;

        }
        temp->next= ptr;
        ptr->prev= temp;
        ptr->next= NULL;
    }
    //after specific node
    void insertafter(int val, int y)
    {

        temp = createnode(val);
        if (start == NULL)
        {
            cout << "Empty list" << endl;
            start = temp;
            return;
        }
        ptr = start;
        while (ptr->data != y)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next->prev = temp;
        ptr->next = temp;
        temp->prev = ptr;
    }

    void insertbefore(int val, int x)
    {
        node *preptr;
        temp = createnode(val);
        if (start==NULL)
        {
            cout << "Empty list.";
            start = temp;
            return;
        }
        ptr = start;
        while (ptr->data != x)
        {
            ptr = ptr->next;
        }
        temp->prev = ptr->prev;
        ptr->prev->next = temp;
        temp->next = ptr;
        ptr->prev = temp;
    }
    void deletehead()
    {
        if (start == NULL)
        {
            cout <<"Empty list.";
            exit(1);
        }
        else
        {
            temp = start;
            start = start->next;
            start->prev= NULL;
            cout << "Deleted item(delete head): "<<temp->data<<endl;
            delete temp;
        }
    }
    void deleteend()
    {
        if (start==NULL)
        {
            cout << "Empty list.";
            exit(1);
        }
        temp = start;
        while (temp->next!=NULL)
        {
            ptr = temp;
            temp = temp->next;

        }
        ptr->next= NULL;
        cout <<"Deleted item(delete end): "<< temp->data<<endl;
        delete temp;
    }
    void deleteafter(int x)
    {
        if (start== NULL)
        {
            cout << "Empty list.";
            exit(1);
        }
        temp = start;
        while (temp->data!=x)
        {
            temp = temp->next;

        }
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        cout<<"Deleted item(delete after): "<<ptr->data<<endl;
        delete ptr;

    }
    void deletebefore(int x)
    {
        if (start==NULL)
        {
            cout << "Empty list.";
            exit(1);
        }
        temp = start;
        while (temp->data != x)
        {
            temp= temp->next;
        }
        ptr = temp->prev;
        ptr->prev->next = temp;
        temp->prev = ptr->prev;
        cout << "Deleted item(delete before): "<<ptr->data<<endl;
        delete ptr;
    }
    void display()
    {
       temp= start;
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
    ll.insertatend(32);
    ll.insertathead(3);
    ll.insertafter(2,3);
    ll.insertbefore(5,2);
    ll.display();
    ll.deleteafter(3);
    ll.deleteend();
    ll.deletehead();
    ll.display();
    return 0;
}
