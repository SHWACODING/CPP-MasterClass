#include <iostream>

using namespace std;

//int Valid(char *name)
//{
//    for (int i = 0; name[i] != '\0'; i++)
//    {
//        if (!(name[i] >= 65 && name[i] <= 90) && !(name[i] >= 97 && name[i] <= 122) && !(name[i] >= 48 && name[i] <= 57))
//        {
//            return 0;
//        }
//    }
//}

void perm (char S[], int k)
{
    static int A[10] = {0};
    static char Res[10];

    int i;

    if (S[k] == '\0')
    {
        Res[k] = '\0';
        cout << Res << endl;
    }
    else
    {
        for (i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = S[i];
                A[i] = 1;
                perm(S, k+1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
////     Check If The String Is Counting Or Vowel ?
//    char A[] = "How Are You";
//
//    int vcnt = 0, ccnt = 0, word = 1;
//
//    for (int i = 0; A[i] != '\0'; i++)
//    {
//        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
//            vcnt++;
//        else if ((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122))
//            ccnt++;
//        else if (A[i] == ' ' && A[i-1] != ' ')
//            word++;
//    }
//    cout << vcnt << endl<< ccnt << endl << word << endl;

////     Validate The String

//    char *name = "Ana?321";
//
//    if (Valid(name))
//        cout << "valid Name, Signed In \n";
//    else
//        cout << "Invalid Name ? \nPlease Try Again ? \n";

////     Reversing The String ?

//    char A[] = "python";
//    char B[sizeof(A)];
//
//    int i, j;
//
//    for (i = 0; A[i] != '\0'; i++)
//    {
//    }
//    i -= 1;
//    for (j = 0; i >= 0;i--, j++)
//    {
//        B[j] = A[i];
//    }
//    B[j] = '\0';
//    cout << B << endl;

////     Other Method Of Reversing ?

//    char A[] = "Malak";
//
//    int temp, i, j;
//
//    for (i = 0; A[i] != '\0'; i++)
//    {
//    }
//    i -= 1;
//
//    for (j = 0; j < i; j++, i--)
//    {
//        temp = A[i];
//        A[i] = A[j];
//        A[j] = temp;
//    }
//    cout << A << endl;

////      Comparing Strings

//    char A[] = "Painter";
//    char B[] = "Painter";
//
//    int i, j;
//
//    for (i = 0, j = 0; A[i] != '\0', B[i] != '\0'; i++, j++)
//        if (A[i] != B[j])
//            break;
//    if (A[i] == B[j])
//        cout << "Equal \n";
//    else if (A[i] > B[j])
//        cout << "A Greater Than B \n";
//    else
//        cout << "A Smaller Than B \n";

////      Check if The String Is Palindrome Or Not
//
//    char A[] = "lidil";
//
//    int i, j, temp;
//
//        for (i = 0; A[i] != '\0'; i++)
//        {
//        }
//        i -= 1;
//
//        for (j = sizeof(A); j >= 0; j--, i--)
//        {
//            temp = A[i];
//            A[i] = A[j];
//            A[j] = temp;
//        }
//
//        if (A[i] == A[j])
//            cout << "Valid \n";
//        else
//            cout << "Not Valid \n";

////      Finding Duplicates In a String ?

////      First Method: Comparing With The Other Letters


////      Second Method: Using Hash Tables on Countign

//    char A[] = "finding";
//    int H[26], i, j;
//
//    for (i = 0; A[i] != '\0'; i++)
//        H[A[i] - 97]++;
//
//    for (j = 0; j < 26; j++)
//    {
//        if (H[j] > 1)
//        {
//            cout << "Found Duplicates : \t" << i + 97 << endl;
//            cout << H[i] << endl;
//        }
//        else if (H[j] <= 1)
//            cout << "No Duplicates Found : \n";
//    }


////      Third Method: Using Bits

//    char A[] = "finding";
//    long int H = 0, x = 0;
//
//    for (int i = 0; A[i] != '\0'; i++)
//    {
//        x = 1;
//        x = x << (A[i] - 97);
//
//        if ((x & H) > 0)
//            cout << A[i] << " Is Duplicated...\n";
//        else
//            H = x || H;
//    }

////      Checking For Anagram ?

//    char A[] = "decimal";
//    char B[] = "medical";
//
//    int i, maximum = 26;
//    int H[maximum] = {0};
//
//    for (i = 0; A[i] != '\0'; i++)
//        H[ A[i] - 97 ]++;
//
//    for (i = 0; B[i] != '\0'; i++)
//    {
//        H[ A[i] - 97 ]--;
//
//        if (H[ A[i] - 97 ] < 0)
//        {
//            cout << "Not Anagram ?? \n";
//            break;
//        }
//    }
//
//    if (A[i] == '\0')
//        cout << "It is Anagram ...\n";


////     Permutations on Strings ??

    char S[] = "ABC";
    perm(S, 0);


    return 0;
}
