//FIND THE FIBONACCI NUMBER FOR GIVEN TERM ‘N’.
//normal recursion and tail recursion
#include<iostream>
using namespace std;

int fibonacci(int n)
{
    int a=0;
    if (n==1)
        return 0;
    else if (n==2)
        return 1;
    else   
        return (fibonacci(n-1)+fibonacci(n-2));
}
int fibo_tail(int n, int a, int b)
{    
    if (n==1)
        return a;
    else if(n==2)
        return b;
    else    
        return fibo_tail(n-1, b, a+b);
        
}
int main()
{
    int n;
    int a=0, b=1;
    cout<< "Enter the nth term: ";
    cin>> n;
    cout << "Tail recursion: "<<fibo_tail(n, a, b)<<endl;
    cout << "Non-tail recursion: "<<fibonacci(n);    
    return 0;
}