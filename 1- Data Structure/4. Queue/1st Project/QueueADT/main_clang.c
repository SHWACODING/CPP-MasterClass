#include <stdio.h>
#include <stdlib.h>

//// Implementation Of Queue Using Array ?
//
//struct Queue
//{
//    int size;
//    int front;
//    int rear;
//    int *Q;
//};
//
//void Create(struct Queue *q, int size)
//{
//    q->size = size;
//    q->front = q->rear = -1;
//    q->Q = (int *)malloc(q->size * sizeof(int));
//}
//
//void Enqueue(struct Queue *q, int x)
//{
//    if (q->rear == q->size-1)
//    {
//        printf("Queue Is Full Now ?");
//    }
//    else
//    {
//        q->rear++;
//        q->Q[q->rear] = x;
//    }
//}
//
//int Dequeue (struct Queue *q)
//{
//    int x = -1;
//
//    if (q->front == q->rear)
//    {
//        printf("Queue Is Empty Now ?");
//    }
//    else
//    {
//        q->front++;
//        x = q->Q[q->front];
//    }
//    return x;
//}
//
//void Display(struct Queue q)
//{
//    for(int i = q.front+1; i <= q.rear; ++i)
//    {
//        printf("%d ", q.Q[i]);
//    }
//    printf("\n");
//}
//
//int main()
//{
//    struct Queue q;
//
//    Create(&q, 5);
//
//    Enqueue(&q, 10);
//    Enqueue(&q, 20);
//    Enqueue(&q, 30);
//    Enqueue(&q, 40);
//
//    Display(q);
//
//    printf("Dequeued Element : %d \n", Dequeue(&q));
//
//    Display(q);
//
//    return 0;
//}

//// Implementation Of Circular Queue Using Array (The Truth One & The Best) ?
//
//struct Queue
//{
//    int size;
//    int front;
//    int rear;
//    int *Q;
//};
//
//void Create(struct Queue *q, int size)
//{
//    q->size = size;
//    q->front = q->rear = 0;
//    q->Q = (int *)malloc(q->size * sizeof(int));
//}
//
//void Enqueue(struct Queue *q, int x)
//{
//    if ((q->rear+1) % q->size == q->front)
//    {
//        printf("Queue Is Full Now ? \n");
//    }
//    else
//    {
//        q->rear = (q->rear + 1) % q->size;
//        q->Q[q->rear] = x;
//    }
//}
//
//int Dequeue (struct Queue *q)
//{
//    int x = -1;
//
//    if (q->front == q->rear)
//    {
//        printf("Queue Is Empty Now ? \n");
//    }
//    else
//    {
//        q->front = (q->front + 1) % q->size;
//        x = q->Q[q->front];
//    }
//    return x;
//}
//
//void Display(struct Queue q)
//{
//    int i = q.front + 1;
//    do
//    {
//        printf("%d ", q.Q[i]);
//        i = (i + 1) % q.size;
//    } while(i != (q.rear + 1) % q.size);
//
//    printf("\n");
//}
//
//int main()
//{
//    struct Queue q;
//
//    Create(&q, 5);
//
//    Enqueue(&q, 10);
//    Enqueue(&q, 20);
//    Enqueue(&q, 30);
//    Enqueue(&q, 40);
//
//    Display(q);
//
//    printf("Dequeued Element : %d \n", Dequeue(&q));
//
//    Display(q);
//
//    return 0;
//}


//// Implementation Of Queue Using Linked Lsit ?
//
//struct Node
//{
//    int data;
//    struct Node *next;
//}*front=NULL, *rear=NULL;
//
//void Enqueue(int x)
//{
//    struct Node *t;
//    t = (struct Node*)malloc(sizeof(struct Node));
//
//    if(t ==NULL)
//        printf("Queue Is Full ? \n");
//
//    else
//    {
//        t->data = x;
//        t->next = NULL;
//
//        // Check If The Inserted Element Is The Only One Found (First) Or Of Any Index ?
//        if (front == NULL)
//            front = rear = t;
//        else
//        {
//            rear->next = t;
//            rear = t;
//        }
//    }
//}
//
//int Dequeue()
//{
//    int x = -1;
//
//    struct Node *t;
//
//    if(front == NULL)
//        printf("Queue Is Empty ? \n");
//    else
//    {
//        x = front->data;
//        t = front;
//        front = front->next;
//        free(t);
//    }
//    return x;
//}
//
//void Display()
//{
//    struct Node *p = front;
//
//    while(p)
//    {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//int main()
//{
//    Enqueue(10);
//    Enqueue(20);
//    Enqueue(30);
//    Enqueue(40);
//    Enqueue(50);
//
//    Display();
//
//    Dequeue();
//
//    Display();
//
//    return 0;
//}
