//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node
//{
//    struct Node *LChild;
//    int data;
//    struct Node *RChild;
//}*root=NULL;
//
//void Insert (int key)
//{
//    struct Node *t = root;
//    struct Node *r, *p;
//
//    if (root == NULL)
//    {
//        p = (struct Node *)malloc(sizeof(struct Node));
//        p->data = key;
//        p->LChild = p->RChild = NULL;
//        root = p;
//        return;
//    }
//    while (t != NULL)
//    {
//        r = t;
//
//        if (key < t->data)
//            t = t->LChild;
//        else if (key > t->data)
//            t = t->RChild;
//        else
//            return;
//    }
//
//    p = (struct Node *)malloc(sizeof(struct Node));
//    p->data = key;
//    p->LChild = p->RChild = NULL;
//
//    if (key < r->data)
//        r->LChild = p;
//    else
//        r->RChild = p;
//}
//
//void PreOrder(struct Node *p)
//{
//    if (p)
//    {
//        printf("%d ", p->data);
//        PreOrder(p->LChild);
//        PreOrder(p->RChild);
//    }
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
//void PostOrder(struct Node *p)
//{
//    if (p)
//    {
//        PostOrder(p->LChild);
//        PostOrder(p->RChild);
//        printf("%d ", p->data);
//    }
//}
//
//struct Node * Search(int key)
//{
//    struct Node *t = root;
//
//    while (t)
//    {
//        if (key == t->data)
//            return t;
//        else if (key < t->data)
//            t = t->LChild;
//        else
//            t = t->RChild;
//    }
//    return NULL;
//};
//
//struct Node * RInsert (struct Node *p, int key)
//{
//    struct Node *t= NULL;
//    if (!p)
//    {
//        t = (struct Node *)malloc(sizeof(struct Node));
//        t->data = key;
//        t->LChild = t->RChild = NULL;
//        return t;
//    }
//
//    if (key < p->data)
//        p->LChild = RInsert(p->LChild, key);
//    else if (key > p->data)
//        p->RChild = RInsert(p->RChild, key);
//
//    return p;
//}
//
//int Height (struct Node *p)
//{
//    int x, y;
//
//    if (p == NULL)
//        return 0;
//
//    x = Height(p->LChild);
//    y = Height(p->RChild);
//
//    return x > y ? x + 1 : y + 1;
//}
//
//struct Node *InPre(struct Node *p)
//{
//    while (p && p->RChild != NULL)
//        p = p->RChild;
//
//    return p;
//};
//
//struct Node *InSucc(struct Node *p)
//{
//    while (p && p->LChild != NULL)
//        p = p->LChild;
//
//    return p;
//};
//
//struct Node *Delete (struct Node *p, int key)
//{
//    struct Node *q;
//
//    if (!p)
//        return NULL;
//    if (!p->LChild && !p->RChild)
//    {
//        if (p == root)
//            root = NULL;
//        free(p);
//        return NULL;
//    }
//
//    if (key < p->data)
//        p->LChild = Delete(p->LChild, key);
//    else if (key > p->data)
//        p->RChild = Delete(p->RChild, key);
//    else
//    {
//        if (Height(p->LChild) > Height(p->RChild))
//        {
//            q = InPre(p->LChild);
//            p->data = q->data;
//            p->LChild = Delete(p->LChild, q->data);
//        }
//        else
//        {
//            q = InSucc(p->RChild);
//            p->data = q->data;
//            p->RChild = Delete(p->RChild, q->data);
//        }
//    }
//    return p;
//};
//
//
//int main ()
//{
//    struct Node *temp;
//
////    Insert(10);
////    Insert(5);
////    Insert(20);
////    Insert(8);
////    Insert(30);
//
//    root = RInsert(root, 40);
//    RInsert(root, 50);
//    RInsert(root, 60);
//    RInsert(root, 70);
//    RInsert(root, 80);
//    RInsert(root, 90);
//
//    Delete(root, 50);
//
//    printf("\n");
//    printf("PreOrder Representation : ");
//    PreOrder(root);
//    printf("\n");
//    printf("InOrder Representation : ");
//    InOrder(root);
//    printf("\n");
//    printf("PostOrder Representation : ");
//    PostOrder(root);
//    printf("\n");
//
//    temp = Search(80);
//    if(temp)
//        printf("Element %d Is Found ??\n", temp->data);
//    else
//        printf("Element Is Not Found ??\n");
//
//    return 0;
//}
