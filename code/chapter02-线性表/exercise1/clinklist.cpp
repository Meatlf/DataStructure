#include <string.h>
#include "clinklist.h"

void clinklist::CreateListF(CLinkNode *&L, ElemType a[], int n)
{
    CLinkNode *s;
    L = (CLinkNode *)malloc(sizeof(CLinkNode));
    L->prior = L->next = NULL;

    CLinkNode *p;

    if (n > 0)
    {
        s = (CLinkNode *)malloc(sizeof(CLinkNode));
        s->data = a[0];

        p = s;
        L->next = p;
        p->prior = L;
    }

    for (size_t i = 1; i < n; i++)
    {
        s = (CLinkNode *)malloc(sizeof(CLinkNode));
        s->data = a[i];

        s->next = L->next;
        if (L->next != NULL) // 这个条件容易忘记
            L->next->prior = s;

        L->next = s;
        s->prior = L;
    }
}

void clinklist::CreateListR(CLinkNode *&L, ElemType a[], int n)
{
    CLinkNode *p, *s; // p始终指向链表的尾
    L = (CLinkNode *)malloc(sizeof(CLinkNode));
    p = L;

    for (size_t i = 0; i < n; i++)
    {
        s = (CLinkNode *)malloc(sizeof(CLinkNode));
        s->data = a[i];
        p->next = s;
        s->prior = p;
        p = s;
    }
    L->prior = p;
    p->next = L;
}

void clinklist::InitalList(CLinkNode *&L)
{
    L = (CLinkNode *)malloc(sizeof(CLinkNode));
    L->prior = L->next = NULL;
}

bool clinklist::InsertList(CLinkNode *&L, int i, ElemType e)
{
    int j = 0;
    CLinkNode *p = L;
    if (i <= 0)
        return false;
        
    while (j < i - 1 && p != NULL)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;

    CLinkNode *s = (CLinkNode *)malloc(sizeof(CLinkNode));

    s->data = e;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}

void clinklist::PrintList(CLinkNode *L)
{
    CLinkNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool clinklist::GetElementViaLocation(CLinkNode *L, int location, ElemType &element)
{
    if (L == NULL || location < 1)
        return false;

    CLinkNode *p = L;
    int i = 0;
    while (i < location && p->next != NULL)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
        return false;
    else
    {
        element = p->data;
        return true;
    }
}

int clinklist::GetLocationViaElement(CLinkNode *L, ElemType element)
{
    int i = 1;
    CLinkNode *p = L->next;

    while (p != NULL && p->data != element)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return 0;
    else
        return i;
}

bool clinklist::IsNullList(CLinkNode *L)
{
    return L->next == NULL;
}

int clinklist::ListLength(CLinkNode *L)
{
    int n = 0;
    CLinkNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}

bool clinklist::InsertElementInList(CLinkNode *&L, int location, ElemType element)
{
    int i = 0;
    CLinkNode *p = L;

    if (location < 1)
        return false;

    while (i < location - 1 && p != NULL)
    {
        i++;
        p = p->next;
    }

    if (p == NULL)
        return false;
    else
    {
        CLinkNode *newNode = (CLinkNode *)malloc(sizeof(CLinkNode));
        newNode->data = element;
        newNode->next = p->next;
        p->next = newNode;
        return true;
    }
}

bool clinklist::DeleteElementInList(CLinkNode *&L, int i, ElemType &element)
{
    int j = 0;
    CLinkNode *p = L, *q;

    if (i < 1)
        return false;

    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }

    if (p == NULL)
        return false;
    else
    {
        q = p->next;
        if (q == NULL)
            return false;
        element = q->data;
        p->next = q->next;
        if (p->next != NULL)
            p->next->prior = p;
        else
        {
            p->next->prior = L;
        }

        free(q);
        return true;
    }
}

void clinklist::FreeList(CLinkNode *&L)
{
    CLinkNode *pre = L, *p = L->next;

    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}