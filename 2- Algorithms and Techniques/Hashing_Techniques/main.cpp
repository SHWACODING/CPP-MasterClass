#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;
// Hashing Techniques :
// *********************

int Hash (int key)
{
    return key % SIZE;
}

//// A--> Linear Hashing ?????? :

////// 1 - Chaining ??????

// Linked List Node ??
class Node
{
public:
    int data;
    Node* next;
};

// Hash Table ??
class HashTable
{
public:
    Node** HT;
    HashTable();
    int Hash (int key);
    void HT_Chaining_Insert (int key);
    int HT_Chaining_Search (int key);
    ~HashTable();
};

HashTable::HashTable()
{
    HT = new Node* [SIZE];

    for (int i = 0; i < SIZE; i++)
        HT[i] = nullptr;
}

int HashTable::Hash(int key)
{
    return key % SIZE;
}

void HashTable::HT_Chaining_Insert(int key)
{
    int hIdx = Hash(key);

    Node* t = new Node;
    t->data = key;
    t->next = nullptr;

    // Case : No Nodes in the Linked List ??
    if (HT[hIdx] == nullptr)
        HT[hIdx] = t;
    else
    {
        Node* p = HT[hIdx];
        Node* q = HT[hIdx];

        // Traverse To Find Insert Position ?
        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }

        // Case : Insert Position is The First ??
        if (q == HT[hIdx])
        {
            t->next = HT[hIdx];
            HT[hIdx] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable::HT_Chaining_Search (int key)
{
    int hIdx = Hash(key);

    Node* p = HT[hIdx];

    while (p)
    {
        if (p->data == key)
            return p->data;
        p = p->next;
    }
    return -1;
}

HashTable::~HashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        Node* p = HT[i];
        while (HT[i])
        {
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }

    delete []HT;
}

// *****************************************************************************************

////// 2 - Linear Probing ??????

int Linear_Probing(int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(idx + i) % SIZE]  != 0)
        i++;

    return (idx + i) % SIZE;
}

void HT_Linear_Probing_Insert(int H[], int key)
{
    int idx = Hash (key);

    if (H[idx]  != 0)
        idx = Linear_Probing(H, key);

    H[idx] = key;
}

int HT_Linear_Probing_Search (int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(idx + i) % SIZE]  != key)
    {
        i++;

        if (H[(idx + i) % SIZE] == 0)
            return -1;
    }


    return key;
}

// *****************************************************************************************

////// 3 - Quadratic Probing ??????

int Quadratic_Probing(int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(idx + (i * i)) % SIZE]  != 0)
        i++;

    return (idx + (i * i)) % SIZE;
}

void HT_Quadratic_Probing_Insert(int H[], int key)
{
    int idx = Hash (key);

    if (H[idx]  != 0)
        idx = Linear_Probing(H, key);

    H[idx] = key;
}

int HT_Quadratic_Probing_Search (int H[], int key)
{
    int idx = Hash(key);

    int i = 0;
    while (H[(idx + (i * i)) % SIZE]  != key)
    {
        i++;

        if (H[(idx + (i * i)) % SIZE] == 0)
            return -1;
    }


    return key;
}

// *****************************************************************************************

//// 4 - Double Hashing ??????

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


//int main()
//{
////  Chaining ??
//    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
//
//    int n = sizeof(A) / sizeof(A[0]);
//
//    HashTable H;
//
//    for (int i = 0; i < n; i++)
//        H.HT_Chaining_Insert(A[i]);
//
//    cout << "Successful Chaining Insertion ??" << endl << endl;
//
//    int key;
//    cout << "Enter The Key To Search For in Chaining : ";
//    cin >> key;
//
//    int value = H.HT_Chaining_Search(key);
//
//    if (key == value)
//    {
//        cout << "Key: " << key << ", Value: " << value << endl;
//        cout << "Successful Search" << endl;
//    }
//    else
//    {
//        cout << "Key: " << key << ", Value: " << value << endl;
//        cout << "Unsuccessful Search" << endl;
//    }
//// *****************************************************************************************
//
////  Linear Probing ??
//    int LP[] = {26, 30, 45, 23, 66};
//
//    int x = sizeof(LP) / sizeof(LP[0]);
//
//    int LP_HT[10] = {0};
//
//    for (int i = 0; i < x; i++)
//        HT_Linear_Probing_Insert(LP_HT, LP[i]);
//
//    cout << "\n\nSuccessful Linear Probing Insertion ??" << endl << endl;
//
//    int LP_key;
//    cout << "Enter The Key To Search For in Linear Probing : ";
//    cin >> LP_key;
//
//    int LP_Search = HT_Linear_Probing_Search(LP_HT, LP_key);
//
//    if (LP_key == LP_Search)
//    {
//        cout << "Key: " << LP_Search << " ==> Is Found Successfully ??" << endl;
//        cout << "Successful Search" << endl;
//    }
//    else
//    {
//        cout << "Key: " << LP_Search << " ==> Is Not Found ??" << endl;
//        cout << "Unsuccessful Search" << endl;
//    }
//
//// *****************************************************************************************
//
////  Quadratic Probing ??
//    int QP[] = {33, 36, 43, 46, 77};
//
//    int z = sizeof(QP) / sizeof(QP[0]);
//
//    int QP_HT[10] = {0};
//
//    for (int i = 0; i < z; i++)
//        HT_Quadratic_Probing_Insert(QP_HT, QP[i]);
//
//    cout << "\n\nSuccessful Quadratic Probing Insertion ??" << endl << endl;
//
//    int QP_key;
//    cout << "Enter The Key To Search For in Quadratic Probing : ";
//    cin >> QP_key;
//
//    int QP_Search = HT_Quadratic_Probing_Search(QP_HT, QP_key);
//
//    if (QP_key == QP_Search)
//    {
//        cout << "Key: " << QP_Search << " ==> Is Found Successfully ??" << endl;
//        cout << "Successful Search" << endl;
//    }
//    else
//    {
//        cout << "Key: " << QP_Search << " ==> Is Not Found ??" << endl;
//        cout << "Unsuccessful Search" << endl;
//    }
//
//// *****************************************************************************************
////  Double Hashing ??
//    int DH[] = {5, 25, 15, 35, 95};
//
//    int d = sizeof(DH) / sizeof(DH[0]);
//
//    int DH_HT[10] = {0};
//
//    for (int i = 0; i < d; i++)
//        DoubleHashing_Insert(DH_HT, DH[i]);
//
//    cout << "\n\nSuccessful Double Hashing Insertion ??" << endl << endl;
//
//    int DH_key;
//    cout << "Enter The Key To Search For in Double Hashing : ";
//    cin >> DH_key;
//
//    int DH_Search = DoubleHashing_Search(DH_HT, DH_key);
//
//    if (DH_key == DH_Search)
//    {
//        cout << "Element: " << DH_Search << " ==> Is Found Successfully ??" << endl;
//        cout << "Successful Search" << endl;
//    }
//    else
//    {
//        cout << "Element: " << DH_Search << " ==> Is Not Found ??" << endl;
//        cout << "Unsuccessful Search" << endl;
//    }
//
//// *****************************************************************************************
//
//
//    return 0;
//}
