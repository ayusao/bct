#include<iostream>
#include<string>

using namespace std;

const int stacksize = 100;
template <class T>
class stackc
{
    private:
        int top;
        T stk[stacksize];
    public:
        stackc()
        {
            top = -1;
        }
        bool Isfull()
        {
            return (top == stacksize);
        }
        bool Isempty()
        {
            // if (top == -1)
            //     return true;
            return (top == -1);
        }
        bool push(T item)
        {
            if (Isfull())
            {
                //cout<< "Stack overflow.\n";
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
            if (Isempty())
            {
                //cout << "Stack Underflow.\n";
                return -1;
            }
            else
            {
                // T item = stk[top];
                // top--;
                return stk[top--];
            }
            //return stk[top--];
        }
        void display()
        {
            for (int i=0; i<=top; i++)
            {
                cout << "Element: "<< stk[i] <<endl;
            }
        }
        char givetop()
        {
            if (Isempty())
                return -1;
            else
                return stk[top];
        }
        int sizest() //not necessary though
        {
            return(top+1);
        }
};
bool Isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
char priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if(op == '^')
        return 3;
    else
        return -1;
}
string topostfix(stackc<char> s, string infix)
{
    string postfix;
    //stackc<char> s;

    for (int i=0; i<infix.length(); i++)
    {
        //if it is an operand
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i]<= 'Z')
        {
            postfix += infix[i];
        }
        //if left parenthesis is encountered
        else if (infix[i]== '(')
        {
            s.push(infix[i]);
        }
        //right parenthesis
        else if (infix[i] == ')')
        {
            //while((!s.Isempty()) && (s.givetop() != '('))
            while((!s.Isempty())&& (s.givetop()!= '('))
            {
                postfix += s.givetop();
                s.pop();
                
            }
            if (s.givetop() == '(')
                {
                    s.pop();
                    
                }
        }
        //if operator
        else if (Isoperator(infix[i]))
        {
            if (s.Isempty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (priority(infix[i])> priority(s.givetop()))
                {
                    s.push(infix[i]);
                }
                else if ((priority(infix[i])== priority(s.givetop()))&&(infix[i]== '^'))
                {
                    s.push(infix[i]);
                } 
                else 
                {
                    while((!s.Isempty())&&(priority(infix[i])<= priority(s.givetop())))
                    {
                        postfix += s.givetop();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }          
        }
        
    }
    while(!s.Isempty())
    {
        postfix += s.givetop();
        s.pop();
    }
    return postfix;
}
int main()
{
    string infix;
    stackc<char> s;
    cout << "Enter your infix expression: ";
    cin >> infix;

    cout <<"Postfix expresssion= "<< topostfix(s, infix);
    return 0;
}
