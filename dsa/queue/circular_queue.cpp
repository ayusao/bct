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
        front =-1;
        rear=-1;
    }
    bool isfull()
    {
        return (front==0 && rear == stacksize-1);
    }
    bool isempty()
    {
        return(front == -1);
    }
    void enq(T item)
    {
        if (isfull())
            throw Full();
        else if (front==-1 && rear==-1)
        {
            front=0; rear=0;
        }
        else if (rear == stacksize-1 && front!=0)
            rear=0;
        else
            rear++;
        q[rear]=item;
    }
    T deq()
    {
        if (front==-1)
            throw Empty();
        T item = q[front];
        if (front==rear)
        {
            front = -1;
            rear =-1;

        }
        else if (front == stacksize-1)
            front =0;
        else
            front++;
        return item;
    }

    void display()
    {
        if (isempty())
            throw Empty();
        else if (front <= rear)
        {
            for (int i=front; i<=rear; i++)
            {
                cout << q[i] << " ";
            }
        }
        else
        {
            for (int i=front; i<stacksize; i++)
                cout << q[i] << " ";
            for (int i=0; i<=rear; i++)
                cout << q[i] << " ";
        }
    }
};
int main()
{
    cqueue<int> cq;
    try{
        cq.enq(256);
        cq.enq(545);
        cq.enq(53);
        cout << "Dequeued element: " << cq.deq() << endl;
        cout << "Dequeued element: " << cq.deq() << endl;
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