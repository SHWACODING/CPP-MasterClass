#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//// Implementation Of Stack Using Array ?????

//struct Stack
//{
//    int sz;
//    int Top;
//    int *S;
//};
//
//void Create(struct Stack *st)
//{
//    printf("Enter Stack's Array Size : ");
//    scanf("%d", &st->sz);
//    st->Top = -1;
//    st->S = (int *)malloc(st->sz * sizeof(int));
//}
//
//void Display (struct Stack st)
//{
//    for (int i = st.Top; i >= 0; --i)
//        printf("%d ", st.S[i]);
//    printf("\n");
//}
//
//void Push (struct Stack *st, int x)
//{
//    if (st->Top == st->sz-1)
//        printf("Stack Overflow ??? \n");
//    else
//    {
//        st->Top++;
//        st->S[st->Top] = x;
//    }
//}
//
//int Pop (struct Stack *st)
//{
//    int x = -1;
//
//    if (st->Top == -1)
//        printf("Stack Underflow ??? \n");
//    else
//        x = st->S[st->Top--];
//
//    return x;
//}
//
//
//int Peek (struct Stack st, int index)
//{
//    int x = -1;
//    if (st.Top - index + 1 < 0)
//        printf("Invalid Index ??? \n");
//    x = st.S[st.Top - index + 1];
//    return x;
//}
//
//int IsEmpty (struct Stack st)
//{
//    if (st.Top == -1)
//        return 1;
//    return 0;
//}
//
//int IsFull (struct Stack st)
//{
////    if (st.Top = st.sz - 1)
////        return 1;
////    return 0;
//
//    // ===========>
//
//    return st.Top == st.sz - 1;
//}
//
//int StackTop (struct Stack st)
//{
//    if (!IsEmpty(st))
//        return st.S[st.Top];
//    return -1;
//}
//
//
//
//int main ()
//{
//    struct Stack st;
//
//    Create(&st);
//    Push(&st, 10);
//    Push(&st, 20);
//    Push(&st, 30);
//    Push(&st, 40);
//    Push(&st, 50);
//
//    printf("Deleted Element Is : %d \n" ,Pop(&st));
//
//    printf("Getting The Peek Element At A Given Index : %d \n" ,Peek(st, 1));
//
//    printf ("The Stack Top Element Is : %d \n", StackTop(st));
//
//    printf("\n");
//    Display(st);
//    printf("\n");
//
//    if (IsEmpty(st))
//        printf("Stack Is Empty Now ????\n");
//    else
//        printf("Stack Containing Data Now ???\n");
//
//    if (IsFull(st))
//        printf("Stack Is Full Now ????\n");
//    else
//        printf("Stack Containing Data Now Or Empty ???\n");
//
//    return 0;
//}

//----------------------------------------------------------------------------------------------------

//// Implementation Of Stack Using Linked List ?????

//struct Node
//{
//    int data;
//    struct Node *next;
//}*Top=NULL;
//
//void Display ()
//{
//    struct Node *p;
//    p = Top;
//    while (p)
//    {
//        printf ("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//void Push (int x)
//{
//    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
//    if (t == NULL)
//        printf ("Stack Overflow ??? \n");
//    else
//    {
//        t->data = x;
//        t->next = Top;
//        Top = t;
//    }
//}
//
//int Pop ()
//{
//    struct Node *t;
//    int x = -1;
//
//    if (Top == NULL)
//        printf ("Stack Is Empty ???\n");
//    else
//    {
//        t = Top;
//        Top = Top->next;
//        x = t->data;
//        free(t);
//    }
//    return x;
//}
//
//int Peek (int index)
//{
//    int x = -1;
//    struct Node *p = Top;
//
//    for (int i = 0; p && i < index - 1; ++i)
//        p = p->next;
//
//    if (p != NULL)
//        return p->data;
//    return -1;
//}
//
//int IsEmpty ()
//{
//    return Top == NULL ? 1 : 0;
//}
//
//int IsFull ()
//{
//    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
//
//    return t == NULL ? 1 : 0;
//}
//
//int StackTop ()
//{
//    if (!IsEmpty())
//        return Top->data;
//    return -1;
//}
//
//
//
//int main ()
//{
//
//    Push(10);
//    Push(20);
//    Push(30);
//    Push(40);
//    Push(50);
//
//    printf("Deleted Element : %d \n", Pop());
//    printf("Getting The Peek Element At A Given Index : %d \n" ,Peek(4));
//    printf ("The Stack Top Element Is : %d \n", StackTop());
//
//    printf("\n");
//    Display();
//    printf("\n");
//
//    if (IsEmpty())
//        printf("Stack Is Empty Now ????\n");
//    else
//        printf("Stack Containing Data Now ???\n");
//
//    if (IsFull())
//        printf("Stack Is Full Now ????\n");
//    else
//        printf("Stack Containing Data Now Or Empty ???\n");
//
//    return 0;
//}

//----------------------------------------------------------------------------------------------------

//// Balanced Parenthesis Matching Via Stack Using Array ??

//struct Stack
//{
//    int sz;
//    int Top;
//    char *S;
//};
//
//void Create(struct Stack *st)
//{
//    printf("Enter Stack's Array Size : ");
//    scanf("%d", &st->sz);
//    st->Top = 0;
//    st->S = (char *)malloc(st->sz * sizeof(char));
//}
//
//void Display (struct Stack st)
//{
//    for (int i = st.Top; i >= 0; --i)
//        printf("%d ", st.S[i]);
//    printf("\n");
//}
//
//void Push (struct Stack *st, char x)
//{
//    if (st->Top == st->sz-1)
//        printf("Stack Overflow ??? \n");
//    else
//    {
//        st->Top++;
//        st->S[st->Top] = x;
//    }
//}
//
//char Pop (struct Stack *st)
//{
//    char x = -1;
//
//    if (st->Top == -1)
//        printf("Stack Underflow ??? \n");
//    else
//        x = st->S[st->Top--];
//
//    return x;
//}
//
//int IsBalanced (struct Stack stk, char *exp)
//{
//    for (int i = 0; exp[i] != '\0'; ++i)
//    {
//        if (exp[i] == '(')
//                Push(&stk, exp[i]);
//        else if (exp[i] == ')')
//        {
//            if (stk.Top == 0)
//                return 0;
//            else
//                Pop(&stk);
//        }
//    }
//    if (stk.Top == 0)
//        return 1;
//    else
//        return 0;
//}
//
//
//int main ()
//{
//    char *exp = "((a+b)*(c-d))";
//
//    struct Stack stk;
//
//    Create(&stk);
//
//    if (IsBalanced(stk, exp))
//        printf("The Parenthesis Matching Is Balanced ?? \n");
//    else
//        printf("The Parenthesis Matching Is Not Balanced ?? \n");
//
//    return 0;
//}

//----------------------------------------------------------------------------------------------------

//// Balanced Parenthesis Matching Via Stack Using Linked List ??

//struct Node
//{
//    char data;
//    struct Node *next;
//}*Top=NULL;
//
//void Display ()
//{
//    struct Node *p;
//    p = Top;
//    while (p)
//    {
//        printf ("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//void Push (char x)
//{
//    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
//    if (t == NULL)
//        printf ("Stack Overflow ??? \n");
//    else
//    {
//        t->data = x;
//        t->next = Top;
//        Top = t;
//    }
//}
//
//char Pop ()
//{
//    struct Node *t;
//    char x = -1;
//
//    if (Top == NULL)
//        printf ("Stack Is Empty ???\n");
//    else
//    {
//        t = Top;
//        Top = Top->next;
//        x = t->data;
//        free(t);
//    }
//    return x;
//}
//
//int IsBalanced (char *exp)
//{
//    for (int i = 0; exp[i] != '\0'; ++i)
//    {
//        if (exp[i] == '(')
//                Push(exp[i]);
//        else if (exp[i] == ')')
//        {
//            if (Top == NULL)
//                return 0;
//            else
//                Pop();
//        }
//    }
//    if (Top == NULL)
//        return 1;
//    else
//        return 0;
//}
//
//
//int main ()
//{
//    char *exp = "((a+b)*(c-d))";
//
//    if (IsBalanced(exp))
//        printf("The Parenthesis Matching Is Balanced ?? \n");
//    else
//        printf("The Parenthesis Matching Is Not Balanced ?? \n");
//
//    return 0;
//}

//----------------------------------------------------------------------------------------------------

//// Infix To Postfix Conversion Using Linked List ??

//struct Node
//{
//    char data;
//    struct Node *next;
//}*Top=NULL;
//
//void Display ()
//{
//    struct Node *p;
//    p = Top;
//    while (p)
//    {
//        printf ("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//void Push (char x)
//{
//    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
//    if (t == NULL)
//        printf ("Stack Overflow ??? \n");
//    else
//    {
//        t->data = x;
//        t->next = Top;
//        Top = t;
//    }
//}
//
//char Pop ()
//{
//    struct Node *t;
//    char x = -1;
//
//    if (Top == NULL)
//        printf ("Stack Is Empty ???\n");
//    else
//    {
//        t = Top;
//        Top = Top->next;
//        x = t->data;
//        free(t);
//    }
//    return x;
//}
//
//int IsBalanced (char *exp)
//{
//    for (int i = 0; exp[i] != '\0'; ++i)
//    {
//        if (exp[i] == '(')
//                Push(exp[i]);
//        else if (exp[i] == ')')
//        {
//            if (Top == NULL)
//                return 0;
//            else
//                Pop();
//        }
//    }
//    if (Top == NULL)
//        return 1;
//    else
//        return 0;
//}
//
//int IsOperand (char x)
//{
//    if (x == '+' || x == '-' || x == '*' || x == '/')
//        return 0;
//    else
//        return 1;
//}
//
//int Precedence (char x)
//{
//    if (x == '+' || x == '-')
//        return 1;
//    else if (x == '*' || x == '/')
//        return 2;
//    else
//        return 0;
//}
//
//char * InfixToPostfix (char *infix)
//{
//    int i = 0, j = 0;
//
//    char *postfix;
//    int len = strlen(infix);
//
//    postfix = (char *)malloc((len+2) * sizeof(char));
//
//    while (infix[i] != '\0')
//    {
//        if (IsOperand(infix[i]))
//            postfix[j++] = infix[i++];
//        else
//        {
//            if (Precedence(infix[i]) > Precedence(Top->data))
//                Push(infix[i++]);
//            else
//            {
//                postfix[j++] = Pop();
//            }
//        }
//    }
//
//    while (Top != NULL)
//        postfix[j++] = Pop();
//    postfix[j] = '\0';
//
//    return postfix;
//}

//int main ()
//{
//    char *infix = "a+b*c-d/e";
//
//    Push('#');
//
//    char *postfix = InfixToPostfix(infix);
//
//    printf("%s ", postfix);
//
//    return 0;
//}

//----------------------------------------------------------------------------------------------------

//// Evaluation Of Postfix ??

struct Node
{
    int data;
    struct Node *next;
}*Top=NULL;

void Display ()
{
    struct Node *p;
    p = Top;
    while (p)
    {
        printf ("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Push (int x)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL)
        printf ("Stack Overflow ??? \n");
    else
    {
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

int Pop ()
{
    struct Node *t;
    int x = -1;

    if (Top == NULL)
        printf ("Stack Is Empty ???\n");
    else
    {
        t = Top;
        Top = Top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int IsBalanced (char *exp)
{
    for (int i = 0; exp[i] != '\0'; ++i)
    {
        if (exp[i] == '(')
                Push(exp[i]);
        else if (exp[i] == ')')
        {
            if (Top == NULL)
                return 0;
            else
                Pop();
        }
    }
    if (Top == NULL)
        return 1;
    else
        return 0;
}

int IsOperand (char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int Precedence (char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

char * InfixToPostfix (char *infix)
{
    int i = 0, j = 0;

    char *postfix;
    int len = strlen(infix);

    postfix = (char *)malloc((len+2) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (IsOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (Precedence(infix[i]) > Precedence(Top->data))
                Push(infix[i++]);
            else
            {
                postfix[j++] = Pop();
            }
        }
    }

    while (Top != NULL)
        postfix[j++] = Pop();
    postfix[j] = '\0';

    return postfix;
}

int EvaluationOfPostfix (char *postfix)
{
    int x1, x2, res = 0;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (IsOperand(postfix[i]))
            Push(postfix[i] - '0');
        else
        {
            x2 = Pop();
            x1 = Pop();
            switch (postfix[i])
            {
                case '+': res = x1 + x2; break;
                case '-': res = x1 - x2; break;
                case '*': res = x1 * x2; break;
                case '/': res = x1 / x2; break;
            }
            Push(res);
        }
    }
    return Top->data;
}


int main ()
{
    char *postfix = "234*+82/-";

    printf ("Result Is : %d \n", EvaluationOfPostfix(postfix));

    return 0;
}
