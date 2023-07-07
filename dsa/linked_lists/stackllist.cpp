//stack as linked list
//start = top
#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* createnode(int val)
{
    node* new_node= new node;
    if (new_node== NULL)
    {
        cout << "Overflow.";
        exit(1);
    }
    else
    {
        new_node->data= val;
        new_node->next= NULL;
    }
}
class stackaslist
{
public:
    node *top, *ptr, *temp;
    stackaslist()
    {
        top= NULL;
    }
    //push operation on stack
    void push(int x)
    {
        ptr= createnode(x);
        if (top==NULL)
        {
            ptr->next= NULL;
            top= ptr;
        }
        else
        {
            ptr->next= top;
            top= ptr;
        }
    }
    void pop()
    {
        if (top==NULL)
        {
            cout<<"Underflow";
            exit(1);
        }
        else
        {
            temp = top;
            top = top->next;
            cout << "Item popped: "<<temp->data<<endl;
            delete temp;
        }
    }
    void display()
    {
        temp = top;
        while(temp!=NULL)
        {
            cout << temp->data<< "\t";
            temp= temp->next;
        }
        cout << endl;

    }
};
int main()
{
    stackaslist sl;
    sl.push(3);
    sl.push(90);
    sl.push(45);
    sl.display();
    sl.pop();
    sl.display();
}
