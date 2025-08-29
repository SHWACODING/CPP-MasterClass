#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    Node* LChild;
    int data;
    Node* RChild;
};

class BST
{
private:
    Node* root;
public:
    BST () { root = nullptr; }
    Node* getRoot () { return root; }
    void IInsert (int key);
    void PreOrder (Node* p);
    void InOrder (Node* p);
    void PostOrder (Node* p);
    Node* ISearch (int key);
    Node* RInsert(Node* p, int key);
    Node* RSearch(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
    void GenerateFromPreOrder (int pre[], int n);
};

void BST::IInsert(int key)
{
    Node* t = root;
    Node* p;
    Node* r;

    // Root Is Empty ?
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->LChild = p->RChild = nullptr;
        root = p;
        return;
    }
    while (t != nullptr)
    {
        r = t;
        if (key < t->data)
            t = t->LChild;
        else if (key > t->data)
            t = t->RChild;
        else
            return;
    }
    // Now t Points at NULL and r Points at Insert Location ?
    p = new Node;
    p->data = key;
    p->LChild = p->RChild = nullptr;

    if (key < r->data)
        r->LChild = p;
    else
        r->RChild = p;
}

void BST::PreOrder(Node* p)
{
    if (p)
    {
        cout << p->data << ", " << flush;
        PreOrder(p->LChild);
        PreOrder(p->RChild);
    }
}

void BST::InOrder(Node* p)
{
    if (p)
    {
        InOrder(p->LChild);
        cout << p->data << ", " << flush;
        InOrder(p->RChild);
    }
}

void BST::PostOrder(Node* p)
{
    if (p)
    {
        PostOrder(p->LChild);
        PostOrder(p->RChild);
        cout << p->data << ", " << flush;
    }
}

Node* BST::ISearch(int key)
{
    Node* t = root;

    while (t != nullptr)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->LChild;
        else
            t = t->RChild;
    }
    return nullptr;
}

Node* BST::RInsert(Node* p, int key)
{
    Node* t;
    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->LChild = t->RChild = nullptr;
        return t;
    }

    if (key < p->data)
        p->LChild = RInsert(p->LChild, key);
    else if (key > p->data)
        p->RChild = RInsert(p->RChild, key);

    return p; // key == p->data
}

Node* BST::RSearch(Node* p, int key)
{
    if (p == nullptr)
        return nullptr;

    if (key == p->data)
        return p;
    else if (key < p->data)
        return RSearch(p->LChild, key);
    else
        return RSearch(p->RChild, key);
}

Node* BST::Delete(Node* p, int key)
{
    Node* q;

    if (p == nullptr)
        return nullptr;

    if (p->LChild == nullptr && p->RChild == nullptr)
    {
        if (p == root)
            root = nullptr;

        delete p;

        return nullptr;
    }

    if (key < p->data)
        p->LChild = Delete(p->LChild, key);
    else if (key > p->data)
        p->RChild = Delete(p->RChild, key);
    else
    {
        if (Height(p->LChild) > Height(p->RChild))
        {
            q = InPre(p->LChild);
            p->data = q->data;
            p->LChild = Delete(p->LChild, q->data);
        }
        else
        {
            q = InSucc(p->RChild);
            p->data = q->data;
            p->RChild = Delete(p->RChild, q->data);
        }
    }
    return p;
}

int BST::Height(Node *p)
{
    int x, y;

    if (p == nullptr)
        return 0;

    x = Height(p->LChild);
    y = Height(p->RChild);

    return x > y ? x + 1 : y + 1;
}

Node* BST::InPre(Node* p)
{
    while (p && p->RChild != nullptr)
        p = p->RChild;

    return p;
}

Node* BST::InSucc(Node* p)
{
    if (p && p->LChild != nullptr)
        p = p->LChild;

    return p;
}

// Generate BST From PreOrder ?

void BST::GenerateFromPreOrder (int *pre, int n)
{
    // Create Root Node
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->LChild = root->RChild = nullptr;

    // Iterative Steps
    Node* t;
    Node* p = root;
    stack<Node*> stk;

    while (i < n)
    {
        // Left Child Case
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->LChild = t->RChild = nullptr;
            p->LChild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            // Right Child Cases
            if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data)
            {
                t = new Node;
                t->data = pre[i++];
                p->LChild = p->RChild = nullptr;
                p->RChild  =t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

int main()
{
    BST bst;

    // Iterative Insert ?
    bst.IInsert(10);
    bst.IInsert(5);
    bst.IInsert(20);
    bst.IInsert(8);
    bst.IInsert(30);

    // PreOrder Traversal ?
    cout << "PreOrder Representation : " << flush;
    bst.PreOrder(bst.getRoot());
    cout << endl;

    // InOrder Traversal ?
    cout << "InOrder Representation : " << flush;
    bst.InOrder(bst.getRoot());
    cout << endl;

    // PostOrder Traversal ?
    cout << "PostOrder Representation : " << flush;
    bst.PostOrder(bst.getRoot());
    cout << endl;

    // Iterative Search ?
    Node* temp = bst.ISearch(20);
    if (temp != nullptr)
        cout << "Element " << temp->data << " Is Found.\n";
    else
        cout << "Element Is Not Found.\n";

    // Recursive Search ?
    temp = bst.RSearch(bst.getRoot(), 20);
    if (temp != nullptr)
        cout << "Element " << temp->data << " Is Found.\n";
    else
        cout << "Element Is Not Found.\n";

    // Recursive Insert ?
    bst.RInsert(bst.getRoot(), 50);
    bst.RInsert(bst.getRoot(), 70);
    bst.RInsert(bst.getRoot(), 1);

    // PreOrder Traversal ?
    cout << "PreOrder Representation : " << flush;
    bst.PreOrder(bst.getRoot());
    cout << endl;

    // InOrder Traversal ?
    cout << "InOrder Representation : " << flush;
    bst.InOrder(bst.getRoot());
    cout << endl;

    // PostOrder Traversal ?
    cout << "PostOrder Representation : " << flush;
    bst.PostOrder(bst.getRoot());
    cout << endl;

    // Inorder Predecessor and Inorder Successor
    BST bs;

    bs.IInsert(5);
    bs.IInsert(2);
    bs.IInsert(8);
    bs.IInsert(7);
    bs.IInsert(9);
    bs.IInsert(1);

    temp = bs.InPre(bs.getRoot());
    cout << "InPre : " << temp->data << endl;

    temp = bs.InSucc(bs.getRoot());
    cout << "InPre : " << temp->data << endl;

    // InOrder Traversal ?
    cout << "InOrder Representation : " << flush;
    bst.InOrder(bs.getRoot());
    cout << endl;

    // Delete ?
    bs.Delete(bs.getRoot(), 7);

    // InOrder Traversal ?
    cout << "InOrder Representation : " << flush;
    bst.InOrder(bs.getRoot());
    cout << endl;

    // BST From PreOrder Traversal ?
    cout << "BST From PreOrder ==> \n" << flush;

    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};

    int n = sizeof(pre) / sizeof(pre[0]);

    BST b;

    b.GenerateFromPreOrder(pre, n);

    // InOrder Traversal ?
    cout << "PreOrder Representation : " << flush;
    b.PreOrder(b.getRoot());
    cout << endl;

    return 0;
}
