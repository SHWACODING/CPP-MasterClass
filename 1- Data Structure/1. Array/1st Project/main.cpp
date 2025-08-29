#include <iostream>
using namespace std;

//template <class T>;

class Array
{
    private:
//        T *A;
        int *A;
        int arrSize;
        int arrLength;
        void swapping(int *x, int *y);

    public:
        Array () {
            arrSize = 10;
            arrLength = 0;
            A = new int[arrSize];
//            A = new T[arrSize];
        }
        Array (int sz) {
            arrSize = sz;
            arrLength = 0;
            A = new int[arrSize];
//            A = new T[arrSize];
        }
        ~Array() {
            delete []A;
        }
        void Display();
        void Append(int x);
        void Insert(int index, int x);
        int Delete(int index);

        int LinearSearch(int key);
        int BinarySearch(int key);
        int RBinarySearch(int a[], int l, int h, int key);

        int Get(int index);
        void Set(int index, int x);
        int Max();
        int Min();
        int Sum();
        float Avg();

        void Reverse();
        void Reverse2();
        void InsertSort(int x);
        int isSorted();
        void Rearrange();

        Array* Merge(Array arr2);
        Array* Union(Array arr2);
        Array* Intersection(Array arr2);
        Array* Difference(Array arr2);
};

void Array::Display()
{
    cout << endl << " Elements Are : " << endl;
    for (int i = 0; i < arrLength; i++)
        cout << A[i] << "\t";
}

void Array::Append(int x)
{
    if (arrLength < arrSize)
        A[arrLength++] = x;
}

void Array::Insert(int index, int x)
{
    if (index >= 0 && index <= arrLength)
    {
        for (int i = arrLength; i > index; i--)
            A[i] = A[i-1];
        A[index] = x;
        arrLength++;
    }
}

int Array::Delete(int index)
{
    int x = 0;

    if (index >= 0 && index < arrLength)
    {
        x = A[index];
        for(int i = index; i < arrLength-1; i++)
            A[i] = A[i+1];
        arrLength--;
        return x;
    }
    return 0;
}

void Array::swapping(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key)
{
    for(int i = 0; i < arrLength; i++)
    {
        if (key == A[i])
        {
            swapping(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l = 0, mid, h = arrLength - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Array::RBinarySearch(int a[], int l, int h, int key)
{
    int mid;
    if(l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinarySearch(a, l, mid - 1, key);
        else
            return RBinarySearch(a, mid + 1, h, key);
    }
    return -1;
}

int Array::Get(int index)
{
    if (index >= 0 && index < arrLength)
        return A[index];
    return -1;
}

void Array::Set(int index, int x)
{
    if (index >= 0 && index < arrLength)
        A[index] = x;
}

int Array::Max()
{
    int maximum = A[0];
    for (int i = 1; i < arrLength; i++)
    {
        if (A[i] > maximum)
            maximum = A[i];
    }
    return maximum;
}

int Array::Min()
{
    int minimum = A[0];
    for (int i = 1; i < arrLength; i++)
    {
        if (A[i] < minimum)
            minimum = A[i];
    }
    return minimum;
}

int Array::Sum()
{
    int s = 0;
    for (int i = 0; i < arrLength; i++)
        s += A[i];
    return s;
}

float Array::Avg()
{
    return float(Sum() / arrLength);
}

void Array::Reverse()
{
    Array *B = new Array(arrLength);

    for (int i = arrLength - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (int i = 0; i < arrLength; i++)
        A[i] = B->A[i];
}

void Array::Reverse2()
{
    for (int i = 0, j = arrLength - 1; i < j; i++, j--)
        swapping(&A[i], &A[j]);
}

void Array::InsertSort(int x)
{
    int i = arrLength - 1;
    if (arrLength == arrSize)
        return;
    while (i >= 0 && A[i] > x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    arrLength++;
}

int Array::isSorted()
{
    for (int i = 1; i < arrLength; i++)
    {
        if (A[i] > A[i+1])
            return 0;
    }
    return 1;
}

void Array::Rearrange()
{
    int i = 0, j = arrLength - 1;

    while(i < j)
    {
        while(A[i] < 0)
            i++;
        while(A[j] >= 0)
            j--;
        if (i < j)
            swapping(&A[i], &A[j]);
    }
}

Array* Array::Merge(Array arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(arrLength + arr2.arrLength);

    while (i < arrLength && j < arr2.arrLength)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = A[j++];
    }

    for (; i < arrLength; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.arrLength; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->arrLength = arrLength + arr2.arrLength;

    return arr3;
}

Array* Array::Union(Array arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(arrLength + arr2.arrLength);

    while (i < arrLength && j < arr2.arrLength)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2.A[j])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }

        for (; i < arrLength; i++)
            arr3->A[k++] = A[i];

        for (; j < arr2.arrLength; j++)
            arr3->A[k++] = arr2.A[j];

        arr3->arrLength = k;
        return arr3;
    }
}

Array* Array::Intersection(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array(arrLength + arr2.arrLength);
    while (i < arrLength && j < arr2.arrLength)
    {
        if (A[i] < arr2.A[j])
            i++;
        else if (A[i] > arr2.A[j])
            j++;
        else if (A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->arrLength = k;
    return arr3;
}

Array* Array::Difference(Array arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(arrLength + arr2.arrLength);

    while (i < arrLength && j < arr2.arrLength)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arrLength; i++)
        arr3->A[k++] = A[i];

    arr3->arrLength = k;
    return arr3;
}


//template <class T>;
int main()
{
//    Array<int> *arr1;  // We Use This Template To Make The Type Of That Array Dynamic ?? جامدةة
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter The Size Of The Array : " << endl;
    cin >> sz;

    arr1 = new Array(sz);

    do
    {
        cout << endl << endl << "Array Menu : \n";
        cout << "1. Insert \n";
        cout << "2. Delete \n";
        cout << "3. Search \n";
        cout << "4. Sum \n";
        cout << "5. Display \n";
        cout << "6. Exit \n";

        cout << "Enter Your Choice : \n";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter An Element To Insert And Its Index : \n";
                cin >> x;
                cin >> index;
                arr1->Insert(index, x);
                break;
            case 2:
                cout << "Enter Index Of Element To Delete : \n";
                cin >> index;
                x = arr1->Delete(index);
                cout << "Element " << x << " Deleted Successfully \n";
                break;
            case 3:
                cout << "Enter Element To Search For : \n";
                cin >> x;
                index = arr1->LinearSearch(x);
                cout << "Element Index " << index << endl;
                break;
            case 4:
                cout << "Sum Of Array Elements Is : " << arr1->Sum() << endl;
                break;
            case 5:
                arr1->Display();

        }
    } while (ch < 6);
    return 0;
}
