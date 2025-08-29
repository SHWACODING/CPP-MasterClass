#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define PRIME 7


// Hashing Techniques :
// *********************

int Hash (int key)
{
    return key % SIZE;
}

//// A--> Linear Hashing ?????? :

////// 1 - Chaining ??????

// Creating Linked List ??
struct Node
{
    int data;
    struct Node *next;
};

void LL_Sorted_Insert (struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node* LL_Search (struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
            return p;

        p = p->next;
    }
    return NULL;
};

void HT_Chaining_Insert (struct Node *H[], int key)
{
    int idx = Hash(key);

    LL_Sorted_Insert(&H[idx], key);
}

// *****************************************************************************************

////// 2 - Linear Probing ??????

int Linear_Probing (int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(idx + i) % SIZE] != 0)
        i++;

    return (idx + i) % SIZE;
}

void HT_Linear_Probing_Insert (int H[], int key)
{
    int idx = Hash(key);

    if (H[idx] != 0)
        idx = Linear_Probing (H, key);

    H[idx] = key;
}

int HT_Linear_Probing_Search (int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(idx + i) % SIZE] != key)
        i++;

    return key;
}

// *****************************************************************************************

////// 3 - Quadratic Probing ??????

int Quadratic_Probing (int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(idx + (i * i)) % SIZE] != 0)
        i++;

    return (idx + (i * i)) % SIZE;
}

void HT_Quadratic_Probing_Insert (int H[], int key)
{
    int idx = Hash(key);

    if (H[idx] != 0)
        idx = Linear_Probing (H, key);

    H[idx] = key;
}

int HT_Quadratic_Probing_Search (int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(idx + (i * i)) % SIZE] != key)
        i++;

    return key;
}

// *****************************************************************************************

//// B--> Double Hashing ??????

int PrimeHash (int key)
{
    return PRIME - (key % PRIME);
}

int DoubleHash (int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0)
        i++;

    return (idx + i * PrimeHash(idx)) % SIZE;
}

void DoubleHashing_Insert (int H[], int key)
{
    int idx = Hash(key);

    if (H[idx] != 0)
        idx = DoubleHash(H, key);

    H[idx] = key;
}

int DoubleHashing_Search (int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key)
    {
        i++;

        if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0)
            return -1;
    }

    return key;
}


// *****************************************************************************************

int main ()
{
//  Chaining

    struct Node *HT_Chaining[10];
    struct Node *temp_Chaining;

    for (int i = 0; i < 10; i++)
        HT_Chaining[i] = NULL;

    HT_Chaining_Insert(HT_Chaining, 12);
    HT_Chaining_Insert(HT_Chaining, 22);
    HT_Chaining_Insert(HT_Chaining, 42);
    HT_Chaining_Insert(HT_Chaining, 43);

    printf("\nSuccessful Insertion in Hash Chaining ??\n");

    int k;
    printf("Enter Element To Search For in HT_Chaining : ");
    scanf("%d", &k);

    temp_Chaining = LL_Search(HT_Chaining[Hash(k)], k);

    if (temp_Chaining->data == k)
    {
        printf("Element %d  is Found Successfully ??\n", temp_Chaining->data);
        printf("Successful Search\n");
    }
    else
    {
        printf("Element Is Not Found ??\n");;
        printf("Unsuccessful Search\n");
    }

// *****************************************************************************************

//  Linear Probing
    int HT_Linear_Probing[10] = {0};

    HT_Linear_Probing_Insert(HT_Linear_Probing, 12);
    HT_Linear_Probing_Insert(HT_Linear_Probing, 25);
    HT_Linear_Probing_Insert(HT_Linear_Probing, 35);
    HT_Linear_Probing_Insert(HT_Linear_Probing, 26);
    HT_Linear_Probing_Insert(HT_Linear_Probing, 46);

    printf("\nSuccessful Insertion in Linear Probing ??\n");

    int m;
    printf("Enter Element To Search For in HT_Linear_Probing : ");
    scanf("%d", &m);

    int LP_Search = HT_Linear_Probing_Search(HT_Linear_Probing, m);

    if (LP_Search == m)
    {
        printf("Element %d  is Found Successfully ??\n", LP_Search);
        printf("Successful Search\n");
    }
    else
    {
        printf("Element: %d  ==> Is Not Found ??\n", LP_Search);
        printf("Unsuccessful Search\n");
    }

// *****************************************************************************************

//  Quadratic Probing ??
    int HT_Quadratic_Probing[10] = {0};

    HT_Quadratic_Probing_Insert(HT_Quadratic_Probing, 17);
    HT_Quadratic_Probing_Insert(HT_Quadratic_Probing, 67);
    HT_Quadratic_Probing_Insert(HT_Quadratic_Probing, 37);
    HT_Quadratic_Probing_Insert(HT_Quadratic_Probing, 82);
    HT_Quadratic_Probing_Insert(HT_Quadratic_Probing, 52);

    printf("\nSuccessful Insertion in Quadratic Hashing ??\n");

    int q;
    printf("Enter Element To Search For in HT_Quadratic_Probing : ");
    scanf("%d", &q);

    int QP_Search = HT_Quadratic_Probing_Search(HT_Quadratic_Probing, q);

    if (QP_Search == q)
    {
        printf("Element %d  is Found Successfully ??\n", QP_Search);
        printf("Successful Search\n");
    }
    else
    {
        printf("Element: %d  ==> Is Not Found ??\n", QP_Search);
        printf("Unsuccessful Search\n");
    }

// *****************************************************************************************

//  Double Hashing ??
    int HT_DoubleHashing[10] = {0};

    DoubleHashing_Insert(HT_DoubleHashing, 5);
    DoubleHashing_Insert(HT_DoubleHashing, 25);
    DoubleHashing_Insert(HT_DoubleHashing, 15);
    DoubleHashing_Insert(HT_DoubleHashing, 35);
    DoubleHashing_Insert(HT_DoubleHashing, 95);

    printf("\nSuccessful Double Hashing Insertion ??\n");

    int DH_key;
    printf("Enter The Key To Search For in Double Hashing : ");
    scanf("%d", &DH_key);

    int DH_Search = DoubleHashing_Search(HT_DoubleHashing, DH_key);

    if (DH_Search == DH_key)
    {
        printf("Element: %d  ==> Is Found Successfully ??\n", DH_Search);
        printf("Successful Search\n");
    }
    else
    {
        printf("Element: %d  ==> Is Not Found ??\n", DH_Search);
        printf("Unsuccessful Search\n");
    }


// *****************************************************************************************

    return 0;
}
