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
        class Full{}; //exception class for fullstack
        class Empty{};
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
        void push(T item)
        {
            if (Isfull())
            {
                //cout<< "Stack overflow.\n";
                //throw ("Stack overflow.\n");
                throw Full();
            }
            else
            {
                top++;
                stk[top]= item;
            }
        }
        T pop()
        {
            if (Isempty())
            {
                //cout << "Stack Underflow.\n";
                // return -1;
                //throw ("stack underflow\n");
                throw Empty();
            }
            else
            {
                T item = stk[top];
                top--;
                return item;
            }
        }
        void display()
        {
            for (int i=0; i<=top; i++)
            {
                cout << "Element: "<< stk[i] <<endl;
            }
        }
        T givetop()
        {
            if (Isempty())
                throw Empty();
                //throw ("stack underflow");
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
string reversestr(string infix)
{
    string reverse;
    for (int i=0; i< infix.length(); i++)
    {
        reverse += infix[infix.length()-i-1]; //-1 for \0
    }
    return reverse;
}
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
string toprefix(string infix)
{
    string prefix;
    stackc<char> s;
    infix = reversestr(infix);
    for (int i=0; i<infix.length(); i++)
    {
        //condition for prefix
        if (infix[i]== '(')
            infix[i] = ')';
        else if (infix[i]== ')')
            infix[i] = '(';
    }
    for (int i=0; i<infix.length(); i++)
    {
        //if it is an operand
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i]<= 'Z')
        {
            prefix += infix[i];
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
                prefix += s.givetop();
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
                        prefix += s.givetop();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.Isempty())
    {
        prefix += s.givetop();
        s.pop();
    }
    return reversestr(prefix);
}
bool checkpar(string exp)
{
    stackc<char> s;
    for (int i=0; i< exp.length(); i++)
    {
        if (exp[i]== '(' || exp[i]=='{' || exp[i]=='[' )
        {
            s.push(exp[i]);
        }
        else if (exp[i]== ')' || exp[i]=='}' || exp[i]==']' )
        {
            if (s.Isempty())
                return false;
            else if ((s.givetop()=='(' &&exp[i]== ')')|| (s.givetop()== '{' && exp[i]== '}') ||(s.givetop()=='[' && exp[i]== ']'))
                {
                    s.pop();
                }
        }

    }
    if (s.Isempty())
    {
        return true;
    }
    else
        return false;
}

int main()
{
    try
    {
        string infix, postfix;
        cout << "Enter your infix expression: ";
        cin >> infix;
        cout <<"Postfix expresssion= "<< topostfix(infix)<<endl;
        cout<< "Prefix expression= "<<toprefix(infix)<<endl;
        
    
            if (checkpar(infix))
        {
            cout << "Balanced parenthesis.";
        }
        else
            {cout << "Unpaired parenthesis.";}
        }  
        catch (stackc<char>::Full)
        {
            cout << "Exception: Stack Overflow.\n";
        }
        catch (stackc<char>::Empty)
        {
            cout <<"Exception: Stack Underflow.\n ";
        }

    return 0;
}
