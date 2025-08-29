#include <iostream>

using namespace std;

class Node
{
public:
    Node* LChild;
    int data;
    int height;
    Node *RChild;
};

class AVL
{
public:
    Node* root;

    AVL () { root = nullptr; }

    // Helper Method For Inserting?
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);

    // Insert
    Node* RInsert(Node* p, int key);

    // Traversal
    void InOrder (Node* p);
    void InOrder () { InOrder(root); }
    Node* getRoot () { return root; }

    // Delete
    Node* Delete(Node* p, int key);
};

int AVL::NodeHeight(Node *p)
{
    int hl, hr;

    hl = (p && p->LChild) ? p->LChild->height : 0;
    hr = (p && p->RChild) ? p->RChild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node *p)
{
    int hl, hr;

    hl = (p && p->LChild) ? p->LChild->height : 0;
    hr = (p && p->RChild) ? p->RChild->height : 0;

    return hl - hr;
}

Node* AVL::LLRotation(Node *p)
{
    Node* pl = p->LChild;
    Node* plr = pl->RChild;

    pl->RChild = p;
    p->LChild = plr;

    // Update Height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p)
        root = pl;

    return pl;
}

Node* AVL::RRRotation(Node *p)
{
    Node* pr = p->RChild;
    Node* prl = pr->LChild;

    pr->LChild = p;
    p->RChild = prl;

    // Update Height ?
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root ?
    if (root == p)
        root = pr;

    return pr;
}

Node* AVL::LRRotation(Node *p)
{
    Node* pl = p->LChild;
    Node* plr = pl->RChild;

    pl->RChild = plr->LChild;
    p->LChild = plr->RChild;

    plr->LChild = pl;
    plr->RChild = p;

    // Update Height ?
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // update root
    if (root == p)
        root = plr;

    return plr;
}

Node* AVL::RLRotation(Node *p)
{
    Node* pr = p->RChild;
    Node* prl = pr->LChild;

    pr->LChild = prl->RChild;
    p->RChild = prl->LChild;

    prl->RChild = pr;
    prl->LChild = p;

    // Update Height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    return prl;
}

Node* AVL::InPre(Node *p) {
    while (p && p->RChild != nullptr){
        p = p->RChild;
    }
    return p;
}

Node* AVL::InSucc(Node *p) {
    while (p && p->LChild != nullptr){
        p = p->LChild;
    }
    return p;
}

Node* AVL::RInsert(Node *p, int key)
{
    Node *t= nullptr;

    if (!p)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->LChild = t->RChild = nullptr;
        return t;
    }

    if (key < p->data)
        p->LChild = RInsert(p->LChild, key);
    else if (key > p->data)
        p->RChild = RInsert(p->RChild, key);

    // Update Height
    p->height = NodeHeight(p);

    // BalanceFactor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->LChild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->LChild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->RChild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->RChild) == 1)
        return RLRotation(p);

    return p;
}

void AVL::InOrder(Node* p)
{
    if (p)
    {
        InOrder(p->LChild);
        cout << p->data << ", " << flush;
        InOrder(p->RChild);
    }
}

Node* AVL::Delete(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }

    if (p->LChild == nullptr && p->RChild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data){
        p->LChild = Delete(p->LChild, key);
    } else if (key > p->data){
        p->RChild = Delete(p->RChild, key);
    } else {
        Node* q;
        if (NodeHeight(p->LChild) > NodeHeight(p->RChild)){
            q = InPre(p->LChild);
            p->data = q->data;
            p->LChild = Delete(p->LChild, q->data);
        } else {
            q = InSucc(p->RChild);
            p->data = q->data;
            p->RChild = Delete(p->RChild, q->data);
        }
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->LChild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->LChild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->RChild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->RChild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->LChild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->RChild) == 0){  // R0 Rotation
        return RRRotation(p);
    }

    return p;
}

int main()
{
    // LR Rotation :
    AVL tlr;

    tlr.root = tlr.RInsert(tlr.root, 50);
    tlr.root = tlr.RInsert(tlr.root, 10);
    tlr.root = tlr.RInsert(tlr.root, 20);

    cout << "LR InOrder Representation : " << flush;
    tlr.InOrder(tlr.root);
    cout << endl;
    cout << "LR Root Data ==> " << tlr.root->data;
    cout << endl;

    // RL Rotation :
    AVL trl;

    trl.root = trl.RInsert(trl.root, 20);
    trl.root = trl.RInsert(trl.root, 50);
    trl.root = trl.RInsert(trl.root, 60);

    cout << "RL InOrder Representation : " << flush;
    trl.InOrder(trl.root);
    cout << endl;
    cout << "RL Root Data ==> " << trl.root->data;
    cout << endl;

    cout << "\n---------------------------------------------\n\n";

    // Try Deletion
    AVL tree;

    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.root = tree.RInsert(tree.root, A[i]);
    }

    cout << "InOrder Representation Before Deleting : " << flush;
    tree.InOrder();
    cout << endl;

    tree.Delete(tree.root, 28);
    cout << "InOrder Representation After Deleting : " << flush;
    tree.InOrder();
    cout << endl;

    return 0;
}
