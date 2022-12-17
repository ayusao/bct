#include<iostream>
using namespace std;

class stackc
{
private:
    int top, maxsize;
    int stk[2];

public:
    stackc()
    {
        top = -1;
        maxsize = 3;
    }
    bool Isempty()
    {
        /*if (top==-1)
            return true;
        else
            return false;*/
            return (top == -1);
    }


    void push(int item)
    {
        if (top == maxsize - 1)
            cout << "Stack Overflow."<<endl;
        else
        {
            top++;
            stk[top]= item;
        }
    }
    void pop()
    {
        if (Isempty()== true)
            cout<< "Stack Underflow"<<endl;
        else
        {
            cout << "Popped element is: " << stk[top]<<endl;
            top--;
        }
    }
    void display()
    {
        for (int i=0; i<=top; i++)
        {
            cout << "Element: "<< stk[i] <<endl;
        }
    }
};
int main()
{
    stackc mystack;
    mystack.push(44);
    mystack.push(256);
    mystack.push(86);

    mystack.push(2);
    mystack.pop();
    mystack.display();

}
