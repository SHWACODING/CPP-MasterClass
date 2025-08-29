//#include <iostream>
//
//using namespace std;
//
//class Node
//{
//public:
//    int data;
//    Node *next;
//};
//
//class LinkedList
//{
//private:
//    Node *first;
//public:
//    LinkedList () { first = NULL; }
//    LinkedList (int A[], int n);
//    ~LinkedList();
//
//    void Display();
//    void Insert(int index, int x);
//    int Delete (int idx);
//    int Length();
//};
//
//LinkedList::LinkedList(int A[], int n)
//{
//    int i;
//    struct Node *temp, *last;
//    first = new Node;
//    first->data = A[0];
//    first->next = NULL;
//    last = first;
//
//    for (i = 1; i < n; ++i)
//    {
//        temp = new Node;
//        temp->data = A[i];
//        temp->next = NULL;
//        last->next = temp;
//        last = temp;
//    }
//}
//
//LinkedList::~LinkedList()
//{
//    Node *p = first;
//
//    while (first)
//    {
//        first = first->next;
//        delete p;
//        p = first;
//    }
//}
//
//void LinkedList::Display()
//{
//    Node *p = first;
//
//    while (p)
//    {
//        cout << p->data << " ";
//        p = p->next;
//    }
//    cout << endl;
//}
//
//int LinkedList::Length()
//{
//    Node *p = first;
//    int len = 0;
//
//    while (p)
//    {
//        len++;
//        p = p->next;
//    }
//    return len;
//}
//
//void LinkedList::Insert(int idx, int x)
//{
//    Node *t, *p = first;
//
//    if (idx < 0 || idx > Length())
//        return;
//
//    t = new Node;
//    t->data = x;
//    t->next = NULL;
//
////    Inserting Into Start ??
//    if (idx == 0)
//    {
//        t->next = first;
//        first = t;
//    }
//
////    Inserting Into Specific Position Not Equal First Position ??
//    else
//    {
//        for (int i = 0; i < idx - 1 && p; ++i)
//            p = p->next;
//
//        t->next = p->next;
//        p->next = t;
//    }
//
//}
//
//int LinkedList::Delete(int idx)
//{
//    Node *p, *q = NULL;
//
//    int x = -1;
//
//    if (idx < 1 || idx > Length())
//        return -1;
//
//    if (idx == 1)
//    {
//        p = first;
//        first = first->next;
//        x = p->data;
//        delete p;
//    }
//    else
//    {
//        p = first;
//
//        for (int i = 0; i < idx - 1; ++i)
//        {
//            q = p;
//            p = p->next;
//        }
//        q->next = p->next;
//        x = p->data;
//        delete p;
//    }
//    return x;
//}
//
//
//int main ()
//{
//
//    int A[] = {1, 2, 3, 4, 5};
//
//    LinkedList L1(A, 5);
//
////    cout << L1.Delete(3) << endl;
//
////    cout << L1.Length() << endl;
//
////    L1.Insert(5, 6);
//
//    L1.Display();
//
//    return 0;
//}
