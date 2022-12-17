#include<iostream>

using namespace std;
const int stacksize = 10;
template <class T>
class Queue
{
private:
    T q[stacksize];
    int front, rear;
public:
    class Full{};
    class Empty{};
    Queue()
    {
        front =0;
        rear=0;
    }
    bool isfull()
    {
        return (rear == stacksize-1);
    }
    bool isempty()
    {
        return (front > rear);
    }
    void enqueue(T item)
    {
        if (isfull())
            throw Full();
        else
        {
            
            q[rear]=item;
            rear++;
        }
    }
    T dequeue()
    {
        if (isempty())
            throw Empty();
        else
        {
            return q[front++];
        }
    }
    void display()
    {
        for (int i=front; i<rear; i++)
        {
            cout<< q[i]<<endl;
        }
    }
};

int main()
{
    Queue<int> q;
    try
    {
        q.enqueue(256);
        q.enqueue(545);
        q.enqueue(53);

        cout << "Dequed element: "<<q.dequeue()<<endl;
        cout << "Dequed element: "<<q.dequeue()<<endl;

        q.display();


    }
    catch(Queue<int>::Full)
    {
        cout << "Exception: Stack Overflow.\n";
    }
    catch(Queue<int>::Empty)
    {
        cout << "Exception: Stack Underflow.\n";
    }

    return 0;

}
