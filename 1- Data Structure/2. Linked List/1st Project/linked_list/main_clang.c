//#include <stdio.h>
//#include <stdlib.h>
//
////struct Node
////{
////    int data;
////    struct Node *next;
////}*first=NULL, *second=NULL, *third=NULL;
//
////// _____________________________________________________________________________________________________
////
////// Create A Linked List ??
////void Create (int A[], int n)
////{
////    int i;
////    struct Node *temp, *last;
////    first = (struct Node *)malloc(sizeof(struct Node));
////    first->data = A[0];
////    first->next = NULL;
////    last = first;
////
////    for (i = 1; i < n; ++i)
////    {
////        temp = (struct Node *)malloc(sizeof(struct Node));
////        temp->data = A[i];
////        temp->next = NULL;
////        last->next = temp;
////        last = temp;
////    }
////}
////
////// ---------------------------------
////
////// Create The Second dLinked List To Be TO Be Used In Concatenating And Merging ??
////
////void CreateUsedInConcatenationAndMerging (int A[], int n)
////{
////    int i;
////    struct Node *temp, *last;
////    second = (struct Node *)malloc(sizeof(struct Node));
////    second->data = A[0];
////    second->next = NULL;
////    last = second;
////
////    for (i = 1; i < n; ++i)
////    {
////        temp = (struct Node *)malloc(sizeof(struct Node));
////        temp->data = A[i];
////        temp->next = NULL;
////        last->next = temp;
////        last = temp;
////    }
////}
////
////// _____________________________________________________________________________________________________
////
////// Display The Linked List ??
////void Display (struct Node *p)
////{
////    while (p != NULL) // == if (p)
////    {
////        printf("%d ", p->data);
////        p = p->next;
////    }
////    printf("\n");
////}
////
////// _____________________________________________________________________________________________________
////
////// Display The Linked List Recursively ??
////void Display_Rec (struct Node *p)
////{
////    if (p != NULL) // == if (p)
////    {
////        printf("%d ", p->data);
////        Display_Rec(p->next);
////    }
////    printf("\n");
////}
////
////// _____________________________________________________________________________________________________
////
////// Display The Linked List Recursively And Reversed ??
////void Display_Recersively_Reversed (struct Node *p)
////{
////    if (p != NULL) // == if (p)
////    {
////        Display_Recersively_Reversed(p->next);
////        printf("%d ", p->data);
////    }
////    printf("\n");
////}
////
////// _____________________________________________________________________________________________________
////
////// Counting # Of Nodes In The Linked List ??
////int Count (struct Node *p)
////{
////    int c = 0;
////    while (p != NULL) // == while (p)
////    {
////        c++;
////        p = p->next;
////    }
////    return c;
////}
////
////// _____________________________________________________________________________________________________
////
////// Counting # Of Nodes In The Linked List Recursively ??
////int Count_Rec (struct Node *p)
////{
////    if (p != NULL) // == if (p)
////        return Count_Rec(p->next) + 1;
////    else
////        return 0;
////}
////
////// _____________________________________________________________________________________________________
////
////// Finding The Summation Of All Elements In The Linked List ??
////int Sum_Of_All_Elements (struct Node *p)
////{
////    int sum = 0;
////
////    while (p)
////    {
////        sum += p->data;
////        p = p->next;
////    }
////    return sum;
////}
////
////// _____________________________________________________________________________________________________
////
////// Finding The Summation Of All Elements In The Linked List Recursively ??
////int Sum_Of_All_Elements_Rec (struct Node *p)
////{
////    if (p)
////        return Sum_Of_All_Elements_Rec(p->next) + p->data;
////    else
////        return 0;
////}
////
////// _____________________________________________________________________________________________________
////
////// Finding The Maximum Element In The Linked List ??
////int Max_Element (struct Node *p)
////{
////    int mx = -999999;
////
////    while (p)
////    {
////        if (p->data > mx)
////            mx = p->data;
////        p = p->next;
////    }
////    return mx;
////}
////
////// _____________________________________________________________________________________________________
////
////// Finding The Maximum Element In The Linked List Recuersively ??
////int Max_Element_Rec (struct Node *p)
////{
////    int mx = 0;
////
////    if (p == 0)
////        return -1;
////
////    mx = Max_Element_Rec(p->next);
////
////    return mx > p->data ? mx : p->data;
////}
////
////// _____________________________________________________________________________________________________
////
////// Searching For Element In Linked List ??
////struct Node * Search (struct Node *p, int key)
////{
////    while (p != NULL)
////    {
////        if (key == p->data)
////            return p;
////        p = p->next;
////    }
////    return NULL;
////}
////
////// _____________________________________________________________________________________________________
////
////// Searching For Element In Linked List Recursively ??
////struct Node * Search_Rec (struct Node *p, int key)
////{
////    if (!p)
////        return 0;
////    if (key == p->data)
////        return p;
////    return Search_Rec(p->next, key);
////}
////
////// _____________________________________________________________________________________________________
////
////// Improve Searching In The Linked List (Head Method == Move To Head or Front) ??
////struct Node * Search_Head (struct Node *p, int key)
////{
////    struct Node *q;
////    while (p)
////    {
////        if (key == p->data)
////        {
////            q->next = p->next;
////            p->next = first;
////            first = p;
////            return p;
////        }
////        q = p;
////        p = p->next;
////    }
////    return NULL;
////}
////
////// _____________________________________________________________________________________________________
////
////// Inserting Into The Linked List ??
////void Insert (struct Node *p, int pos, int x)
////{
////    struct Node *t;
////
////    if (pos < 0 || pos > Count(p))
////        return;
////
////    t = (struct Node *)malloc(sizeof(struct Node));
////    t->data = x;
////
//////    Inserting Into Start ??
////    if (pos == 0)
////    {
////        t->next = first;
////        first = t;
////    }
////
//////    Inserting Into Specific Position Not Equal First Position ??
////    else
////    {
////        for (int i = 0; i < pos - 1 && p; ++i)
////            p = p->next;
////
////        t->next = p->next;
////        p->next = t;
////    }
////}
////
////// _____________________________________________________________________________________________________
////
////// Inserting Into A New Node Into Q Sorted A Sorted List ??
////
////void InsertIntoSortedList (struct Node *p, int x)
////{
////    struct Node *t, *q = NULL;
////
////    t = (struct Node *)malloc(sizeof(struct Node));
////    t->data = x;
////    t->next = NULL;
////
////    if (first == NULL)
////        first = t;
////    else
////    {
////        while (p && p->data < x)
////        {
////            q = p;
////            p = p->next;
////        }
////        if (p == first)
////        {
////            t->next = first;
////            first = t;
////        }
////        else
////        {
////            t->next = q->next;
////            q->next = t;
////        }
////    }
////}
////
////// _____________________________________________________________________________________________________
////
////// Deleting The First Node From Linked List ??
////
////int Delete (struct Node *p, int idx)
////{
////    struct Node *q;
////    int x = -1;
////
////    if (idx < 1 || idx > Count(p))
////        return -1;
////
////    if (idx == 1)
////    {
////        q = first;
////        x = first->data;
////        first = first->next;
////        free(q);
////        return x;
////    }
////    else
////    {
////        for (int i = 0; i < idx - 1; ++i)
////        {
////            q = p;
////            p = p->next;
////        }
////        q->next = p->next;
////        x = p->data;
////        free(p);
////        return x;
////    }
////
////}
////
////// _____________________________________________________________________________________________________
////
////// Check If The LL Is Sorted Or Not ???
////
////int isSorted (struct Node *p)
////{
////    int x = -65536; // Smallest 4-bytes Int ??
////
////    while(p) // while(p != NULL)
////    {
////        if (p->data < x)
////            return 0;
////        x = p->data;
////        p = p->next;
////    }
////    return 1;
////}
////
////// _____________________________________________________________________________________________________
////
////// Remove Duplicates From A Sorted LL ??
////
////void RemoveDuplictes(struct Node *p)
////{
////    struct Node *q = p->next;
////
////    while(q)
////    {
////        if (p->data != q->data)
////        {
////            p = q;
////            q = q->next;
////        }
////        else
////        {
////            p->next = q->next;
////            free(q);
////            q = p->next;
////        }
////    }
////}
////
////// _____________________________________________________________________________________________________
////
////// Reversing a Linked List ??
//////// 1- Reversing Elements ??
////
////void ReversingElements(struct Node *p)
////{
////    int *A, i = 0;
////
////    struct Node *q = p;
////
////    A = (int *)malloc(sizeof(int)*Count(p));
////
////    while (q)
////    {
////        A[i] = q->data;
////        q = q->next;
////        i++;
////    }
////
////    q = p;
////    i--;
////
////    while(q)
////    {
////        q->data = A[i];
////        q = q->next;
////        i--;
////    }
////}
////
//////// 2- Reversing Using Sliding Pointers ?? (Reversing The Nodes Itself ??)
////
////void Reversing_Using_Sliding_Pointers (struct Node *p)
////{
////    struct Node *q = NULL, *r = NULL;
////
////    while (p)
////    {
////        r = q;
////        q = p;
////        p = p->next;
////        q->next = r;
////    }
////    first = q;
////}
////
//////// 3- Recursive Reversing ??
////
////void Recursive_Reversing (struct Node *q, struct Node *p)
////{
////    if (p)
////    {
////        Recursive_Reversing(p, p->next);
////        p->next = q;
////    }
////    else
////        first = q;
////}
////
////// _____________________________________________________________________________________________________
////
////// Concatenating Two Linked Lists ??
////
////void Concat (struct Node *p, struct Node *q)
////{
////    third = p;
////
////    while (p->next != NULL)
////        p = p->next;
////    p->next = q;
////}
////
////// _____________________________________________________________________________________________________
////
////// Merging Two Linked Lists ??
////
////void Merge (struct Node *p, struct Node *q)
////{
////    struct Node *last;
////
////    if (p->data < q->data)
////    {
////        third = last = p;
////        p = p->next;
////        third->next = NULL;
////    }
////    else
////    {
////        third = last = q;
////        q = q->next;
////        third->next = NULL;
////    }
////
////    while (p && q)
////    {
////        if (p->data < q->data)
////        {
////            last->next = p;
////            last = p;
////            p = p->next;
////            last->next = NULL;
////        }
////        else
////        {
////            last->next = q;
////            last = q;
////            q = q->next;
////            last->next = NULL;
////        }
////    }
////
////    if (p) last->next = p;
////    if (q) last->next = q;
////
////}
////
////// _____________________________________________________________________________________________________
////
////// Check For LOOP In Linked List ??
////
////int IsLOOP (struct Node *f)
////{
////    struct Node *p, *q;
////
////    p = q = f;
////
////    do
////    {
////        p = p->next;
////        q = q->next;
////        q = q ? q->next : NULL;
////    } while (p && q && p != q);
////
////    return p == q ? 1 : 0;
////}
//
//// _____________________________________________________________________________________________________
//
////int MiddleElement (struct Node *p)
////{
////    struct Node *q;
////    p = q = first;
////    int x;
////
////    while (q)
////    {
////        q = q->next;
////        if (q) q = q->next;
////        if (q) p = p->next;
////        x = p->data;
////    }
////    return x;
////}
//
//// _____________________________________________________________________________________________________
//
//// _______________________________________________________________________________________________________
//// _______________________________________________________________________________________________________
//
////// Circular Linked List ????
////
////struct CircularLLNode
////{
////    int data;
////    struct CircularLLNode *next;
////}*Head=NULL;
////
////
////void CreateCircularLL (int A[], int n)
////{
////    int i;
////    struct CircularLLNode *temp, *last;
////    Head = (struct CircularLLNode *)malloc(sizeof(struct CircularLLNode));
////    Head->data = A[0];
////    Head->next = Head;
////    last = Head;
////
////    for (i = 1; i < n; ++i)
////    {
////        temp = (struct CircularLLNode *)malloc(sizeof(struct CircularLLNode));
////        temp->data = A[i];
////        temp->next = last->next;
////        last->next = temp;
////        last = temp;
////    }
////}
////
////// -----------------------------------------------------------
////
////void DisplayCircularLL (struct CircularLLNode *h)
////{
////    do
////    {
////        printf("%d ", h->data);
////        h = h->next;
////    }
////    while (h != Head);
////
////    printf("\n");
////}
////
////// -----------------------------------------------------------
////
////void RecursiveDisplayCircularLL (struct CircularLLNode *h)
////{
////    static int flag = 0;
////    if (h != Head || flag == 0)
////    {
////        flag = 1;
////        printf("%d ", h->data);
////        RecursiveDisplayCircularLL(h->next);
////    }
////    flag = 0;
////}
////
////// -----------------------------------------------------------
////
////int LengthOfCircularLL(struct CircularLLNode *p)
////{
////    int len = 0;
////
////    do
////    {
////        len++;
////        p = p->next;
////    } while (p != Head);
////
////    return len;
////}
////
////// -----------------------------------------------------------
////
////void InsertIntoCircularLL (struct CircularLLNode *p, int index, int x)
////{
////    struct CircularLLNode *t;
////    int i;
////
////    if (index < 0 || index > LengthOfCircularLL(Head))
////        return;
////
////    if (index == 0)
////    {
////        t = (struct CircularLLNode *)malloc(sizeof(struct CircularLLNode));
////        t->data = x;
////        if (Head == NULL)
////        {
////            Head = t;
////            Head->next = Head;
////        }
////        else
////        {
////            while (p->next != Head) p = p->next;
////            p->next = t;
////            t->next = Head;
////            Head = t;
////        }
////    }
////    else
////    {
////        for (i = 0; i < index - 1; ++i) p = p->next;
////        t = (struct CircularLLNode *)malloc(sizeof(struct CircularLLNode));
////        t->data = x;
////        t->next = p->next;
////        p->next = t;
////    }
////}
////
////// -----------------------------------------------------------
////
////int DeleteFromCircularLL (struct CircularLLNode *p, int index)
////{
////    struct CircularLLNode *q;
////    int x, i;
////
////    if (index < 0 || index > LengthOfCircularLL(Head))
////        return -1;
////
////    if (index == 1)
////    {
////        while (p->next != Head) p = p->next;
////        x = Head->data;
////        if (Head == p)
////        {
////            free(Head);
////            Head = NULL;
////        }
////        else
////        {
////            p->next = Head->next;
////            free(Head);
////            Head = p->next;
////        }
////    }
////    else
////    {
////        for (i = 0; i <index - 2; ++i)
////            p = p->next;
////        q = p->next;
////        p->next = q->next;
////        x = q->data;
////        free(q);
////    }
////    return x;
////}
////
////// _____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
////// _____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
////
////// Doubly Linked List ????
////
////struct DoublyLLNode
////{
////    struct DoublyLLNode *prev;
////    int data;
////    struct DoublyLLNode *next;
////}*starter=NULL;
////
////// -----------------------------------------------------------
////
////void CreateDoublyLL (int A[], int n)
////{
////    struct DoublyLLNode *temp, *last;
////    int i;
////
////    starter = (struct DoublyLLNode *)malloc(sizeof(struct DoublyLLNode));
////    starter->data = A[0];
////    starter->prev = starter->next = NULL;
////    last = starter;
////
////    for (i = 1; i < n; ++i)
////    {
////        temp = (struct DoublyLLNode *)malloc(sizeof(struct DoublyLLNode));
////        temp->data = A[i];
////        temp->next = last->next;
////        temp->prev = last;
////        last->next = temp;
////        last = temp;
////    }
////
////}
////
////// -----------------------------------------------------------
////
////void DisplayDoublyLL (struct DoublyLLNode *p)
////{
////    while (p)
////    {
////        printf("%d ", p->data);
////        p = p->next;
////    }
////    printf("\n");
////}
////
////// -----------------------------------------------------------
////
////int LengthOfDoublyLL (struct DoublyLLNode *p)
////{
////    int len = 0;
////    while (p)
////    {
////        len++;
////        p = p->next;
////    }
////    return len;
////}
////
////// -----------------------------------------------------------
////
////void InsertIntoDoublyLL (struct DoublyLLNode *p, int index, int x)
////{
////    struct DoublyLLNode *t;
////    int i;
////
////    if (index < 0 || index > LengthOfDoublyLL(p))
////        return;
////
////    if (index == 0)
////    {
////        t = (struct DoublyLLNode *)malloc(sizeof(struct DoublyLLNode));
////        t->data = x;
////        t->prev = NULL;
////        t->next = starter;
////        starter->prev = t;
////        starter = t;
////    }
////    else
////    {
////        for (i = 0; i < index-1; ++i)
////            p = p->next;
////
////        t = (struct DoublyLLNode *)malloc(sizeof(struct DoublyLLNode));
////        t->data = x;
////
////        t->prev = p;
////        t->next = p->next;
////        if (p->next)
////            p->next->prev = t;
////        p->next = t;
////    }
////
////}
////
////// -----------------------------------------------------------
////
////int DeleteFromDoublyLL (struct DoublyLLNode *p, int index)
////{
////    int x = -1, i;
////
////    if (index < 1 || index > LengthOfDoublyLL(p))
////        return -1;
////
////    if (index == 1)
////    {
////        starter = starter->next;
////        if (starter) starter->prev = NULL;
////        x = p->data;
////        free(p);
////    }
////    else
////    {
////        for (i = 0; i < index-1; ++i)
////            p = p->next;
////
////        p->prev->next = p->next;
////        if (p->next)
////            p->next->prev = p->prev;
////        x = p->data;
////        free(p);
////    }
////    return x;
////
////}
////
////// -----------------------------------------------------------
////
////void ReverseDoublyLL (struct DoublyLLNode *p)
////{
////    struct DoublyLLNode *temp;
////
////    while (p != NULL)
////    {
////        temp = (struct DoublyLLNode *)malloc(sizeof(struct DoublyLLNode));
////        temp = p->next;
////        p->next = p->prev;
////        p->prev = temp;
////        p = p->prev;
////        if (p != NULL && p->next == NULL)
////            starter = p;
////    }
////}
//
//// _____________________________________________________________________________________________________
//
//
//int main ()
//{
////    struct Node *t1, *t2;
//
////    int A[] = {10, 20, 30, 40, 50};
//
////    int B[] = {5, 15, 25, 35, 45};
//
////    Create(A, 5);
////    CreateUsedInConcatenationAndMerging(B, 5);
//
//    ////  Make t2 as LOOP LL ???
////    t1 = first->next->next;
////    t2 = first->next->next->next->next;
////    t2->next = t1;
//
////    Display(first);
////    Display_Rec(first);
////    Display_Recersively_Reversed(first);
////    printf("The Number Of Nodes Is : %d", Count(first));
////    printf("The Number Of Nodes Is : %d", Count_Rec(first));
//
//// _____________________________________________________________________________________________________
//
////    printf("The Summation Of All Elements In LL : %d\n", Sum_Of_All_Elements(first));
////    printf("The Summation Of All Elements In LL Rec : %d\n", Sum_Of_All_Elements_Rec(first));
//
//// _____________________________________________________________________________________________________
//
////    printf("The Maximum Element In The LL : %d \n", Max_Element(first));
////    printf("The Maximum Element In The LL : %d \n", Max_Element_Rec(first));
//
//// _____________________________________________________________________________________________________
//
////    struct Node *temp1, *temp2, *temp3;
////
////    temp1 = Search(first, 32);
////    temp2 = Search_Rec(first, 15);
////    temp3 = Search_Head(first, 28);
////    temp3 = Search_Head(first, 7);
////
////    if (temp1)
////        printf("Key %d Is Found ?\n", temp1->data);
////    else
////        printf("Key Not Found ??\n");
////
////    if (temp2)
////        printf("Key %d Is Found ?\n", temp2->data);
////    else
////        printf("Key Not Found ??\n");
////
////    if (temp3)
////        printf("Key %d Is Found ?\n", temp3->data);
////    else
////        printf("Key Not Found ??\n");
////
////    Display(first);
//
//// _____________________________________________________________________________________________________
//
////    Display(first);
////    Insert(first, 4, 12);
////    Display(first);
//
//// _____________________________________________________________________________________________________
//
////    int x[] = {10, 20, 30, 40, 50};
////    Create(x, 5);
////
////    Display(first);
////    InsertIntoSortedList(first, 35);
////    Display(first);
//
//// _____________________________________________________________________________________________________
//
////    Display(first);
////    printf("Deleted Element Is : %d \n", Delete(first, 4));
////    Display(first);
//
//// _____________________________________________________________________________________________________
//
////    printf("%d\n", isSorted(first));
////    Display(first);
//
////    if (isSorted(first))
////        printf("Sorted\n");
////    else
////        printf("Not Sorted ?\n");
//
//// _____________________________________________________________________________________________________
//
////    int X[] = {3, 3, 5, 7, 7, 7, 10, 15, 15, 24, 28, 32, 32};
////    Create(X, 12);
////
////    RemoveDuplictes(first);
////    Display(first);
//
//// _____________________________________________________________________________________________________
//
////    Display(first);
////    ReversingElements(first);
////    Display(first);
//
////    Display(first);
////    Reversing_Using_Sliding_Pointers(first);
////    Display(first);
//
////    Display(first);
////    Recursive_Reversing(NULL, first);
////    Display(first);
//
//// _____________________________________________________________________________________________________
//
////    printf("First : \n");
////    Display(first);
////    printf("\n\n");
////
////    printf("Second : \n");
////    Display(second);
////    printf("\n\n");
//
//// _____________________________________________________________________________________________________
//
//////    Concat(first, second);
////    Concat(second, first);
////
////    Display(third);
////    printf("\n\n");
//
//
//// _____________________________________________________________________________________________________
//
////    Merge(first, second);
////    Display(third);
//
//// _____________________________________________________________________________________________________
//
////    printf("====> %d\n", IsLOOP(first));
//
////    IsLOOP (first) ? printf("Yes It Is LOOP !!\n") : printf("Yes It Is Not LOOP !!\n");
//
//// _____________________________________________________________________________________________________
//
////    printf("The Middle Of This Linked List : %d\n", MiddleElement(first));
//
//// _____________________________________________________________________________________________________
//
//// _____________________________________________________________________________________________________
//// _____________________________________________________________________________________________________
//
////    // Circular Linked List ????
////
////    int C[] = {2, 3, 4, 5, 6};
////
////    CreateCircularLL(C, 5);
////
//////    RecursiveDisplayCircularLL(Head);
//////    DisplayCircularLL(Head);
////
//////    DisplayCircularLL(Head);
//////
//////    InsertIntoCircularLL(Head, 3, 99);
//////
//////    DisplayCircularLL(Head);
////
////    DisplayCircularLL(Head);
////
////    printf("Deleted Element Is : %d\n", DeleteFromCircularLL(Head, 1));
////
////    DisplayCircularLL(Head);
//
//// _____________________________________________________________________________________________________
//// _____________________________________________________________________________________________________
//
//    // Doubly Linked List ????
//
////    int D[] = {10, 20, 30, 40, 50};
////
////    CreateDoublyLL(D, 5);
//
////    DisplayDoublyLL(starter);
////    printf("Length Of This Doubly LL : %d\n", LengthOfDoublyLL(starter));
//
////    DisplayDoublyLL(starter);
////    InsertIntoDoublyLL(starter, 2, 99);
////    DisplayDoublyLL(starter);
//
////    DisplayDoublyLL(starter);
////    printf("Deleted Element Is : %d\n" ,DeleteFromDoublyLL(starter, 5));
////    DisplayDoublyLL(starter);
//
////    DisplayDoublyLL(starter);
////    ReverseDoublyLL(starter);
////    DisplayDoublyLL(starter);
//
//// _____________________________________________________________________________________________________
//
//// _____________________________________________________________________________________________________
//
//// _____________________________________________________________________________________________________
//
//    return 0;
//}
