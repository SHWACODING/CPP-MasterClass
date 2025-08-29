#include <iostream>

using namespace std;


////    Find The Missing Element (Only One Element) In a Sorted Array ??
//
//int main()
//{
//    int A[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
//    int sum = 0;
//
//    for (int i = 0; i < 11; i++)
//    {
//        sum += A[i];
//    }
//    int RealSum = 12 * (12 + 1) / 2;
//
//    if (RealSum > sum)
//        cout << "Missing Element Is : " << RealSum - sum << endl;
//    else
//        cout << "No Missing Elements ?? \n";
//
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------

////    Find The Missing Element (Only One Element) In a Sorted Array ??
//
//int main ()
//{
//    int A[] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
//
//    int l = A[0];
//    int h = A[10];
//    int n = 11;
//
//    int diff = l - 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        if (A[i] - i != diff)
//        {
//            cout << "Missing Element Is : " << i + diff << endl;
//            break;
//        }
//        else
//            cout << "No Missing Elements ?? \n";
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------

////    Find The Multiple Missing Elements In a Sorted Array ??
//
//int main()
//{
//    int A[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
//
//    int l = A[0];
//    int h = A[10];
//    int n = 11;
//
//    int diff = l - 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        if (A[i] - i != diff)
//        {
//            while (diff < A[i] - i)
//            {
//                cout << "Missing Element Is : " << i + diff << endl;
//                diff++;
//            }
//        }
//        else
//            cout << "No Missing Elements ?? \n";
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------

////    Find The Missing Element (Only One Element) In an Unsorted Array Use Hashing ??
//
//int main()
//{
//    int A[] = {3, 7, 4, 12, 6, 1, 11, 2, 10};
//
//    int l = 1;
//    int h = 12;
//    int n = 10;
//
//    int H[h];
//
//    for (int i = 0; i < n; i++)
//        H[A[i]]++;
//
//    for (int i = l; i <= h; i++)
//    {
//        if (H[i] == 0)
//            cout << "Missing Element Is : " << i << endl;
//        else
//            cout << "No Missing Elements ?? \n";
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------

////    Find The Duplicate Elements In a Sorted Array ??
//
//    int main ()
//    {
//        int n = 10;
//        int A[n] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
//        int lastDuplicate = 0;
//
//        for (int i = 0; i < n; i++)
//        {
//            if (A[i] == A[i+1] && A[i] != lastDuplicate)
//            {
//                cout << "Duplicate Found : " << A[i] << endl;
//                lastDuplicate = A[i];
//            }
//            else
//                cout << "No Duplicates Found ?? \n";
//        }
//
//        return 0;
//    }

//--------------------------------------------------------------------------------------------------------------

////    Find The Duplicate Elements and Its Number Of Duplicating In a Sorted Array ??
//
//int main ()
//{
//    int n = 10;
//    int A[n] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
//
//    for (int i = 0; i < n-1; i++)
//    {
//        if (A[i] == A[i+1])
//        {
//            int j = i+1;
//            while (A[j] == A[i])
//                j++;
//            cout << A[i] << " Is Appearing For " << j-i << " Times. \n";
//            i = j - 1;
//        }
//    }
//}


//--------------------------------------------------------------------------------------------------------------

////    Find The Duplicate Elements and Its Number Of Duplicating In a Sorted Array Use Hashing ??
//
//int main ()
//{
//    int n = 10;
//    int A[n] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
//
//    int H[20] = {0};
//
//    for (int i = 0; i < n; i++)
//        H[A[i]]++;
//
//    for (int i = 0; i < 20; i++)
//    {
//        if (H[i] > 1)
//            cout << i << " Is Appearing For " << H[i] << " Times. \n";
//        else
//            cout << "No Duplicates Found ?? \n";
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------

////    Find The Duplicate Elements and Its Number Of Duplicating In an Unsorted Array ??
//
//int main ()
//{
//    int n = 10;
//    int A[n] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
//
//    for (int i = 0; i < n-1; i++)
//    {
//        int cnt = 1;
//
//        if (A[i] != -1)
//        {
//            for (int j = i+1; j < n; j++)
//            {
//                if (A[i] == A[j])
//                {
//                    cnt++;
//                    A[j] = -1;
//                }
//            }
//
//            if (cnt > 1)
//                cout << A[i] << " Appears For : " << cnt << " Times. \n";
//        }
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------

////    Find The Duplicate Elements and Its Number Of Duplicating In an Unsorted Array Use Hashing ??
//
//int main ()
//{
//    int n = 10;
//    int A[n] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
//
//    int maximum = 8;
//    int H[maximum] = {0};
//
//    for (int i = 0; i < n; i++)
//        H[A[i]]++;
//
//    for (int i = 0; i <= maximum; i++)
//    {
//        if (H[i] > 1)
//            cout << i << " Is Appearing For " << H[i] << " Times. \n";
//        else
//            cout << "No Duplicates Found ?? \n";
//    }
//
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------

////    Find The Pair Of Elements and Its Summation In a sorted Array ??
//
//int main ()
//{
//    int n = 12;
//    int A[n] = {6, 3, 8, 1, 10, 16, 7, 5, 2, 9, 0, 14};
//
//    int k = 10;
//
//    for (int i = 0; i < n-1; i++)
//        for (int j = i+1; j < n; j++)
//            if (A[i] + A[j] == k)
//                cout << A[i] << " + " << A[j] << " = " << k << endl;
//
//    return 0;
//}

//--------------------------------------------------------------------------------------------------------------

////    Find The Pair Of Elements and Its Summation In a Unsorted Array ??
//
//int main ()
//{
//    int n = 10;
//    int A[n] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
//
//    int maximum = 16;
//    int H[maximum] = {0};
//
//    int k = 10;
//
//// دا اجمد جدا علشان انا اللي عاملة وهو الاصح
//
//    for (int i = 0; i < n; i++)
//        H[A[i]]++;
//
//    for (int i = 0; i < maximum; i++)
//        for (int j = i+1; j < maximum; j++)
//            if (H[i] > 0 && H[j] > 0 && i + j == k)
//                cout << i << " + " << j << " = " << k << endl;
//
////    We Can Also Write In This Form
//
////    for (int i = 0; i < n; i++)
////    {
////        if (H[k - A[i]] != 0)
////            cout << A[i] << " + " << k - A[i] << " = " << k << endl;
////        H[A[i]]++;
////    }
//
//    return 0;
//}


//--------------------------------------------------------------------------------------------------------------

////    Find The Pair Of Elements and Its Summation In a sorted Array ??
//
//int main ()
//{
//    int n = 10;
//    int A[n] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
//
//    int k = 10;
//
//    int i = 0, j = n-1;
//    while (i < j)
//    {
//        if (A[i] + A[j] == k)
//        {
//            cout << A[i] << " + " << A[j] << " = " << k << endl;
//            i++;
//            j--;
//        }
//        else if (A[i] + A[j] < k)
//            i++;
//        else
//            j--;
//    }
//
//
//    return 0;
//}

// -----------------------------------------

//// Same Code But Using For Loop ??

//int main ()
//{
//    int n = 10;
//    int A[n] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
//
//    int k = 10;
//
//    for (int i = 0, j = n-1; i < j;)
//    {
//        if (A[i] + A[j] == k)
//        {
//            cout << A[i] << " + " << A[j] << " = " << k << endl;
//            i++;
//            j--;
//        }
//        else if (A[i] + A[j] < k)
//            i++;
//        else
//            j--;
//    }
//
//
//    return 0;
//}


//--------------------------------------------------------------------------------------------------------------

////    Find The Max And Min In A Single Scan ??

//int main ()
//{
//    int n = 10;
//    int A[n] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
//
//    int mn = A[0], mx = A[0];
//
//    for (int i = 1; i <= n; i++)
//    {
//        if (A[i] < mn)
//            mn = A[i];
//        else if (A[i] > mx)
//            mx = A[i];
//    }
//    cout << "The Minimum Element Is : " << mn << endl;
//    cout << "The Maximum Element Is : " << mx << endl;
//
//    return 0;
//}


