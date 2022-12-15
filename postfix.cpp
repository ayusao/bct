#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

const int stacksize = 20;
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
            if (top == stacksize)
                return true;
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
                cout<< "Stack overflow.\n";
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
                cout << "Stack Underflow.\n";
            }
            else
            {
                // T item = stk[top];
                // top--;
                return stk[top--];
            }
        }
        void display()
        {
            for (int i=0; i<=top; i++)
            {
                cout << "Element: "<< stk[i] <<endl;
            }
        }
        int givetop()
        {
            if (Isempty())
                return '\0';
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
// char priority(int op)
// {
//     if (op == "+" || op == "-")
//         return 1;
//     else if (op == "*" || op == "/")
//         return 2;
//     else if(op == "^")
//         return 3;
// }
string topostfix(string infix)
{
    string postfix;
    stackc<char> s;

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
        //if operator
        // else if (Isoperator(infix[i]))
        // {
        //     if (priority(infix[i])> priority(s.givetop()))
        //     {
        //         postfix += s.pop();
        //         s.pop();
        //     }
        //     else
        //     {
        //         s.push(infix[i]);
        //     }

        // }
        //right parenthesis
        else if (infix[i] == ')')
        {
            while(!s.Isempty())
            {
                postfix += s.pop();
                s.pop();
                //if (postfix == '(')
                  //  break;
            }
        }
    }
    return postfix;
}
int main()
{
    string infix;
    cout << "Enter your infix expression: ";
    cin >> infix;

    cout <<"Postfix expresssion= "<< topostfix(infix);
    return 0;
}
