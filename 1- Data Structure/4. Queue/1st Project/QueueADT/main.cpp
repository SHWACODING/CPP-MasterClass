#include <iostream>
#include <stack>

using namespace std;

//// Implementation Of Queue Using Array ?
//
//class Queue
//{
//private:
//    int Front;
//    int Rear;
//    int Size;
//    int *Q;
//public:
//    Queue()
//    {
//        Front = Rear = -1;
//        Size = 10;
//        Q = new int[Size];
//    }
//    Queue(int sz)
//    {
//        Front = Rear = -1;
//        this->Size = sz;
//        Q = new int[this->Size];
//    }
//    void Enqueue(int x);
//    int Dequeue();
//    void Display();
//};
//
//void Queue::Enqueue(int x)
//{
//    if(Rear == Size-1)
//        cout << "Queue Is Full ? \n";
//    else
//    {
//        Rear++;
//        Q[Rear] = x;
//    }
//}
//
//int Queue::Dequeue()
//{
//    int x = -1;
//
//    if (Front == Rear)
//        cout << "Queue Is Empty ? \n";
//    else
//    {
//        Front++;
//        x = Q[Front];
//    }
//    return x;
//}
//
//void Queue::Display()
//{
//    for (int i = Front+1; i <= Rear; ++i)
//        cout << Q[i] << " ";
//    cout << endl;
//}
//
//int main()
//{
//    Queue q(5);
//
//    q.Enqueue(10);
//    q.Enqueue(20);
//    q.Enqueue(30);
//    q.Enqueue(40);
//
//    q.Display();
//
//    cout << q.Dequeue() << endl;
//
//    q.Display();
//
//    return 0;
//}

//// Implementation Of Circular Queue Using Array  (The Best & Truth) ?
//
//class Queue
//{
//private:
//    int Front;
//    int Rear;
//    int Size;
//    int *Q;
//public:
//    Queue()
//    {
//        Front = Rear = 0;
//        Size = 10;
//        Q = new int[Size];
//    }
//    Queue(int sz)
//    {
//        Front = Rear = 0;
//        this->Size = sz;
//        Q = new int[this->Size];
//    }
//    void Enqueue(int x);
//    int Dequeue();
//    void Display();
//};
//
//void Queue::Enqueue(int x)
//{
//    if((Rear + 1) % Size == Front)
//        cout << "Queue Is Full ? \n";
//    else
//    {
//        Rear = (Rear + 1) % Size;
//        Q[Rear] = x;
//    }
//}
//
//int Queue::Dequeue()
//{
//    int x = -1;
//
//    if (Front == Rear)
//        cout << "Queue Is Empty ? \n";
//    else
//    {
//        Front = (Front + 1) % Size;
//        x = Q[Front];
//    }
//    return x;
//}
//
//void Queue::Display()
//{
//    int i = Front + 1;
//
//    do
//    {
//        cout << Q[i] << " ";
//        i = (i + 1) % Size;
//    } while(i != (Rear + 1) % Size);
//    cout << endl;
//}
//
//int main()
//{
//    Queue q(5);
//
//    q.Enqueue(10);
//    q.Enqueue(20);
//    q.Enqueue(30);
//    q.Enqueue(40);
//
//    q.Display();
//
//    cout << q.Dequeue() << endl;
//
//    q.Display();
//
//    return 0;
//}

//// Implementation Of Doubly Ended Queue (DEQueue) Using Array ?
//
//class DEQueue
//{
//private:
//    int Front;
//    int Rear;
//    int Size;
//    int* Q;
//public:
//    DEQueue(int Size);
//    ~DEQueue();
//    void Display();
//    void EnqueueFront(int x);
//    void EnqueueRear(int x);
//    int DequeueFront();
//    int DequeueRear();
//    bool IsEmpty();
//    bool IsFull();
//};
//
//DEQueue::DEQueue(int Size)
//{
//    this->Size = Size;
//    Front = Rear = -1;
//    Q = new int[Size];
//}
//
//DEQueue::~DEQueue()
//{
//    delete []Q;
//}
//
//bool DEQueue::IsEmpty()
//{
//    return Front == Rear ? true : false;
//}
//
//bool DEQueue::IsFull()
//{
//    return Rear == Size - 1 ? true : false;
//}
//
//void DEQueue::EnqueueFront(int x)
//{
//    if (Front == -1)
//        cout << "DEQueue Overflow" << endl;
//    else
//    {
//        Q[Front] = x;
//        Front--;
//    }
//}
//
//void DEQueue::EnqueueRear(int x)
//{
//    if(IsFull())
//        cout << "DEQueue Overflow" << endl;
//    else
//    {
//        Rear++;
//        Q[Rear] = x;
//    }
//}
//
//int DEQueue::DequeueFront()
//{
//    int x = -1;
//
//    if (IsEmpty())
//        cout << "DEQueue Underflow" << endl;
//    else
//    {
//        x = Q[Front];
//        Front++;
//    }
//    return x;
//}
//
//int DEQueue::DequeueRear()
//{
//    int x = -1;
//
//    if(Rear == -1)
//        cout << "DEQueue Underflow" << endl;
//    else
//    {
//        x = Q[Rear];
//        Rear--;
//    }
//    return x;
//}
//
//void DEQueue::Display()
//{
//    for (int i = Front+1; i <= Rear; ++i)
//    {
//        cout << Q[i] << flush;
//        if (i < Rear)
//            cout << " <- " << flush;
//    }
//    cout << endl;
//}
//
//int main()
//{
//    int A[] = {1, 3, 5, 7, 9};
//    int B[] = {2, 4, 6, 8, 10};
//
//    DEQueue deq(sizeof(A) / sizeof(A[0]));
//
//    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
//        deq.EnqueueRear(A[i]);
//
//    deq.Display();
//    deq.EnqueueRear(11);
//
//    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
//        deq.DequeueFront();
//
//    deq.DequeueFront();
//
//    cout << endl;
//
//    for (int i = 0; i < sizeof(B) / sizeof(B[0]); ++i)
//        deq.EnqueueFront(B[i]);
//
//    deq.Display();
//    deq.EnqueueFront(12);
//
//    for (int i = 0; i < sizeof(B) / sizeof(B[0]); ++i)
//        deq.DequeueRear();
//
//    deq.Display();
//
//    return 0;
//}

//// Implementation Of Queue Using 2 Stacks ?
//class Queue
//{
//private:
//    stack<int> e_stk;
//    stack<int> d_stk;
//public:
//    Queue(){};
//    ~Queue(){};
//    void Enqueue(int x);
//    int Dequeue();
//};
//
//void Queue::Enqueue(int x)
//{
//    e_stk.push(x);
//}
//
//int Queue::Dequeue()
//{
//    int x = -1;
//
//    if (d_stk.empty())
//    {
//        cout << "Queue Underflow" << endl;
//        return x;
//    }
//    else
//    {
//        while (!e_stk.empty())
//        {
//            d_stk.push(e_stk.top());
//            e_stk.pop();
//        }
//    }
//    x = d_stk.top();
//    d_stk.pop();
//    return x;
//}
//
//int main()
//{
//    int A[] = {1, 3, 5, 7, 9};
//
//    Queue q;
//
//    cout << "Enqueue : " << flush;
//    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
//    {
//        q.Enqueue(A[i]);
//        cout << A[i] << flush;
//
//        if (i < sizeof(A) / sizeof(A[0]) - 1)
//            cout << " <- " << flush;
//    }
//    cout << endl;
//
//    cout << "Dequeue : " << flush;
//    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
//    {
//        cout << q.Dequeue() << flush;
//
//        if (i < sizeof(A) / sizeof(A[0]) - 1)
//            cout << " <- " << flush;
//    }
//
//    return 0;
//}


//// Implementation Of Queue Using Linked Lsit ?
//
//class Node
//{
//public:
//    int data;
//    Node* next;
//};
//
//class Queue
//{
//private:
//    Node* Front;
//    Node* Rear;
//public:
//    Queue()
//    {
//        Front = nullptr;
//        Rear = nullptr;
//    };
//    ~Queue()
//    {
//        Node* p = Front;
//        while (Front)
//        {
//            Front = Front->next;
//            delete p;
//            p = Front;
//        }
//    };
//    void Enqueue(int x);
//    int Dequeue();
//    bool IsEmpty();
//    void Display();
//};
//
//void Queue::Enqueue(int x)
//{
//    Node* t = new Node;
//
//    if (t == nullptr)
//        cout << "Queue Overflow" << endl;
//    else
//    {
//        t->data = x;
//        t->next = nullptr;
//
//        if (Front == nullptr)
//        {
//            Front = t;
//            Rear = t;
//        }
//        else
//        {
//            Rear->next = t;
//            Rear = t;
//        }
//    }
//}
//
//int Queue::Dequeue()
//{
//    int x = -1;
//
//    Node* p;
//
//    if(IsEmpty())
//        cout << "Queue Underflow" << endl;
//    else
//    {
//        p = Front;
//        Front = Front->next;
//        x = p->data;
//        delete p;
//    }
//    return x;
//}
//
//bool Queue::IsEmpty()
//{
//    return Front == nullptr ? true : false;
//}
//
//void Queue::Display()
//{
//    Node* p = Front;
//
//    while(p)
//    {
//        cout << p->data << flush;
//        p = p->next;
//
//        if (p != nullptr)
//            cout << " <- " << flush;
//    }
//    cout << endl;
//}
//
//int main()
//{
//    int A[] = {1, 3, 5, 7, 9};
//
//    Queue q;
//
//    for (int i = 0; i < sizeof(A)/sizeof(A[0]); ++i)
//        q.Enqueue(A[i]);
//
//    q.Display();
//
//    for (int i = 0; i < sizeof(A)/sizeof(A[0]); ++i)
//        cout << "Deleted Element : " << q.Dequeue() << endl;
//
//    q.Display();
//
//    return 0;
//}
