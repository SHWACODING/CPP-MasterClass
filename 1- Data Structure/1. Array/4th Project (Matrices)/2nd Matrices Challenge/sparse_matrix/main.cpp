#include <iostream>
#include <math.h>

using namespace std;

//// Sparse Matrices Using Struct ??
//
//struct Element
//{
//    int i, j, x;
//};
//
//struct Sparse
//{
//    int m, n, num;
//    struct Element *e;
//};
//
//void Create(struct Sparse *s)
//{
//    cout << "Enter Array Dimensions (m X n) : ";
//    cin >> s->m >> s->n;
//    cout << "Enter The Number Of Non Zero Elements : ";
//    cin >> s->num;
//    s->e = new Element[s->num];
//    cout << "Enter The Row Index (i) , The Column Index (j) And The Non Zero Element Itself (x) : \n";
//    for (int i = 0; i < s->num; i++)
//        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
//}
//
//void Display (struct Sparse s)
//{
//    int i, j, k = 0;
//    for (i = 0; i < s.m; i++)
//    {
//        for (j = 0; j < s.n; j++)
//        {
//            if (i == s.e[k].i && j == s.e[k].j)
//                cout << s.e[k++].x << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//}
//
//
//int main()
//{
//
//    struct Sparse s;
//
//    Create(&s);
//
//    Display(s);
//
//    return 0;
//}

//// Adding Sparse Matrices Using Struct??

//struct Element
//{
//    int i, j, x;
//};
//
//struct Sparse
//{
//    int m, n, num;
//    struct Element *e;
//};
//
//void Create(struct Sparse *s)
//{
//    cout << "Enter Array Dimensions (m X n) : ";
//    cin >> s->m >> s->n;
//    cout << "Enter The Number Of Non Zero Elements : ";
//    cin >> s->num;
//    s->e = new Element[s->num];
//    cout << "Enter The Row Index (i) , The Column Index (j) And The Non Zero Element Itself (x) : \n";
//    for (int i = 0; i < s->num; i++)
//        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
//}
//
//
//void Display (struct Sparse s)
//{
//    int i, j, k = 0;
//    for (i = 0; i < s.m; i++)
//    {
//        for (j = 0; j < s.n; j++)
//        {
//            if (i == s.e[k].i && j == s.e[k].j)
//                cout << s.e[k++].x << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//}
//
//
//struct Sparse * Add (Sparse *s1, Sparse *s2)
//{
//    Sparse *sum;
//    int i, j, k;
//    i = j = k = 0;
//
//    sum = new Sparse;
//    sum->e = new Element[s1->num + s2->num];
//
//    while (i < s1->num && j < s2->num)
//    {
//        if (s1->e[i].i < s2->e[j].i)
//            sum->e[k++] = s1->e[i++];
//        else if (s1->e[i].i > s2->e[j].j)
//            sum->e[k++] = s2->e[j++];
//        else
//        {
//            if (s1->e[i].j < s2->e[j].j)
//                sum->e[k++] = s1->e[i++];
//            else if (s1->e[i].j > s2->e[j].j)
//                sum->e[k++] = s2->e[j++];
//            else
//            {
//                sum->e[k] = s1->e[i];
//                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
//            }
//        }
//    }
//
//    for (; i < s1->num; i++)
//        sum->e[k++] = s1->e[i];
//
//    for (; j < s2->num; j++)
//        sum->e[k++] = s2->e[j];
//
//    sum->m = s1->m;
//    sum->n = s1->n;
//
//    sum->num = k;
//
//    return sum;
//}
//
//
//int main ()
//{
//    struct Sparse s1, s2, *s3;
//
//    Create(&s1);
//
//    cout << endl;
//
//    Create(&s2);
//
//    cout << endl << endl;
//
//    s3 = Add(&s1, &s2);
//
//    cout << "This Is First Matrix : \n\n";
//    Display(s1);
//
//    cout << endl << endl;
//
//    cout << "This Is Second Matrix : \n\n";
//    Display(s2);
//
//    cout << endl << endl;
//
//    cout << "This Is The Sum Of First & Second Matrices : \n\n";
//    Display(*s3);
//
//
//    return 0;
//}

//// Sparse Matrices Using Class Usual Method ??

//class Element
//{
//public:
//    int i;
//    int j;
//    int x;
//};
//
//class Sparse
//{
//private:
//    int m;
//    int n;
//    int num;
//    Element *e;
//
//public:
//
//    Sparse (int m, int n, int num)
//    {
//        this->m = m;
//        this->n = n;
//        this->num = num;
//        e = new Element[this->num];
//    }
//
//    ~Sparse ()
//    {
//        delete []e;
//    }
//
//    void Read ()
//    {
//        cout << "Enter The Non Zero Elements : \n";
//        for (int i = 0; i < num; i++)
//            cin >> e[i].i >> e[i].j >> e[i].x;
//    }
//
//    void Display ()
//    {
//        int k = 0;
//
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (e[k].i == i && e[k].j == j)
//                    cout << e[k++].x << " ";
//                else
//                    cout << "0 ";
//            }
//            cout << endl;
//        }
//    }
//};
//
//
//int main ()
//{
//    int m, n, num;
//
//    cout << "Enter The Array Dimensions (m X n) :  ";
//    cin >> m >> n;
//    cout << "Enter The Number Of Non Zero Elements :  ";
//    cin >> num;
//
//    Sparse s1(m, n, num);
//
//    s1.Read();
//    s1.Display();
//
//
//    return 0;
//}


//// Sparse Matrices Using Class Overloading Operator And Friend Function ??
//
//class Element
//{
//public:
//    int i;
//    int j;
//    int x;
//};
//
//class Sparse
//{
//private:
//    int m;
//    int n;
//    int num;
//    Element *e;
//
//public:
//
//    Sparse (int m, int n, int num)
//    {
//        this->m = m;
//        this->n = n;
//        this->num = num;
//        e = new Element[this->num];
//    }
//
//    ~Sparse ()
//    {
//        delete []e;
//    }
//
//    friend istream & operator >> (istream &is, Sparse &s);
//    friend ostream & operator << (ostream &os, Sparse &s);
//};
//
//istream & operator >> (istream &is, Sparse &s)
//{
//    cout << "Enter The Non Zero Elements : \n";
//    for (int i = 0; i < s.num; i++)
//        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
//    return is;
//}
//
//ostream & operator << (ostream &os, Sparse &s)
//{
//    int k = 0;
//
//    for (int i = 0; i < s.m; i++)
//    {
//        for (int j = 0; j < s.n; j++)
//        {
//            if (s.e[k].i == i && s.e[k].j == j)
//                cout << s.e[k++].x << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//    return os;
//}
//
//
//int main ()
//{
//    int m, n, num;
//
//    cout << "Enter The Array Dimensions (m X n) :  ";
//    cin >> m >> n;
//    cout << "Enter The Number Of Non Zero Elements :  ";
//    cin >> num;
//
//    Sparse s1(m, n, num);
//
//    cin >> s1;
//    cout << s1;
//
//
//    return 0;
//}


//// Adding Sparse Matrices Using Class Overloading Operator And Friend Function ??

//class Element
//{
//public:
//    int i;
//    int j;
//    int x;
//};
//
//class Sparse
//{
//private:
//    int m;
//    int n;
//    int num;
//    Element *e;
//
//public:
//
//    Sparse (int m, int n, int num)
//    {
//        this->m = m;
//        this->n = n;
//        this->num = num;
//        e = new Element[this->num];
//    }
//
//    ~Sparse ()
//    {
//        delete []e;
//    }
//
//    Sparse operator+(Sparse &s);
//
//    friend istream & operator >> (istream &is, Sparse &s);
//    friend ostream & operator << (ostream &os, Sparse &s);
//};
//
//Sparse Sparse::operator+(Sparse &s)
//{
//    int i, j, k;
//
////    if (m != s.m || n != s.n)
////        return NULL;
//    Sparse *sum = new Sparse(m, n, num+s.num);
//
//    i = j = k = 0;
//
//    while (i < num && j < s.num)
//    {
//        if (e[i].i < s.e[j].i)
//            sum->e[k++] = e[i++];
//        else if (e[i].i > s.e[j].i)
//            sum->e[k++] = s.e[j++];
//        else
//        {
//            if (e[i].j < s.e[j].j)
//                sum->e[k++] = e[i++];
//            else if (e[i].j > s.e[j].j)
//                sum->e[k++] = s.e[j++];
//            else
//            {
//                sum->e[k] = e[i];
//                sum->e[k++].x = e[i++].x + s.e[j++].x;
//            }
//        }
//    }
//
//    for (; i < num; i++)
//        sum->e[k++] = e[i];
//
//    for (; j < num; j++)
//        sum->e[k++] = s.e[j];
//
//    sum->num = k;
//    return *sum;
//
//}
//
//istream & operator >> (istream &is, Sparse &s)
//{
//    cout << "Enter The Non Zero Elements : \n";
//    for (int i = 0; i < s.num; i++)
//        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
//    return is;
//}
//
//ostream & operator << (ostream &os, Sparse &s)
//{
//    int k = 0;
//
//    for (int i = 0; i < s.m; i++)
//    {
//        for (int j = 0; j < s.n; j++)
//        {
//            if (s.e[k].i == i && s.e[k].j == j)
//                cout << s.e[k++].x << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//    return os;
//}
//
//
//int main ()
//{
//    int m1, m2, n1, n2, num1, num2;
//
//    cout << "Enter The Array Dimensions (m X n) :  ";
//    cin >> m1 >> n1;
//    cout << "Enter The Number Of Non Zero Elements :  ";
//    cin >> num1;
//
//    Sparse s1(m1, n1, num1);
//    cin >> s1;
//    cout << endl << s1 << endl;
//
//    cout << "Enter The Array Dimensions (m X n) :  ";
//    cin >> m2 >> n2;
//    cout << "Enter The Number Of Non Zero Elements :  ";
//    cin >> num2;
//
//    Sparse s2(m2, n2, num2);
//    cin >> s2;
//    cout << endl << s2 << endl;
//
//    Sparse sum = s1 + s2;
//
//    cout << "First Matrix IS : \n\n" << s1 << endl;
//    cout << "Second Matrix IS : \n\n" << s2 << endl;
//    cout << "Sum Matrix IS : \n\n" << sum;
//
//    return 0;
//}


//// Polynomial Representation Using Struct ??
//// Basic Method Of Addition ??
//
//struct Term
//{
//    int coeff, exp;
//};
//
//struct Poly
//{
//    int n;
//    struct Term *terms;
//};
//
//
//int main ()
//{
//    struct Poly p;
//
//    int x = 5, sum = 0;
//
//    cout << "Enter The Number Of Terms : ";
//    cin >> p.n;
//
//    p.terms = new Term[p.n];
//
//    cout << "Enter Polynomial Terms : \n";
//    for (int i = 0; i < p.n; i++)
//    {
//        cout << "Enter The Term (Coefficient & Exponent) Number " << i+1 << " :  ";
//        cin >> p.terms[i].coeff >> p.terms[i].exp;
//
//        sum += p.terms[i].coeff * pow(x, p.terms[i].exp);
//
//    }
//    cout << sum;
//
//    return 0;
//}

//// Polynomial Representation Using Struct ??


struct Term
{
    int coeff, exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};


void Create (struct Poly *p)
{
    int i;
    cout << "Enter The Number Of Terms : ";
    cin >> p->n;

    p->terms = new Term[p->n];

    cout << "Enter All Polynomial Terms : \n";
    for (i = 0; i < p->n; i++)
    {
        cout << "Enter The Term (Coefficient & Exponent) Number " << i+1 << " :  ";
        cin >> p->terms[i].coeff >> p->terms[i].exp;
    }
}

void Display (struct Poly p)
{
    int i;
    for (i = 0; i < p.n; i++)
        cout << p.terms[i].coeff << "X^" << p.terms[i].exp << " + ";
    cout << endl;
}

struct Poly *Add (struct Poly *p1, struct Poly *p2)
{
    int i, j, k;

    struct Poly *sum;

    sum = new Poly;

    sum->terms = new Term[p1->n + p2->n];

    i = j = k = 0;

    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];

        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];

        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    for (; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];

    for (; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    sum->n = k;

    return sum;

};

int main ()
{
    struct Poly p1, p2, *p3;

    Create(&p1);

    cout << endl << endl;
    Create(&p2);

    p3 = Add(&p1, &p2);

    cout << endl << "First Polynomial Is : "<< endl << endl;

    Display(p1);

    cout << endl << "Second Polynomial Is : "<< endl << endl;

    Display(p2);

    cout << endl << "Summation Polynomial Is : "<< endl << endl;

    Display(*p3);

    cout << endl;


    return 0;
}


