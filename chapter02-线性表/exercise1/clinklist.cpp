#include <string.h>
#include "clinklist.h"

void clinklist::CreateListF(CLinkNode *&L, ElemType a[], int n)
{
    CLinkNode *s;
    L = (CLinkNode *)malloc(sizeof(CLinkNode));
    L->next = NULL;

    if (n > 1)
    {
        s = (CLinkNode *)malloc(sizeof(CLinkNode));
        s->data = a[0];

        L->next = s;
        s->next = L;
    }

    for (size_t i = 1; i < n; i++)
    {
        s = (CLinkNode *)malloc(sizeof(CLinkNode));
        s->data = a[i];

        s->next = L->next;
        L->next = s;
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
        p = s;
    }
    p->next = L;
}

void clinklist::InitalList(CLinkNode *&L)
{
    L = (CLinkNode *)malloc(sizeof(CLinkNode));
    L->next = NULL;
}

void clinklist::InsertList(CLinkNode *&L, ElemType e)
{
    CLinkNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }

    CLinkNode *s = (CLinkNode *)malloc(sizeof(CLinkNode));

    s->data = e;
    p->next = s;
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

bool clinklist::GetElementViaLocation(CLinkNode *L, int i, ElemType &e)
{
    if (L == NULL || i < 1)
        return false;

    CLinkNode *p = L;
    int j = 0;
    while (j < i && p->next != NULL)
    {
        p = p->next;
        j++;
    }

    if (p == NULL)
        return false;
    else
    {
        e = L->data;
        return true;
    }
}

int clinklist::GetLocationViaElement(CLinkNode *L, ElemType e)
{
    int j = 1;
    CLinkNode *p = L->next;

    while (p != NULL && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return 0;
    else
        return j;
}

bool clinklist::IsNullList(CLinkNode *L)
{
    return L->next == NULL;
}

int clinklist::ListLength(CLinkNode *L)
{
    int n = 0;
    CLinkNode *p = L;
    while (p->next != L)
    {
        p = p->next;
        n++;
    }
    return n;
}

bool clinklist::InsertElementInList(CLinkNode *&L, int i, ElemType e)
{
    int j = 0;
    CLinkNode *p = L;

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
        CLinkNode *s = (CLinkNode *)malloc(sizeof(CLinkNode));
        s->data = e;

        s->next = p->next;
        p->next = s;
        return true;
    }
}

bool clinklist::DeleteElementInList(CLinkNode *&L, int i, ElemType &e)
{
    int j = 0;
    CLinkNode *p = L, *q;

    if (i < 1)
        return false;

    // 查找第i-1个结点
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
        e = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}

void clinklist::FreeList(CLinkNode *&L)
{
    CLinkNode *pre = L, *p = L->next;

    while (p != L)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}