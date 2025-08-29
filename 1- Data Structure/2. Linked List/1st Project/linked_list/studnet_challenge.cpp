#include <iostream>
#include <cmath>


using namespace std;

//______________________________________________________________________________________________________

// Sparse Matrix Using Linked List ?? مش عارف اعملها خالص !!!!!!

class SparseMatrixNode
{
public:
    int col;
    int val;
    SparseMatrixNode *next;
};

class LinkedList
{
private:
    SparseMatrixNode *first;
public:
    LinkedList () {first = NULL;}

    void CreateSparseMatrixLL (SparseMatrixNode *s);
    void DisplaySparseMatrixLL ();
    int LengthOfSparseMatrixLL ();

};

void LinkedList::DisplaySparseMatrixLL ()
{
    int m, n;
    cin >> m >> n;

    SparseMatrixNode *p = first;

    for (int i = 0; i < m; ++i)
    {
        p = A[i];
        for (int j = 0; j < n; ++j)
        {
            if (j == p->col)
            {
                cout << p->val << " ";
                p = p->next;
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }

}

int LinkedList::LengthOfSparseMatrixLL ()
{
    SparseMatrixNode *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}


int main ()
{
    int A[1, 2, 3, 4, 5];

    LinkedList L1(A, 5);

    L1.DisplaySparseMatrixLL();

    cout << L1.LengthOfSparseMatrixLL() << endl;

    return 0;
}


//______________________________________________________________________________________________________

//// Polynomial Representation Using Linked List ??
//
//class PolynomialNode
//{
//public:
//    int coeff;
//    int exp;
//    PolynomialNode *next;
//};
//
//
//class LinkedList
//{
//public:
//    PolynomialNode *poly;
//    LinkedList () {poly = NULL;}
//    void CreatePolynomialLL ();
//    void DisplayPolynomial (PolynomialNode *p);
//    long EvaluatePolynomial (PolynomialNode *p, int x);
//};
//
//
//void LinkedList::CreatePolynomialLL ()
//{
//    PolynomialNode *t, *last;
//    int num;
//
//    cout << "Enter The Number Of Terms : ";
//    cin >> num;
//
//    cout << "Enter Each Term :: The Coefficient && The Exponent : \n";
//
//    for (int i = 0; i < num; ++i)
//    {
//        t = new PolynomialNode;
//        cin >> t->coeff >> t->exp;
//
//        t->next = NULL;
//        if (poly == NULL)
//        {
//            poly = last = t;
//        }
//        else
//        {
//            last->next = t;
//            last = t;
//        }
//    }
//}
//
//void LinkedList::DisplayPolynomial (PolynomialNode *p)
//{
//    while (p)
//    {
//        cout << p->coeff << "X^" << p->exp << " + ";
//        p = p->next;
//    }
//    cout << endl;
//}
//
//long LinkedList::EvaluatePolynomial (PolynomialNode *p, int x)
//{
//    long val = 0;
//
//    while (p)
//    {
//        val += p->coeff * pow(x, p->exp);
//        p = p->next;
//    }
//    return val;
//}
//
//int main ()
//{
//    LinkedList L1;
//
//    L1.CreatePolynomialLL();
//    L1.DisplayPolynomial(L1.poly);
//
//    int x_val;
//    cin >> x_val;
//
//    cout << L1.EvaluatePolynomial(L1.poly, x_val) << endl;
//
//
//    return 0;
//}


