#include <iostream>
#include <string>
#include <math.h>

using namespace std;

template <class T>
void Print_List(T& vec, int n, string s)
{
    cout << s << ": [" << flush;

    for (int i = 0; i < n; ++i)
    {
        cout << vec[i] << flush;
        if (i < n-1)
            cout << ", " << flush;
    }

    cout << "]" << endl;
}

void Swapping(int* x, int * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble_Sort(int A[], int n)
{
    int flag = 0;

    for (int i = 0; i < n-1; ++i)
    {
        for (int j = 0; j < n-i-1; ++j)
        {
            if (A[j] > A[j+1])
            {
                Swapping(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

// ************************************************************************

void Insertion_Sort(int A[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        int x = A[i];

        while (j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

// ************************************************************************

void Selection_Sort(int A[], int n)
{
    int i, j, k;

    for (i = 0; i < n-1; ++i)
    {
        for (j = k = i; j < n; ++j)
            if (A[j] < A[k])
                k = j;

        Swapping(&A[i], &A[k]);
    }
}

// ************************************************************************

// Quick Sort == Partition-Exchange Sort == Selection-Exchange Sort

int Partition(int A[], int low, int high)
{
    int povit = A[low];
    int i = low;
    int j = high;

    do
    {
        // Increment i as long as elements are Smaller or Equal To Povit
        do {i++;} while (A[i] <= povit);

        // Decrement j as long as elements are Larger Than Povit
        do {j--;} while (A[j] > povit);

        if (i < j)
        Swapping(&A[i], &A[j]);
    } while (i < j);

    Swapping(&A[low], &A[j]);
    return j;
}

void Quick_Sort (int A[], int low, int high)
{

    if (low < high)
    {
        int j = Partition(A, low, high);
        Quick_Sort(A, low, j);
        Quick_Sort(A, j+1, high);
    }
}

// ************************************************************************

void Merge_Two_Arrays_In_One (int A[], int B[], int C[], int m, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < m && j < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < m)
        C[k++] = A[i++];

    while (j < n)
        C[k++] = B[j++];
}

// ***************************************

void Merge_One_Arrays_In_Another_One (int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= mid)
        B[k++] = A[i++];
    while (j <= high)
        B[k++] = A[j++];

    for (int i = low; i <= high; i++)
        A[i] = B[i];
}

// ***************************************

void Recursive_Merge_Sort (int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        Recursive_Merge_Sort(A, low, mid);
        Recursive_Merge_Sort(A, mid+1, high);

        Merge_One_Arrays_In_Another_One(A, low, mid, high);
    }
}

// ******************

void Iterative_Merge_Sort (int A[], int n)
{
    int p;
    for (p = 2; p <= n; p=p*2)
    {
        for (int i = 0; i+p-1 < n; i=i+p)
        {
            int l = i;
            int h = i + p- 1;
            int mid = (l+h)/2;
            Merge_One_Arrays_In_Another_One(A, l, mid, h);
        }
    }
    if (p / 2 < n)
        Merge_One_Arrays_In_Another_One(A, 0, p/2, n-1);
}

// ************************************************************************

int FindMax (int A[], int n)
{
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (A[i] > mx)
            mx = A[i];
    }
    return mx;
}

void Count_Sort (int A[], int n)
{
    int mx = FindMax(A, n);
    int* C = new int [mx + 1];

    for (int i = 0; i < mx+1; i++)
        C[i] = 0;

    for (int i = 0; i < n; i++)
        C[A[i]]++;

    int i = 0, j = 0;

    while (i < mx+1)
    {
        if (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
            i++;
    }
}


// ************************************************************************

// Linked List Node
class Node
{
public:
    int value;
    Node* next;
};

void Insert (Node** ptrBins, int idx)
{
    Node* temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr) // prtBins[idx] is The Head Prt ??
        ptrBins[idx] = temp;
    else
    {
        Node* p = ptrBins[idx];
        while (p->next != nullptr)
            p = p->next;
        p->next = temp;
    }
}

int Delete (Node** ptrBins, int idx)
{
    Node* p = ptrBins[idx]; // prtBins[idx] is The Head Prt ??

    ptrBins[idx] = ptrBins[idx]->next;

    int x = p->value;

    delete p;

    return x;
}

void Bin_Sort (int A[], int n)
{
    int mx = FindMax(A, n);

    // Create Bins Array ??
    Node** bins = new Node* [mx+1];

    // Initialize bins array With nullptr ??
    for (int i = 0; i < mx+1; i++)
        bins[i] = nullptr;

    // Update Count Array Values Based On A Values ??
    for (int i = 0; i < n; i++)
        Insert(bins, A[i]);

    // Update A With Sorted Elements ??
    int i = 0, j = 0;

    while (i < mx+1)
    {
        while (bins[i] != nullptr)
            A[j++] = Delete(bins, i);
        i++;
    }

    // Delete Heap Memory ??
    delete [] bins;
}


// ************************************************************************

void InsertRadix (Node** ptrBins, int val, int idx)
{
    Node* temp = new Node;
    temp->value = val;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr) // prtBins[idx] is The Head Prt ??
        ptrBins[idx] = temp;
    else
    {
        Node* p = ptrBins[idx];
        while (p->next != nullptr)
            p = p->next;
        p->next = temp;
    }
}

int CountDigits (int x)
{
    int cnt = 0;

    while (x != 0)
    {
        x /= 10;
        cnt++;
    }

    return cnt;
}

void InitializeBins (Node** p, int n)
{
    for (int i = 0; i < n; i++)
        p[i] = nullptr;
}

int GetBinIndex (int x, int idx)
{
    return (int)(x / pow(10, idx)) % 10;
}

void Radix_Sort (int A[], int n)
{
    int mx = FindMax(A, n);
    int nPass = CountDigits(mx);

    // Create Bins Array ??
    Node** bins = new Node* [10];

    // Initialize Bins Array With Nullptr ??
    InitializeBins(bins, 10);

    // Update Bins and A For nPass Times ??
    for (int pass = 0; pass < nPass; pass++)
    {
        // Update Bins Based On A Values ??
        for (int i = 0; i < n; i++)
        {
            int binIdx = GetBinIndex(A[i], pass);
            InsertRadix(bins, A[i], binIdx);
        }

        // Update A With Sorted Elements From Bin ??
        int i = 0, j = 0;

        while (i < 10)
        {
            while (bins[i] != nullptr)
            {
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize Bins With Nullptr Again ??
        InitializeBins(bins, 10);
    }

    // Delete Heap Memory ??
    delete [] bins;
}


// ************************************************************************

void Shell_Sort (int A[], int n)
{
    for (int gap = n/2; gap > 1; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = A[i];

            int j = i - gap;
            while (j > 0 && A[j] > temp)
            {
                A[j+gap] = A[j];
                j -= gap;
            }
            A[j + gap] = temp;
        }
    }
}

// ************************************************************************

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(A[0]);

    Print_List(A, n, "UnSorted List A ==> ");

// ************************************************************************

    Bubble_Sort(A, n);

    Print_List(A, n, "Bubble Sorted A ==> ");

// ************************************************************************

    Insertion_Sort(A, n);
    Print_List(A, n, "Insertion Sorted A ==> ");

// ************************************************************************

    Selection_Sort(A, n);
    Print_List(A, n, "Selection Sorted A ==> ");

// ************************************************************************

    int Q[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT_MAX};
    int m = sizeof(Q)/sizeof(Q[0]);

    Quick_Sort(Q, 0, m-1);
    Print_List(Q, m-1, "Quick Sorted A ==> ");

// ************************************************************************

    Recursive_Merge_Sort(A, 0, n-1);
    Print_List(A, n, "Recursive Merge Sorted A ==> ");

// ************************************************************************

    Iterative_Merge_Sort(A, n);
    Print_List(A, n, "Iterative Merge Sorted A ==> ");

// ************************************************************************

    Count_Sort(A, n);
    Print_List(A, n, "Count Sorted A ==> ");

// ************************************************************************

    Bin_Sort(A, n);
    Print_List(A, n, "Bin Sorted A ==> ");

// ************************************************************************

    int R[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int w = sizeof(R) / sizeof(R[0]);

    Print_List(R, w, "Radix Unsorted List ==> ");
    Radix_Sort(R, w);
    Print_List(R, w, "Radix sorted List ==> ");


// ************************************************************************

    Shell_Sort(A, n);
    Print_List(A, n, "Shell Sorted List ==> ");

    return 0;
}
