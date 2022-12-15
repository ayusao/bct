#include<iostream>
using namespace std;

template <class T>
class stackc{
private:
    int top, stacksize;
    T* stk;
public:
    stackc(int size_ofstack)
    {
        top = -1;
        stacksize=size_ofstack;
        stk = new T[stacksize];
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
    bool push (T item)
{
    if (Isfull())
    {
        cout << "Stack Overflow\n";
        return false;
    }
    else
    {
        top++;
        stk[top]= item;
        return true;
    }
}
    T pop()
    {
        if (Isempty()) // Isempty()==true
            //throw ("Stack Underflow\n");
            cout << "Stack Underflow\n";
        else
        {
            cout << "Popped element is: " << stk[top]<<endl;
            return stk[top--];
        }
    }

bool display()
{
    for (int i=0; i<=top; i++)
    {
        cout << "Element: "<< stk[i] <<endl;
    }
    return true;
}
    int sizestk() //not necessary though
        {
            return(top+1);
        }

};
int main()
{
    stackc<int> mystack(5);
    std::cout<< "Size of stack: "<< mystack.sizestk()<<endl;
    mystack.push(44);
    mystack.push(256);
    mystack.push(86);

    mystack.push(2);
    mystack.pop();
    std::cout<< "Size of stack: "<< mystack.sizestk()<<endl;
    mystack.display();
}
