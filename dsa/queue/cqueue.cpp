//Perform enqueue and dequeue operations in Circular Queue
#include<iostream>
using namespace std;
const int stacksize = 3;
template <class T>
class cqueue
{
private:
    T q[stacksize];
    int front, rear;
public:
    class Full{};
    class Empty{};
    cqueue()
    {
        front =0;
        rear=0;
    }
    bool isfull()
    {
        return ((rear+1)%stacksize == front);
    }
    bool isempty()
    {
        return(rear==front);
    }
    void enq(T item)
    {
        if (isfull())
            throw Full();
        q[rear]= item;
        rear= (rear+1)%stacksize;
            
    }
    void deq()
    {
        if (isempty())
            throw Empty();
    
        T item = q[front];
        front = (front+1)%stacksize;
        
        cout << "Dequeued element: "<<item<<endl;
    }

    void display()
    {
        if (isempty())
            throw Empty();
        for (int i= front; i!=rear; i=(i+1)%stacksize)
        {
            cout << q[i]<< " "<<endl;
        }
        cout << endl;
    }
    
};
int main()
{
    cqueue<int> cq;
    try{
        cq.enq(256);
        cq.enq(545);
        cq.display();
        cq.deq();
        cq.deq();
        cq.enq(55);
        cq.enq(46);

        cq.display();
    }
    catch(cqueue<int>::Full)
    {
        cout << "Exception: Stack Overflow.\n";
    }
    catch(cqueue<int>::Empty)
    {
        cout << "Exception: Stack Underflow.\n";
    }

    return 0;
}