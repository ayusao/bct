//check if a expression is valid
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
    try{
    //stackc<char> s;
    string expression;
    cout << "Enter the expression: ";
    cin>>expression;
    if (checkpar(expression))
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
