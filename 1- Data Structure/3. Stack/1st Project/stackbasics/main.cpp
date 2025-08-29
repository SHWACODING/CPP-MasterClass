#include <iostream>
#include <cstring>

using namespace std;

//// Implementation Of Stack Using Array ?????

//class Stack
//{
//private:
//    int sz;
//    int Top;
//    int *S;
//public:
//    Stack(int sz);
//    ~Stack();
//    void Push(int x);
//    int Pop();
//    int Peek(int index);
//    int IsFull();
//    int IsEmpty();
//    void Display();
//    int StackTop();
//};
//
//Stack::Stack(int sz)
//{
//    this->sz = sz;
//    Top = -1;
//    S = new int[sz];
//}
//
//Stack::~Stack()
//{
//    delete[] S;
//}
//
//void Stack::Display()
//{
//    for (int i = Top; i >= 0; --i)
//        cout << S[i] << " | " << flush;
//    cout << endl;
//}
//
//void Stack::Push(int x)
//{
//    if (IsFull())
//        cout << "Stack Overflow ??? \n";
//    else
//    {
//        Top++;
//        S[Top] = x;
//    }
//}
//
//int Stack::Pop()
//{
//    int x = -1;
//    if (IsEmpty())
//        cout << "Stack Underflow ??? \n";
//    else
//    {
//        x = S[Top];
//        Top--;
//    }
//    return x;
//}
//
//int Stack::Peek(int index)
//{
//    int x = -1;
//
//    if (Top - index + 1 < 0 || Top - index + 1 == sz)
//        cout << "Invalid Position ??? \n";
//    else
//        x = S[Top - index + 1];
//    return x;
//}
//
//int Stack::IsFull()
//{
//    return Top == sz-1 ? 1 : 0;
//}
//
//int Stack::IsEmpty()
//{
//    return Top == -1 ? 1 : 0;
//}
//
//int Stack::StackTop()
//{
//    return IsEmpty() ? -1 : S[Top];
//}
//
//
//
//int main()
//{
//    int A[] = {1, 3, 5, 7, 9};
//
//    Stack stk(sizeof(A) / sizeof(A[0]));
//
//    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
//        stk.Push(A[i]);
//    stk.Push(11);
//
//    cout << "Stack Full : " << stk.IsFull() << endl;
//
//    cout << "Stack : " << flush;
//    stk.Display();
//
//    cout << "Peek At 0Th Position : " << stk.Peek(0) << endl;
//    cout << "Peek At 3Th Position : " << stk.Peek(3) << endl;
//    cout << "Peek At 10Th Position : " << stk.Peek(10) << endl;
//
//    cout << "Stack Top Element : " << stk.StackTop() << endl;
//
//    cout << "Popped Out Elements : " << flush;
//    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
//        cout << stk.Pop() << ", " << flush;
//
//    cout << endl;
//    stk.Pop();
//
//    cout << "Stack Is Empty : " << stk.IsEmpty() << endl;
//
//
//    return 0;
//}

//----------------------------------------------------------------------------------------------------

//// Implementation Of Stack Using Linked List ?????

//class Node
//{
//public:
//    int data;
//    Node *next;
//};
//
//class Stack
//{
//private:
//    Node *Top;
//public:
//    Stack () { Top = NULL; }
//    ~Stack ();
//    void Push (int x);
//    int Pop();
//    int Peek (int index);
//    int IsEmpty ();
//    int IsFull ();
//    int StackTop ();
//    void Display ();
//};
//
//Stack::~Stack ()
//{
//    Node *p = Top;
//    while (Top)
//    {
//        Top = Top->next;
//        delete p;
//        p = Top;
//    }
//}
//
//void Stack::Push(int x)
//{
//    Node *t = new Node;
//
//    if (t == NULL)
//        cout << " Stack Overflow ??? \n";
//    else
//    {
//        t->data = x;
//        t->next = Top;
//        Top = t;
//    }
//}
//
//int Stack::Pop ()
//{
//    Node *p;
//    int x = -1;
//
//    if (Top == NULL)
//        cout << "Stack Underflow ??? \n";
//    else
//    {
//        p = Top;
//        x = p->data;
//        Top = Top->next;
//        delete p;
//    }
//    return x;
//}
//
//int Stack::Peek(int index)
//{
//    if (IsEmpty())
//        return -1;
//    else
//    {
//        Node *p = Top;
//
//        for (int i = 0; p && i < index - 1; ++i)
//            p = p->next;
//        if (p)
//            return p->data;
//        else
//            return -1;
//    }
//}
//
//int Stack::IsFull()
//{
//    Node *t = new Node;
//    int r = t ? 1 : 0;
//    delete t;
//    return r;
//}
//
//int Stack::IsEmpty()
//{
//    return Top ? 0 : 1;
//}
//
//int Stack::StackTop()
//{
//    if (Top)
//        return Top->data;
//    return -1;
//}
//
//
////int main ()
////{
////    int A[] = {1, 3, 5, 7, 9};
////
////    Stack stk;
////
////    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
////        stk.Push(A[i]);
////
////    stk.Push(11);
////
////    cout << "Stack Full : " << stk.IsFull() << endl;
////
////    cout << "Stack Peek At 3rd Position : " << stk.Peek(3) << endl;
////    cout << "Stack Peek At 10th Position : " << stk.Peek(10) << endl;
////
////    cout << "Stack Top : " << stk.StackTop() << endl;
////    cout << "Stack Full : " << stk.IsFull() << endl;
////    cout << "Stack Empty : " << stk.IsEmpty() << endl;
////
////    cout << "Popped Elements : " << flush;
////    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
////        cout << stk.Pop() << ", " << flush;
////
////    cout << endl;
////    cout << stk.Pop() << endl;
////
////    cout << "Stack Is Empty : " << stk.IsEmpty() << endl;
////
////    return 0;
////}

//----------------------------------------------------------------------------------------------------

//// Balanced Parenthesis Matching Via Stack Using Array ??

//class Stack
//{
//private:
//    int sz;
//    int Top;
//    char *S;
//public:
//    Stack(int sz);
//    ~Stack();
//    void Push(char x);
//    int Pop();
//    int IsEmpty();
//    int IsBalanced (char* exp);
//};
//
//Stack::Stack(int sz)
//{
//    this->sz = sz;
//    Top = -1;
//    S = new char[sz];
//}
//
//Stack::~Stack()
//{
//    delete[] S;
//}
//
//void Stack::Push(char x)
//{
//    if (Top == sz - 1)
//        cout << "Stack Overflow ??? \n";
//    else
//    {
//        Top++;
//        S[Top] = x;
//    }
//}
//
//int Stack::Pop()
//{
//    char x = -1;
//    if (IsEmpty())
//        cout << "Stack Underflow ??? \n";
//    else
//    {
//        x = S[Top];
//        Top--;
//    }
//    return x;
//}
//
//int Stack::IsEmpty()
//{
//    return Top == -1 ? 1 : 0;
//}
//
//int Stack::IsBalanced(char *exp)
//{
//    Stack stk(sizeof(exp) / sizeof(char));
//
//    for (int i = 0; i < strlen(exp); ++i)
//    {
//        if (exp[i] == '(')
//                stk.Push(exp[i]);
//        else if (exp[i] == ')')
//        {
//            if (stk.IsEmpty())
//                return false;
//            else
//                stk.Pop();
//        }
//    }
//    return stk.IsEmpty() ? true : false;
//}
//
//
//int main ()
//{
//
//    char E[] = "((a+b)*(c-d))";
//    Stack stk(20);
//
//    if (stk.IsBalanced(E))
//        cout << "This Equation Parenthesis Matching Is Balanced ?? \n";
//    else
//        cout << "This Equation Parenthesis Matching Is Not Balanced ?? \n";
//
//
//    char F[] = "(((a+b)*(c-d))";
//
//    if (stk.IsBalanced(F))
//        cout << "This Equation Parenthesis Matching Is Balanced ?? \n";
//    else
//        cout << "This Equation Parenthesis Matching Is Not Balanced ?? \n";
//
//
//    char G[] = "((a+b)*(c-d)))";
//
//    if (stk.IsBalanced(G))
//        cout << "This Equation Parenthesis Matching Is Balanced ?? \n";
//    else
//        cout << "This Equation Parenthesis Matching Is Not Balanced ?? \n";
//
//    return 0;
//}

//----------------------------------------------------------------------------------------------------

//// Balanced Parenthesis Matching Via Stack Using Linked List ??

//class Node
//{
//public:
//    char data;
//    Node *next;
//};
//
//class Stack
//{
//private:
//    Node *Top;
//public:
//    Stack () { Top = NULL; }
//    ~Stack ();
//    void Push (char x);
//    char Pop();
//    int IsBalanced (char* exp);
//};
//
//Stack::~Stack ()
//{
//    Node *p = Top;
//    while (Top)
//    {
//        Top = Top->next;
//        delete p;
//        p = Top;
//    }
//}
//
//void Stack::Push(char x)
//{
//    Node *t = new Node;
//
//    if (t == NULL)
//        cout << " Stack Overflow ??? \n";
//    else
//    {
//        t->data = x;
//        t->next = Top;
//        Top = t;
//    }
//}
//
//char Stack::Pop ()
//{
//    Node *p;
//    char x = -1;
//
//    if (Top == NULL)
//        cout << "Stack Underflow ??? \n";
//    else
//    {
//        p = Top;
//        x = p->data;
//        Top = Top->next;
//        delete p;
//    }
//    return x;
//}
//
//int Stack::IsBalanced (char* exp)
//{
//    Stack stk;
//
//    for (int i = 0; i < strlen(exp); ++i)
//    {
//        if (exp[i] == '(')
//                stk.Push(exp[i]);
//        else if (exp[i] == ')')
//        {
//            if (stk.Top == NULL)
//                return false;
//            else
//                stk.Pop();
//        }
//    }
//    return stk.Top == NULL ? true : false;
//}
//
//
//int main ()
//{
//    Stack stk;
//
//    char E[] = "((a+b)*(c-d))";
//
//    if (stk.IsBalanced(E))
//        cout << "This Equation Parenthesis Matching Is Balanced ?? \n";
//    else
//        cout << "This Equation Parenthesis Matching Is Not Balanced ?? \n";
//
//
//    char F[] = "((a+b)*(c-d)))";
//
//    if (stk.IsBalanced(F))
//        cout << "This Equation Parenthesis Matching Is Balanced ?? \n";
//    else
//        cout << "This Equation Parenthesis Matching Is Not Balanced ?? \n";
//
//
//    char G[] = "(((a+b)*(c-d))";
//
//    if (stk.IsBalanced(G))
//        cout << "This Equation Parenthesis Matching Is Balanced ?? \n";
//    else
//        cout << "This Equation Parenthesis Matching Is Not Balanced ?? \n";
//
//    return 0;
//}

