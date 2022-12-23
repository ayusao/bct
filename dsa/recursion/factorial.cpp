//FIND THE FACTORIAL FOR GIVEN NUMBER ‘N’.
#include<iostream>


int fact(int n)
{
    if (n==0)
        return 1;
    else
        return (n*fact(n-1));
}
int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >>  num;
    std::cout << "The factorial of the given number is: "<< fact(num);
    return 0;
}
