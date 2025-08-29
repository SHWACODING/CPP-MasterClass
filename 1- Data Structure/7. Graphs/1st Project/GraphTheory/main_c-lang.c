//#include <stdio.h>
//#include <stdlib.h>
//
//// Queue ??
//struct Node
//{
//    int data;
//    struct Node *next;
//}*front=NULL, *rear=NULL;
//
//void Enqueue (int x)
//{
//    struct Node *t;
//    t = (struct Node*)malloc(sizeof(struct Node));
//
//    if (t == NULL)
//        printf("Queue Is FULL \n");
//    else
//    {
//        t->data = x;
//        t->next = NULL;
//
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
//int Dequeue ()
//{
//    int x = -1;
//    struct Node* t;
//
//    if (front == NULL)
//        printf("Queue Is Empty \n");
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
//int IsEmpty ()
//{
//    return front == NULL;
//}
//
//// *******************************************************************************
//
//void BFS (int G[][8], int start, int n)
//{
//    int i = start, j;
//    int visited[8] = {0};
//
//    printf("%d ", i);
//    visited[i] = 1;
//    Enqueue(i);
//
//    while (!IsEmpty())
//    {
//        i = Dequeue();
//
//        for (j = 1; j < n; ++j)
//            if (G[i][j] == 1 && visited[j] == 0)
//            {
//                printf("%d ", j);
//                visited[j] = 1;
//                Enqueue(j);
//            }
//    }
//}
//
//// *******************************************************************************
//
//void DFS (int G[][8], int start, int n)
//{
//    static int visited[8] = {0};
//    int j;
//
//    if (visited[start] == 0)
//    {
//        printf("%d ", start);
//        visited[start] = 1;
//
//        for (j = 1; j < n; ++j)
//            if (G[start][j] == 1 && visited[j] == 0)
//                DFS(G, j, n);
//    }
//}
//
//// *******************************************************************************
//
//
//int main ()
//{
//    int G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
//                   {0, 0, 1, 1, 1, 0, 0, 0},
//                   {0, 1, 0, 1, 0, 0, 0, 0},
//                   {0, 1, 1, 0, 1, 1, 0, 0},
//                   {0, 1, 0, 1, 0, 1, 0, 0},
//                   {0, 0, 0, 1, 1, 0, 1, 1},
//                   {0, 0, 0, 0, 0, 1, 0, 0},
//                   {0, 0, 0, 0, 0, 1, 0, 0}};
//
//    printf("BFS Traversal For (Vertex : 1) ->  ");
//    BFS(G, 1, 8);
//    printf("\n");
//
//// ****************************************************************************
//
//    printf("DFS Traversal For (Vertex : 4) ->  ");
//    DFS(G, 4, 8);
//    printf("\n");
//
//    return 0;
//}
