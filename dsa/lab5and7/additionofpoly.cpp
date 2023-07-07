//a program in cpp to add multiple polynomial equations using dynamic linkedList
#include<iostream>
using namespace std;

struct node{
 float coef, expo;
 node* next;
};

class LinkedList
{
private:
    node* newNode, *ptr,*p,*start,*temp;
    int degree,n;
    float data;
public:
    LinkedList():degree(0),n(0),data(0)
    {
        start = nullptr;
    }
    ~LinkedList()
    {
    }
    void getData()
    {
        cout << "ENTER THE NUMBER OF EXPRESSIONS TO BE ADDED : ";
        cin >> n;
        cout << "ENTER THE HIGHEST DEGREE AMONG THE EXPRESSIONS: ";
        cin >> degree;
        cout << "ENTER THE COEFFICIENTS OF ALL THE EXPRESSIONS IN MATRIX FORM: " << n << " x " << degree+1 << std::endl;
    }
    void insertExp()
    {
        getData();
        for(int j =0;j<n;j++)
        {
        start = NULL;
        for(int i=degree;i>=0;i--)
        {
            cin>>data;
            newNode = new node;
            newNode->coef = data;
            newNode->expo = i;
            if(start == NULL)
            {
                newNode->next = NULL;
                start = newNode;
            }
            else
            {
                ptr = start;
                while(ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
                newNode->next = NULL;
            }
        }
        if(j == 0)
        {
                temp = start;
        }
        else
        {
            Addition(start);
        }
        }
        showData(temp);
    }
    void Addition(node* q)
    {
        p = temp;
            while(p->next != NULL)
            {
                  p->coef += q->coef;
                  p = p->next;
                  q = q->next;
            }
            if (p->expo == q->expo)
            {
                p->coef += q->coef;
                p = p->next;
                q = q->next;
            }
    }
    void showData(node* a)
    {
        cout << "\n ADDITION: ";
        while(a->next != NULL)
        {
            cout<<a->coef<<"x^"<<a->expo;
            cout<<" + ";
            a = a->next;
        }
        cout<<a->coef<<"x^"<<a->expo;
    }
};

int main()
{
    LinkedList ll;
    ll.insertExp();
    return 0;
}
