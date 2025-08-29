#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    Node *Lchild;
    int data;
    Node *Rchild;

    Node(){};
    Node(int data);
};

Node::Node(int data)
{
    Lchild = nullptr;
    this->data = data;
    Rchild = nullptr;
}

// ------------------------------------------------------------
// Tree Class ?

//class Tree
//{
//public:
//    Node *root;
//
//    Tree(){root = NULL;}
//    void CreateTree();
//    void PreOrder (Node *p);
//    void InOrder (Node *p);
//    void PostOrder (Node *p);
//    void LevelOrder(Node *p);
//    int Height(Node *root);
//    int Count(Node* root);
//    void IPreOrder(Node* p);
//    void IInOrder(Node* p);
//    void IPostOrder(Node* p);
//    Node* GenerateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
//};

// Here We Can Make root Private ??
class Tree
{
private:
    Node *root;
public:
    Tree(){root = NULL;}
    void CreateTree();
    void PreOrder(){PreOrder(root);} // Recursive Function ?
    void PreOrder (Node* p);
    void InOrder(){InOrder(root);} // Recursive Function ?
    void InOrder (Node* p);
    void PostOrder(){PostOrder(root);} // Recursive Function ?
    void PostOrder (Node* p);
    void LevelOrder(){LevelOrder(root);} // Recursive Function ?
    void LevelOrder(Node* p);
    int Height(Node* p);
    int Height(){return Height(root);} // Recursive Function ?
    int Count(Node* p);
    int Count() {return Count(root);} // Recursive Function ?
    void IPreOrder(Node* p);
    void IPreOrder(){IPreOrder(root);} // Recursive Function ?
    void IInOrder(Node* p);
    void IInOrder(){IInOrder(root);} // Recursive Function ?
    void IPostOrder(Node* p);
    void IPostOrder(){IPostOrder(root);} // Recursive Function ?
    Node* GenerateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
};

// ------------------------------------------------------------
// Queue ?

class Queue
{
private:
    int Front;
    int Rear;
    int Size;
    Node **Q;
public:
    Queue () {Front = Rear = -1; Size = 10; Q = new Node *[Size];}
    Queue (int Size) {Front = Rear = -1; this->Size = Size; Q = new Node *[this->Size];}
    void Enqueue(Node *x);
    Node * Dequeue();
    void Display();
    int IsEmpty();
};

void Queue::Enqueue(Node *x)
{
    if (Rear == Size - 1)
        cout << "Queue Is Full ??\n";
    else
    {
        Rear++;
        Q[Rear] = x;
    }
}

Node * Queue::Dequeue()
{
    Node* x = NULL;

    if (Front == Rear)
        cout << "Queue Is Empty ??\n";
    else
    {
        x = Q[Front + 1];
        Front++;
    }
    return x;
}

void Queue::Display()
{
    for (int i = Front + 1; i <= Rear; ++i)
        cout << Q[i] << " " << flush;
    cout << endl;
}

int Queue::IsEmpty()
{
    return Front == Rear;
}

// ------------------------------------------------------------
// Tree Functions ?

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter Root Values : " << flush;
    cin >> x;

    root = new Node;
    root->data = x;
    root->Lchild = root->Rchild = nullptr;
    q.Enqueue(root);

    while(!q.IsEmpty())
    {
        p = q.Dequeue();

        cout << "Enter Left Child Of " << p->data << " :  " << flush;
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = NULL;
            p->Lchild = t;
            q.Enqueue(t);
        }

        cout << "Enter Right Child Of " << p->data << " :  " << flush;
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = NULL;
            p->Rchild = t;
            q.Enqueue(t);
        }
    }
}

void Tree::PreOrder(Node* p)
{
    if(p)
    {
        cout << p->data << " " << flush;
        PreOrder(p->Lchild);
        PreOrder(p->Rchild);
    }
}

void Tree::InOrder(Node* p)
{
    if(p)
    {
        InOrder(p->Lchild);
        cout << p->data << " " << flush;
        InOrder(p->Rchild);
    }
}

void Tree::PostOrder(Node* p)
{
    if(p)
    {
        PostOrder(p->Lchild);
        PostOrder(p->Rchild);
        cout << p->data << " " << flush;
    }
}

void Tree::LevelOrder(Node* p)
{
    Queue q(100);

    cout << root->data << " ";
    q.Enqueue(root);

    while(!q.IsEmpty())
    {
        root = q.Dequeue();

        if (root->Lchild)
        {
            cout << root->Lchild->data << " ";
            q.Enqueue(root->Lchild);
        }
        if (root->Rchild)
        {
            cout << root->Rchild->data << " ";
            q.Enqueue(root->Rchild);
        }
    }
}

int Tree::Height(Node *p)
{
    int x = 0, y = 0;

    if (p == nullptr)
        return 0;

    x = Height(p->Lchild);
    y = Height(p->Rchild);

    if(x > y)
        return x + 1;
    else
        return y + 1;
}

int Tree::Count(Node* p)
{
    if(p)
        return Count(p->Lchild) + Count(p->Rchild) + 1;
    return 0;
}

//void Tree::IPreOrder(Node *p)
//{
//    stack<Node*> stk;
//
//    while (p != nullptr || ! stk.empty())
//    {
//        if (p != nullptr)
//        {
//            cout << p->data << ", " << flush;
//            stk.emplace(p);
//            p = p->Lchild;
//        }
//        else
//        {
//            p = stk.top();
//            stk.pop();
//            p = p->Rchild;
//        }
//    }
//    cout << endl;
//}
//
//void Tree::IInOrder(Node *p)
//{
//    stack<Node*> stk;
//    while(p != nullptr || !stk.empty())
//    {
//        if (p != nullptr)
//        {
//            stk.emplace(p);
//            p = p->Lchild;
//        }
//        else
//        {
//            p = stk.top();
//            stk.pop();
//            cout << p->data << ", " << flush;
//            p = p->Rchild;
//        }
//    }
//    cout << endl;
//}

//void Tree::IPostOrder(Node *p)
//{
//    stack<long int> stk;
//    long int temp;
//
//    while(p != nullptr || !stk.empty())
//    {
//        if (p != nullptr)
//        {
//            stk.emplace((long int)p);
//            p = p->Lchild;
//        }
//        else
//        {
//            temp = stk.top();
//            stk.pop();
//            if (temp > 0)
//            {
//                stk.emplace(-temp);
//                p = ((Node*)temp)->Rchild;
//            }
//            else
//            {
//                cout << ((Node*)(-1 * temp))->data << ", " << flush;
//                p = nullptr;
//            }
//        }
//    }
//    cout << endl;
//}

// Generating Tree From Traversal ??
// PreOrder + InOrder || PostOrder + InOrder

int SearchInOrder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; ++i)
    {
        if (inArray[i] == data)
            return i;
    }
    return -1;
}

Node* Tree::GenerateFromTraversal (int *inorder, int *preorder, int inStart, int inEnd)
{
    static int preIndex = 0;

    if (inStart > inEnd)
        return nullptr;

    Node* node = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
        return node;

    int splitIndex = SearchInOrder(inorder, inStart, inEnd, node->data);

    node->Lchild = GenerateFromTraversal(inorder, preorder, inStart, splitIndex - 1);

    node->Rchild = GenerateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

    return node;
}

 // ------------------------------------------------------------

int main()
{
    Tree t;
    t.CreateTree();

    cout << endl << endl;
    cout << "This Is PreOrder Representation Of Tree :  ";
    t.PreOrder();
//    t.PreOrder(t.root);
    cout << endl << endl;

    cout << "This Is InOrder Representation Of Tree :  ";
    t.InOrder();
//    t.InOrder(t.root);
    cout << endl << endl;

    printf("This Is PostOrder Representation Of Tree :  ");
    t.PostOrder();
//    t.PostOrder(t.root);
    cout << endl << endl;

    cout << "Level Order Of This Tree :  " << flush;
    t.LevelOrder();
//    t.LevelOrder(t.root);
    cout << endl << endl;

    cout << "Height Of This Tree : " << t.Height();
    cout << endl << endl;

    cout << "Number Of Nodes In this Tree : " << t.Count();
    cout << endl << endl;

//    cout << "This Is Ietrative PreOrder Representation Of Tree :  " << flush;
//    t.IPreOrder();
////    t.IPreOrder(t.root);
//    cout << endl << endl;
//
//    cout << "This Is Ietrative InOrder Representation Of Tree :  " << flush;
//    t.IInOrder();
////    t.IInOrder(t.root);
//    cout << endl << endl;
//
//    cout << "This Is Ietrative PostOrder Representation Of Tree :  " << flush;
//    t.IPostOrder();
////    t.IPostOrder(t.root);
//    cout << endl << endl;

    Tree bt;

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    Node* T = bt.GenerateFromTraversal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0]-1));

    bt.PreOrder(T);

    return 0;
}
