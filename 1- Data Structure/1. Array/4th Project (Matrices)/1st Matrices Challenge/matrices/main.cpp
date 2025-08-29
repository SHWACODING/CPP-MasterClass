#include <iostream>

using namespace std;

// Write The Diagonal Matrix Using Struct ?????????????????????

//struct Matrix
//{
//    int A[10];
//    int n;
//};
//
//void Set (struct Matrix *m, int i, int j, int x)
//{
//    if (i == j)
//        m->A[i-1] = x;
//}
//
//int Get (struct Matrix m, int i, int j)
//{
//    if (i == j)
//         return m.A[i-1];
//    else
//        return 0;
//}
//
//void Display (struct Matrix m)
//{
//    int i, j;
//
//    for (i = 0; i < m.n; i++)
//    {
//        for (j = 0; j < m.n; j++)
//        {
//            if (i == j)
//                cout << m.A[i] << " ";
//            else
//                cout << 0 << " ";
//        }
//        cout << endl;
//    }
//}
//
//
//int main()
//{
//    struct Matrix m;
//    m.n = 4;
//
//    Set (&m, 1, 1, 5);
//    Set (&m, 2, 2, 8);
//    Set (&m, 3, 3, 9);
//    Set (&m, 4, 4, 12);
//
//    cout << Get (m, 2, 2) << endl << "-------------" << endl;
//
//    Display(m);
//
//    return 0;
//}

// Another Method To Write The Diagonal Matrix Using Class ??????

//class Diagonal
//{
//private:
//    int *A;
//    int n;
//public:
//    Diagonal ()
//    {
//        this->n = 4;
//        A = new int[n];
//    }
//    Diagonal (int n)
//    {
//        this->n = n;
//        A = new int[n];
//    }
//    ~Diagonal()
//    {
//        delete []A;
//    }
//
//    void Set (int i, int j, int x);
//    int Get (int i, int j);
//    void Display ();
//
//};
//
//void Diagonal::Set (int i, int j, int x)
//{
//    if (i == j)
//        A[i-1] = x;
//}
//
//int Diagonal::Get (int i, int j)
//{
//    if (i == j)
//        return A[i-1];
//    else
//        return 0;
//}
//
//void Diagonal::Display()
//{
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (i == j)
//                cout << A[i] << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//}
//
//int main ()
//{
//    Diagonal d(4);
//
//    d.Set(1, 1, 4);
//    d.Set(2, 2, 7);
//    d.Set(3, 3, 9);
//    d.Set(4, 4, 8);
//
//    d.Display();
//
//    cout << "-------------------" << endl;
//
//    cout << d.Get(1, 1) << endl;
//
//
//    return 0;
//}


// Write The Lower Triangular Matrix Using Struct  (( Row Measure Representation )) ???
//
//struct Matrix
//{
//    int *A;
//    int n;
//};
//
//void Set (struct Matrix *m, int i, int j, int x)
//{
//    if (i >= j)
//        m->A[i * (i-1) / 2 + j - 1] = x;
//}
//
//int Get (struct Matrix m, int i, int j)
//{
//    if (i >= j)
//         return m.A[i * (i-1) / 2 + j - 1];
//    else
//        return 0;
//}
//
//void Display (struct Matrix m)
//{
//    for (int i = 1; i <= m.n; i++)
//    {
//        for (int j = 1; j <= m.n; j++)
//        {
//            if (i >= j)
//                cout << m.A[i*(i-1)/2+j-1] << " ";
//            else
//                cout << 0 << " ";
//        }
//        cout << endl;
//    }
//}
//
//
//int main()
//{
//    struct Matrix m;
//    int i, j, x;
//
//    cout << "Enter The Matrix Dimension : ";
//    cin >> m.n;
//
//    m.A = new int[m.n*(m.n+1)/2];
//
//    cout << "Enter All Matrix Elements : \n";
//
//    for (i = 1; i <= m.n; i++)
//    {
//        for (j = 1; j <= m.n; j++)
//        {
//            cin >> x;
//            Set (&m, i, j, x);
//        }
//    }
//
//    cout << endl << endl;
//
//    Display (m);
//
//    return 0;
//}


// Write The Lower Triangular Matrix Using Struct  (( column Measure Representation )) ???
//
//struct LowerTri
//{
//    int *A;
//    int n;
//};
//
//void Set (struct LowerTri *m, int i, int j, int x)
//{
//    if (i >= j)
//        m->A[m->n*(j-1)-(j-2)*(j-1)/2+i-j] = x;
//}
//
//int Get (struct LowerTri m, int i, int j)
//{
//    if (i >= j)
//         return m.A[m.n*(j-1)-(j-2)*(j-1)/2+i-j];
//    else
//        return 0;
//}
//
//void Display (struct LowerTri m)
//{
//    for (int i = 1; i <= m.n; i++)
//    {
//        for (int j = 1; j <= m.n; j++)
//        {
//            if (i >= j)
//                cout << m.A[m.n*(j-1)-(j-2)*(j-1)/2+i-j] << " ";
//            else
//                cout << 0 << " ";
//        }
//        cout << endl;
//    }
//}
//
//
//int main()
//{
//    struct LowerTri m;
//    int i, j, x;
//
//    cout << "Enter The Matrix Dimension : ";
//    cin >> m.n;
//
//    m.A = new int[m.n*(m.n+1)/2];
//
//    cout << "Enter All Matrix Elements : \n";
//
//    for (i = 1; i <= m.n; i++)
//    {
//        for (j = 1; j <= m.n; j++)
//        {
//            cin >> x;
//            Set (&m, i, j, x);
//        }
//    }
//
//    cout << endl << endl;
//
//    Display (m);
//
//    return 0;
//}


// Another Method To Write The Lower Triangular Matrix Using Class (( Row Measure Representation ))  ???

//class LowerTri
//{
//private:
//    int *A;
//    int n;
//public:
//    LowerTri ()
//    {
//        this->n = 4;
//        A = new int[n*(n+1)/2];
//    }
//    LowerTri (int n)
//    {
//        this->n = n;
//        A = new int[n*(n+1)/2];
//    }
//    ~LowerTri()
//    {
//        delete []A;
//    }
//
//    void Set (int i, int j, int x);
//    int Get (int i, int j);
//    void Display ();
//    int GetDimension(){return n;}
//
//};
//
//void LowerTri::Set (int i, int j, int x)
//{
//    if (i >= j)
//        A[i*(i-1)/2+j-1] = x;
//}
//
//int LowerTri::Get (int i, int j)
//{
//    if (i >= j)
//        return A[i*(i-1)/2+j-1];
//    else
//        return 0;
//}
//
//void LowerTri::Display()
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (i >= j)
//                cout << A[i*(i-1)/2+j-1] << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//}
//
//int main ()
//{
//    int d;
//    cout << "Enter The Dimensions Of Matrix : ";
//    cin >> d;
//
//    LowerTri lm(d);
//
//    int x;
//    cout << "Enter All Matrix Elements : \n";
//
//    for (int i = 1; i <= d; i++)
//    {
//        for (int j = 1; j <= d; j++)
//        {
//            cin >> x;
//            lm.Set(i, j, x);
//        }
//    }
//
//    cout << endl << endl;
//
//    lm.Display();
//
//    return 0;
//}

// Another Method To Write The Lower Triangular Matrix Using Class (( column Measure Representation ))  ???

//class LowerTri
//{
//private:
//    int *A;
//    int n;
//public:
//    LowerTri ()
//    {
//        this->n = 4;
//        A = new int[n*(n+1)/2];
//    }
//    LowerTri (int n)
//    {
//        this->n = n;
//        A = new int[n*(n+1)/2];
//    }
//    ~LowerTri()
//    {
//        delete []A;
//    }
//
//    void Set (int i, int j, int x);
//    int Get (int i, int j);
//    void Display ();
//    int GetDimension(){return n;}
//
//};
//
//void LowerTri::Set (int i, int j, int x)
//{
//    if (i >= j)
//        A[n*(j-1)-(j-2)*(j-1)/2+i-j] = x;
//}
//
//int LowerTri::Get (int i, int j)
//{
//    if (i >= j)
//        return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
//    else
//        return 0;
//}
//
//void LowerTri::Display()
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (i >= j)
//                cout << A[n*(j-1)-(j-2)*(j-1)/2+i-j] << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//}
//
//int main ()
//{
//    int d;
//    cout << "Enter The Dimensions Of Matrix : ";
//    cin >> d;
//
//    LowerTri lm(d);
//
//    int x;
//    cout << "Enter All Matrix Elements : \n";
//
//    for (int i = 1; i <= d; i++)
//    {
//        for (int j = 1; j <= d; j++)
//        {
//            cin >> x;
//            lm.Set(i, j, x);
//        }
//    }
//
//    cout << endl << endl;
//
//    lm.Display();
//
//    return 0;
//}


// Write The Lower Triangular Matrix Using Struct  (( Row Measure Representation )) ???

//struct UpperTri
//{
//    int *A;
//    int n;
//};
//
//void Set (struct UpperTri *m, int i, int j, int x)
//{
//    if (i <= j)
//        m->A[j * (j-1) / 2 + i - 1] = x;
//}
//
//int Get (struct UpperTri m, int i, int j)
//{
//    if (i <= j)
//         return m.A[j * (j-1) / 2 + i - 1];
//    else
//        return 0;
//}
//
//void Display (struct UpperTri m)
//{
//    for (int i = 1; i <= m.n; i++)
//    {
//        for (int j = 1; j <= m.n; j++)
//        {
//            if (i <= j)
//                cout << m.A[j * (j-1) / 2 + i - 1] << " ";
//            else
//                cout << 0 << " ";
//        }
//        cout << endl;
//    }
//}
//
//
//int main()
//{
//    struct UpperTri m;
//    int i, j, x;
//
//    cout << "Enter The Matrix Dimension : ";
//    cin >> m.n;
//
//    m.A = new int[m.n*(m.n+1)/2];
//
//    cout << "Enter All Matrix Elements : \n";
//
//    for (i = 1; i <= m.n; i++)
//    {
//        for (j = 1; j <= m.n; j++)
//        {
//            cin >> x;
//            Set (&m, i, j, x);
//        }
//    }
//
//    cout << endl << endl;
//
//    Display (m);
//
//    return 0;
//}


// Write The Upper Triangular Matrix Using Struct  (( column Measure Representation )) ???
//
//struct UpperTri
//{
//    int *A;
//    int n;
//};
//
//void Set (struct UpperTri *m, int i, int j, int x)
//{
//    if (i <= j)
//        m->A[m->n*(i-1)-(i-2)*(i-1)/2+j-i] = x;
//}
//
//int Get (struct UpperTri m, int i, int j)
//{
//    if (i <= j)
//         return m.A[m.n*(i-1)-(i-2)*(i-1)/2+j-i];
//    else
//        return 0;
//}
//
//void Display (struct UpperTri m)
//{
//    for (int i = 1; i <= m.n; i++)
//    {
//        for (int j = 1; j <= m.n; j++)
//        {
//            if (i <= j)
//                cout << m.A[m.n*(i-1)-(i-2)*(i-1)/2+j-i] << " ";
//            else
//                cout << 0 << " ";
//        }
//        cout << endl;
//    }
//}
//
//
//int main()
//{
//    struct UpperTri m;
//    int i, j, x;
//
//    cout << "Enter The Matrix Dimension : ";
//    cin >> m.n;
//
//    m.A = new int[m.n*(m.n+1)/2];
//
//    cout << "Enter All Matrix Elements : \n";
//
//    for (i = 1; i <= m.n; i++)
//    {
//        for (j = 1; j <= m.n; j++)
//        {
//            cin >> x;
//            Set (&m, i, j, x);
//        }
//    }
//
//    cout << endl << endl;
//
//    Display (m);
//
//    return 0;
//}


// Another Method To Write The Upper Triangular Matrix Using Class (( Row Measure Representation ))  ???

//class UpperTri
//{
//private:
//    int *A;
//    int n;
//public:
//    UpperTri ()
//    {
//        this->n = 4;
//        A = new int[n*(n+1)/2];
//    }
//    UpperTri (int n)
//    {
//        this->n = n;
//        A = new int[n*(n+1)/2];
//    }
//    ~UpperTri()
//    {
//        delete []A;
//    }
//
//    void Set (int i, int j, int x);
//    int Get (int i, int j);
//    void Display ();
//    int GetDimension(){return n;}
//
//};
//
//void UpperTri::Set (int i, int j, int x)
//{
//    if (i <= j)
//        A[j*(j-1)/2+i-1] = x;
//}
//
//int UpperTri::Get (int i, int j)
//{
//    if (i <= j)
//        return A[j*(j-1)/2+i-1];
//    else
//        return 0;
//}
//
//void UpperTri::Display()
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (i <= j)
//                cout << A[j*(j-1)/2+i-1] << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//}
//
//int main ()
//{
//    int d;
//    cout << "Enter The Dimensions Of Matrix : ";
//    cin >> d;
//
//    UpperTri lm(d);
//
//    int x;
//    cout << "Enter All Matrix Elements : \n";
//
//    for (int i = 1; i <= d; i++)
//    {
//        for (int j = 1; j <= d; j++)
//        {
//            cin >> x;
//            lm.Set(i, j, x);
//        }
//    }
//
//    cout << endl << endl;
//
//    lm.Display();
//
//    return 0;
//}

// Another Method To Write The Upper Triangular Matrix Using Class (( column Measure Representation ))  ???
//
//class UpperTri
//{
//private:
//    int *A;
//    int n;
//public:
//    UpperTri ()
//    {
//        this->n = 4;
//        A = new int[n*(n+1)/2];
//    }
//    UpperTri (int n)
//    {
//        this->n = n;
//        A = new int[n*(n+1)/2];
//    }
//    ~UpperTri()
//    {
//        delete []A;
//    }
//
//    void Set (int i, int j, int x);
//    int Get (int i, int j);
//    void Display ();
//    int GetDimension(){return n;}
//
//};
//
//void UpperTri::Set (int i, int j, int x)
//{
//    if (i <= j)
//        A[n*(i-1)-(i-2)*(i-1)/2+j-i] = x;
//}
//
//int UpperTri::Get (int i, int j)
//{
//    if (i <= j)
//        return A[n*(i-1)-(i-2)*(i-1)/2+j-i];
//    else
//        return 0;
//}
//
//void UpperTri::Display()
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (i <= j)
//                cout << A[n*(i-1)-(i-2)*(i-1)/2+j-i] << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//}
//
//int main ()
//{
//    int d;
//    cout << "Enter The Dimensions Of Matrix : ";
//    cin >> d;
//
//    UpperTri lm(d);
//
//    int x;
//    cout << "Enter All Matrix Elements : \n";
//
//    for (int i = 1; i <= d; i++)
//    {
//        for (int j = 1; j <= d; j++)
//        {
//            cin >> x;
//            lm.Set(i, j, x);
//        }
//    }
//
//    cout << endl << endl;
//
//    lm.Display();
//
//    return 0;
//}


