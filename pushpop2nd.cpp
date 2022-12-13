#include<iostream>
using namespace std;

template <class T>
class stackc{
private:
    int top, stacksize;
    int* stk;
public:
    stackc()
    {
        top = -1;
        stacksize=10;
        stk = new int[stacksize];
    }

    bool Isempty()
    {
        /*if (top==-1)
            return true;
        else
            return false;*/
            return (top == -1);
    }
    bool Isfull()
    {
        return (top == stacksize-1);
    }
    void push (T item)
    {
        if (top == stacksize- 1)
            //throw ("Stack Overflow.\n");
            cout << "Stack Overflow\n";
        else
        {
            top++;
            stk[top]= item;
        }
    }
    T pop()
    {
        if (Isempty()== true)
            //throw ("Stack Underflow\n");
            cout << "Stack Underflow\n";
        else
        {
            cout << "Popped element is: " << stk[top]<<endl;
            top--;
        }
    }
    T display()
    {
        for (int i=0; i<=top; i++)
        {
            cout << "Element: "<< stk[i] <<endl;
        }
    }

};
int main()
{
    stackc<int> mystack;
    mystack.push(44);
    mystack.push(256);
    mystack.push(86);

    mystack.push(2);
    mystack.pop();
    mystack.display();
}
