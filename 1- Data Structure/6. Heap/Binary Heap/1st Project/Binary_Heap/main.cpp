#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lecture Based ??
void InsertInplace (int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : (i/2)]) // Make it Go To Parent ?
    {
        A[i] = A[i % 2 == 0 ? (i/2)-1 : (i/2)];
        i = i % 2 == 0 ? (i/2)-1 : (i/2);
    }
    A[i] = temp;
}

void CreateHeapInplace (int A[], int n)
{
    for (int i = 0; i < n; ++i)
        InsertInplace(A, i);
}

// STL Vector Based ??
void InsertSTLVecBased (vector<int>&vec, int key)
{
    // Insert Key At The End ?
    auto i = vec.size();
    vec.emplace_back(key);

    // ReArrange Elements : Indices are not DRY
    while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : (i / 2)])
    {
        vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : (i / 2)];
        i = i % 2 == 0 ? (i / 2) - 1 : (i / 2);
    }
    vec[i] = key;
}

void CreateHeapSTLVecBased(vector<int>& vec, int A[], int n)
{
    // O(n * Log(n))
    for (int i = 0; i < n; ++i)
        InsertSTLVecBased(vec, A[i]);
}

template <class T>
void PrintHeap (T& vec, int n, string s)
{
    cout << s << " : [" << flush;

    for (int i = 0; i < n; ++i)
    {
        cout << vec[i] << flush;
        if (i < n-1)
            cout << ", " << flush;
    }
    cout << "]" << endl;
}

int DeleteHeap (int A[], int n)
{
    int i, j, x, temp, val;

    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;

    while (j <= n - 1)
    {
        if (j < n-1 && A[j + 1] > A[j])
            j++;

        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

void Swap (int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Heapify (int A[], int n)
{
    // # of Leaf Elements: (n+1)/2, index of Last Leaf Element's Parent: (n/2)-1
    for (int i = (n/ 2) - 1; i >= 0; --i)
    {
        int j = 2 * i + 1; // Left Child For Current i

        while (j < n-1)
        {
            // Compare Left And Right Children of current i
            if (A[j] < A[j + 1])
                j = j + 1;

            // Compare Parent and Largest Child
            if (A[i] < A[j])
            {
                Swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    cout << "Create Heap : " << endl;

    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};

    //Create Heap ??
    CreateHeapInplace(a, sizeof(a) / sizeof(a[0]));

    // Print Heap Values ??
    PrintHeap (a, sizeof(a)/ sizeof(a[0]), "A");

    // Heapify Method ??
    Heapify(a, sizeof(a) / sizeof(a[0]));

    // Print Heapify Values ??
    PrintHeap (a, sizeof(a)/ sizeof(a[0]), "Heapified A");

    cout << endl;

    // Delete Heap ??
    for (int i = 10; i > 1; --i)
        cout << DeleteHeap(a, i) << endl;
    cout << endl;


    // Heap Sort
    for (int i = 1; i <= 10; ++i)
        cout << a[i] << " ";
    cout << endl;

    // STL Based ??
    vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};

    CreateHeapSTLVecBased(v, a, sizeof(a) / sizeof(a[0]));

    PrintHeap (v, v.size(), "V");

    return 0;
}
