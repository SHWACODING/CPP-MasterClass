#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void Swapping(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Print_List(int A[], int n, char s[100])
{
    printf("%s ==> : [", s);
    for (int i = 0; i < n; ++i)
    {
        printf("%d", A[i]);
        if (i < n-1)
            printf(", ");
    }
    printf("]\n");
}

void Bubble_Sort(int A[], int n)
{
    int i, j, flag = 0;
    for (i = 0; i < n-1; ++i)
    {
        flag = 0;
        for (j = 0; j < n-i-1; ++j)
        {
            if (A[j] > A[j+1])
            {
                Swapping(&A[j], &A[j+1]);
                flag = 1;
            }
        }
//        if (flag == 1)
//            printf("\n*****Sorted***** %d ***\n", i+1);
//        else
//            break;
        if (flag == 0)
            break;
    }
    printf("\n");
}

// *******************************************************************************

void Insertion_Sort(int A[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        int x = A[i];

        while(j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

// *******************************************************************************

void Selection_Sort(int A[], int n)
{
    int i, j, k;

    for (i = 0; i < n-1; i++)
    {
        for (j = k = i; j < n; j++)
            if (A[j] < A[k])
                k = j;

        Swapping(&A[i], &A[k]);
    }
}

// *******************************************************************************

// Quick Sort == Partition-Exchange Sort == Selection-Exchange Sort

int Partition (int A[], int l, int h)
{
    int povit = A[l];
    int i = l, j = h;

    do
    {
        // Increment i as long as elements are Smaller or Equal To Povit
        do {i++;} while (A[i] <= povit);

        // Decrement j as long as elements are Larger Than Povit
        do {j--;} while (A[j] > povit);

        if (i < j)
        Swapping(&A[i], &A[j]);
    } while (i < j);

    Swapping(&A[l], &A[j]);
    return j;
}

void Quick_Sort (int A[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = Partition(A, l, h);
        Quick_Sort(A, l, j);
        Quick_Sort(A, j+1, h);
    }
}

// *******************************************************************************

void Merge_Two_Arrays_In_One (int A[], int B[], int m, int n)
{
    int i, j, k, C[m + n];
    i = j = k = 0;

    while (i < m && j < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    for (; i < m; i++)
        C[k++] = A[i];
    for (; j < n; j++)
        C[k++] = B[j];
}

// ***************************************

void Merge_One_Arrays_In_Another_One (int A[], int low, int mid, int high)
{
    int i, j, k, B[high + 1];

    i = low; j = mid + 1; k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= high; j++)
        B[k++] = A[j];

    for (i = low; i <= high; i++)
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

// *************************

void Iterative_Merge_Sort (int A[], int n)
{
    int i, p, l, mid, h;

    for (p = 2; p <= n; p=p*2)
    {
        for (i = 0; i+p-1 < n; i=i+p)
        {
            l = i;
            h = i + p- 1;
            mid = (l+h)/2;
            Merge_One_Arrays_In_Another_One(A, l, mid, h);
        }
    }
    if (p / 2 < n)
        Merge_One_Arrays_In_Another_One(A, 0, p/2, n-1);
}

// *******************************************************************************

int FindMax (int A[], int n)
{
    int max = INT_MIN;

    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void Count_Sort (int A[], int n)
{
    int max = FindMax(A, n);
    int *C = (int *)malloc(sizeof(int) * (max + 1));

    for (int i = 0; i < max+1; i++)
        C[i] = 0;

    for (int i = 0; i < n; i++)
        C[A[i]]++;

    int i = 0, j = 0;

    while (i < max+1)
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

// *******************************************************************************



// *******************************************************************************



// *******************************************************************************



// *******************************************************************************


//int main ()
//{
//    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
//    int n = 10;
//
//// *******************************************************************************
//
//    Bubble_Sort(A, n);
//    Print_List(A, n, "Bubble Sort List");
//
//// *******************************************************************************
//
//    Insertion_Sort(A, n);
//    Print_List(A, n, "Insertion Sort List");
//
//// *******************************************************************************
//
//    Selection_Sort(A, n);
//    Print_List(A, n, "Selection Sort List");
//
//// *******************************************************************************
//
//    int Q[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT_MAX};
//    int m = 11;
//
//    Quick_Sort(A, 0, m-1);
//    Print_List(Q, m-1, "Quick Sort List");
//
//// *******************************************************************************
//
//    Recursive_Merge_Sort(A, 0, n-1);
//    Print_List(A, n, "Recursive Merge Sort List");
//
//// *******************************************************************************
//
//    Iterative_Merge_Sort(A, n);
//    Print_List(A, n, "Iterative Merge Sort List");
//
//// *******************************************************************************
//
//    Count_Sort(A, n);
//    Print_List(A, n, "Count Sort");
//
//// *******************************************************************************
//
//
//
//// *******************************************************************************
//
//
//
//// *******************************************************************************
//
//    return 0;
//}
