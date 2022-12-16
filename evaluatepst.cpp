//evaluate the postfix expression
#include<iostream>
#include<string>
#include<math.h>

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
                throw ("Stack overflow.\n");
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
                // return -1;
                throw ("stack underflow\n");
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
        T givetop()
        {
            if (Isempty())
                throw ("stack underflow");
            else
                return stk[top];
        }
        int sizest() //not necessary though
        {
            return(top+1);
        }
};

bool isoperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/' || c== '^')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int evaluate(string postfix)
{
    stackc<int> s;
    int operand1, operand2;
    for (int i=0; i<postfix.length(); i++)
    {
        if (postfix[i]>= '0' && postfix[i]<='9')
            s.push(postfix[i]-'0'); //converts to integer
        else if (isoperator(postfix[i]))
        {
            operand1 = s.givetop();
            s.pop();
            operand2 = s.givetop();
            s.pop();
            switch (postfix[i])
            {
            case '+':
                s.push(operand2+ operand1);
                break;
            case '-':
                s.push(operand2 - operand1);
                break;
            case '*':
                s.push(operand2 * operand1);
                break;
            case '/':
                s.push(operand2 / operand1);
                break;
            case '^':
                s.push(pow(operand2,operand1));
                break;
            default:
                break;
            }

        }
    }
    return(s.givetop());
}

int main()
{
    try{
    string postfix;
    cout << "Enter the postfix expression with integers: ";
    cin >> postfix;
    cout << "After evaluation, the value is: "<< evaluate(postfix);
    }
    catch (const char* err) {
    cout << err;
    }
    return 0;
}
