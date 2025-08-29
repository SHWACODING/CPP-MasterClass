//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node
//{
//    struct Node *LChild;
//    int data;
//    int height;
//    struct Node *RChild;
//}*root=NULL;
//
//int NodeHeight(struct Node *p)
//{
//    int hl, hr;
//
//    hl = p && p->LChild ? p->LChild->height : 0;
//    hr = p && p->RChild ? p->RChild->height : 0;
//
//    return hl > hr ? hl + 1 : hr + 1;
//}
//
//int BalanceFactor(struct Node *p)
//{
//    int hl, hr;
//
//    hl = p && p->LChild ? p->LChild->height : 0;
//    hr = p && p->RChild ? p->RChild->height : 0;
//
//    return hl - hr;
//}
//
//struct Node *LLRotation(struct Node *p)
//{
//    struct Node *pl = p->LChild;
//    struct Node *plr = pl->RChild;
//
//    pl->RChild = p;
//    p->LChild = plr;
//
//    // Update Height
//    p->height = NodeHeight(p);
//    pl->height = NodeHeight(pl);
//
//    // Update root
//    if (root == p)
//        root = pl;
//
//    return pl;
//};
//
//struct Node *LRRotation(struct Node *p)
//{
//    struct Node *pl = p->LChild;
//    struct Node *plr = pl->RChild;
//
//    pl->RChild = plr->LChild;
//    p->LChild = plr->RChild;
//
//    plr->LChild = pl;
//    plr->RChild = p;
//
//    // Update Height ?
//    pl->height = NodeHeight(pl);
//    p->height = NodeHeight(p);
//    plr->height = NodeHeight(plr);
//
//    // update root
//    if (root == p)
//        root = plr;
//
//    return plr;
//};
//
//struct Node *RRRotation(struct Node *p)
//{
//    struct Node *pr = p->RChild;
//    struct Node *prl = pr->LChild;
//
//    pr->LChild = p;
//    p->RChild = prl;
//
//    // Update Height ?
//    p->height = NodeHeight(p);
//    pr->height = NodeHeight(pr);
//
//    // Update root ?
//    if (root == p)
//        root = pr;
//
//    return pr;
//};
//
//struct Node *RLRotation(struct Node *p)
//{
//    struct Node *pr = p->RChild;
//    struct Node *prl = pr->LChild;
//
//    pr->LChild = prl->RChild;
//    p->RChild = prl->LChild;
//
//    prl->RChild = pr;
//    prl->LChild = p;
//
//    // Update Height
//    pr->height = NodeHeight(pr);
//    p->height = NodeHeight(p);
//    prl->height = NodeHeight(prl);
//
//    return prl;
//};
//
//struct Node * RInsert (struct Node *p, int key)
//{
//    struct Node *t= NULL;
//
//    if (!p)
//    {
//        t = (struct Node *)malloc(sizeof(struct Node));
//        t->data = key;
//        t->height = 1;
//        t->LChild = t->RChild = NULL;
//        return t;
//    }
//
//    if (key < p->data)
//        p->LChild = RInsert(p->LChild, key);
//    else if (key > p->data)
//        p->RChild = RInsert(p->RChild, key);
//
//    // Update Height
//    p->height = NodeHeight(p);
//
//    // BalanceFactor and Rotation
//    if (BalanceFactor(p) == 2 && BalanceFactor(p->LChild) == 1)
//        return LLRotation(p);
//    else if (BalanceFactor(p) == 2 && BalanceFactor(p->LChild) == -1)
//        return LRRotation(p);
//    else if (BalanceFactor(p) == -2 && BalanceFactor(p->RChild) == -1)
//        return RRRotation(p);
//    else if (BalanceFactor(p) == -2 && BalanceFactor(p->RChild) == 1)
//        return RLRotation(p);
//
//    return p;
//}
//
//void InOrder(struct Node *p)
//{
//    if (p)
//    {
//        InOrder(p->LChild);
//        printf("%d ", p->data);
//        InOrder(p->RChild);
//    }
//}
//
//int main()
//{
//    // LR Rotation :
//    root = RInsert(root, 50);
//    root = RInsert(root, 10);
//    root = RInsert(root, 20);
//
//    printf("InOrder Representation : ");
//    InOrder(root);
//    printf("\n");
//    printf("LR Root Data ==> %d", root->data);
//    printf("\n");
//
//    // RL Rotation :
//    root = RInsert(root, 20);
//    root = RInsert(root, 50);
//    root = RInsert(root, 60);
//
//    printf("InOrder Representation : ");
//    InOrder(root);
//    printf("\n");
//    printf("RL Root Data ==> %d", root->data);
//    printf("\n");
//}
