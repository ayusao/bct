//tower of hanoi
#include<iostream>
using namespace std;

void towerOfHanoi(int n, char source, char dest, char aux)
{
    if (n==1)
    {
        cout<< "Move 1 disc from " << source<<" to "<<dest<<endl;
    }
        
    else
    {
        towerOfHanoi(n-1, source, aux, dest);
        cout<< "Move " << n << " disc from " << source<<" to "<<dest<<endl;
        towerOfHanoi(n-1, aux, dest, source);
    }
}

int main()
{
    towerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}