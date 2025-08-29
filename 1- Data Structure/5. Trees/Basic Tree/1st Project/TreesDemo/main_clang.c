//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node
//{
//    struct Node *Lchild;
//    int data;
//    struct Node *Rchild;
//};
//
////----------------------------------
//
//struct Queue
//{
//    int Size;
//    int Front;
//    int Rear;
//    struct Node **Q;
//};
//
//struct Node *root = NULL;
//
//// ------------------------------------------------------------
//// Queue ?
//
//void CreateQueue(struct Queue *q, int size)
//{
//    q->Size = size;
//    q->Front = q->Rear = 0;
//    q->Q = (struct Node **)malloc(q->Size * sizeof(struct Node *));
//}
//
//void Enqueue(struct Queue *q, struct Node *x)
//{
//    if ((q->Rear + 1) % q->Size == q->Front)
//        printf("Queue Is Full ??");
//    else
//    {
//        q->Rear = (q->Rear + 1) % q->Size;
//        q->Q[q->Rear] = x;
//    }
//}
//
//struct Node * Dequeue(struct Queue *q)
//{
//    struct Node* x = NULL;
//    if (q->Front == q->Rear)
//        printf("Queue Is Empty ??");
//    else
//    {
//        q->Front = (q->Front + 1) % q->Size;
//        x = q->Q[q->Front];
//    }
//    return x;
//}
//
//int IsEmptyQueue(struct Queue q)
//{
//    return q.Front == q.Rear;
//}
//
//// ------------------------------------------------------------//
//// Stack ??
//struct Stack
//{
//    int Size;
//    int Top;
//    struct Node **S;
//};
//
//void CreateStack(struct Stack *st, int Size)
//{
//    st->Size = Size;
//    st->Top = -1;
//    st->S = (struct Node **)malloc(st->Size*sizeof(struct Node *));
//}
//
//void Push(struct Stack *st, struct Node *x)
//{
//    if(st->Top == st->Size - 1)
//        printf("Stack Overflow ??\n");
//    else
//    {
//        st->Top++;
//        st->S[st->Top] = x;
//    }
//}
//
//struct Node *Pop(struct Stack *st)
//{
//    struct Node *x = NULL;
//
//    if(st->Top == -1)
//        printf("Stack Underflow ??\n");
//    else
//    {
//        x = st->S[st->Top--];
//    }
//    return x;
//};
//
//int IsEmptyStack(struct Stack st)
//{
//    return st.Top == -1;
//}
//
//int IsFullStack (struct Stack st)
//{
//    return st.Top == st.Size-1;
//}
//
//// ------------------------------------------------------------
//// Linked Tree ?
//
//void CreateTree()
//{
//    struct Node *p, *t;
//    int x;
//    struct Queue q;
//    CreateQueue(&q, 100);
//
//    printf("Enter Root Value : ");
//    scanf("%d", &x);
//
//    root = (struct Node *)malloc(sizeof(struct Node));
//    root->data = x;
//    root->Lchild = root->Rchild = NULL;
//    Enqueue(&q, root);
//
//    while(!IsEmptyQueue(q))
//    {
//        p = Dequeue(&q);
//
//        printf("Enter Left Child Of %d : ", p->data);
//        scanf("%d", &x);
//        if(x != -1)
//        {
//            t = (struct Node *)malloc(sizeof(struct Node));
//            t->data = x;
//            t->Lchild = t->Rchild = NULL;
//            p->Lchild = t;
//            Enqueue(&q, t);
//        }
//
//        printf("Enter Right Child Of %d : ", p->data);
//        scanf("%d", &x);
//        if(x != -1)
//        {
//            t = (struct Node *)malloc(sizeof(struct Node));
//            t->data = x;
//            t->Lchild = t->Rchild = NULL;
//            p->Rchild = t;
//            Enqueue(&q, t);
//        }
//    }
//}
//
//void PreOrder(struct Node *p)
//{
//    if(p)
//    {
//        printf("%d ", p->data);
//        PreOrder(p->Lchild);
//        PreOrder(p->Rchild);
//    }
//}
//
//void InOrder(struct Node *p)
//{
//    if(p)
//    {
//        InOrder(p->Lchild);
//        printf("%d ", p->data);
//        InOrder(p->Rchild);
//    }
//}
//
//void PostOrder(struct Node *p)
//{
//    if(p)
//    {
//        PostOrder(p->Lchild);
//        PostOrder(p->Rchild);
//        printf("%d ", p->data);
//    }
//}
//
//void LevelOrder(struct Node* root)
//{
//    struct Queue q;
//    CreateQueue(&q, 100);
//
//    printf("%d ", root->data);
//    Enqueue(&q, root);
//
//    while(!IsEmptyQueue(q))
//    {
//        root = Dequeue(&q);
//
//        if (root->Lchild)
//        {
//            printf("%d ", root->Lchild->data);
//            Enqueue(&q, root->Lchild);
//        }
//        if (root->Rchild)
//        {
//            printf("%d ", root->Rchild->data);
//            Enqueue(&q, root->Rchild);
//        }
//    }
//}
//
//int Count(struct Node* root)
//{
//    if(root)
//        return Count(root->Lchild) + Count(root->Rchild) + 1;
//    return 0;
//}
//
//int Height(struct Node* root)
//{
//    int x = 0, y = 0;
//    if (root == 0)
//        return 0;
//
//    x = Height(root->Lchild);
//    y = Height(root->Rchild);
//
//    if(x > y)
//        return x + 1;
//    else
//        return y + 1;
//}
//
//void IPreOrder(struct Node *p)
//{
//    struct Stack stk;
//    CreateStack(&stk, 100);
//    while(p || !IsEmptyStack(stk))
//    {
//        if(p)
//        {
//            printf("%d ", p->data);
//            Push(&stk, p);
//            p = p->Lchild;
//        }
//        else
//        {
//            p = Pop(&stk);
//            p = p->Rchild;
//        }
//    }
//}
//
//void IInOrder(struct Node *p)
//{
//    struct Stack stk;
//    CreateStack(&stk, 100);
//    while(p || !IsEmptyStack(stk))
//    {
//        if(p)
//        {
//            Push(&stk, p);
//            p = p->Lchild;
//        }
//        else
//        {
//            p = Pop(&stk);
//            printf("%d ", p->data);
//            p = p->Rchild;
//        }
//    }
//}
//
//// ------------------------------------------------------------
//
//int main()
//{
//    CreateTree();
//
//    printf("\n\n");
//    printf("This Is PreOrder Representation Of Tree :  ");
//    PreOrder(root);
//    printf("\n\n");
//
//    printf("This Is InOrder Representation Of Tree :  ");
//    InOrder(root);
//    printf("\n\n");
//
//    printf("This Is PostOrder Representation Of Tree :  ");
//    PostOrder(root);
//    printf("\n\n");
//
//    printf("Level Order Of This Tree :  ");
//    LevelOrder(root);
//    printf("\n\n");
//
//    printf("Count Of This Tree :  %d \n\n", Count(root));
//
//    printf("Height Of This Tree :  %d \n\n", Height(root));
//
//    printf("\n\n");
//    printf("This Is Iterative PreOrder Representation Of Tree :  ");
//    IPreOrder(root);
//    printf("\n\n");
//
//    printf("This Is Iterative InOrder Representation Of Tree :  ");
//    IInOrder(root);
//    printf("\n\n");
//
//    return 0;
//}
