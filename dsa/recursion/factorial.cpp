//FIND THE FACTORIAL FOR GIVEN NUMBER ‘N’.
#include<iostream>

int fact(int n)
{
    if (n==0)
        return 1;
    else
        return (n*fact(n-1));
}
int tail(int n, int res)
    {
        if (n==0)
            return res;
        else
            return (tail(n-1, n*res));
    }
int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >>  num;
    std::cout << "Tail recursion: "<< tail(num, 1)<<std::endl;
    std::cout << "Non-tail recursion: "<< fact(num);
    return 0;
}
