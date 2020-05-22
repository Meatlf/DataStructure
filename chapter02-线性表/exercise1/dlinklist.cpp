#include <string.h>
#include "dlinklist.h"

void dlinklist::CreateListF(DLinkNode *&L, ElemType a[], int n)
{
    DLinkNode *s;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;

    for (size_t i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];

        s->next = L->next;
        if (L->next != NULL) // 这个条件容易忘记
            L->next->prior = s;

        L->next = s;
        s->prior = L;
    }
}

void dlinklist::CreateListR(DLinkNode *&L, ElemType a[], int n)
{
    DLinkNode *p, *s; // p始终指向链表的尾
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    p = L;

    for (size_t i = 0; i < n; i++)
    {
        s = (DLinkNode *)malloc(sizeof(DLinkNode));
        s->data = a[i];
        p->next = s;
        s->prior = p;
        p = s;
    }
    p->next = NULL;
}

void dlinklist::InitalList(DLinkNode *&L)
{
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;
}

bool dlinklist::InsertList(DLinkNode *&L, int i, ElemType e)
{
    int j = 0;
    DLinkNode *p = L;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;

    DLinkNode *s = (DLinkNode *)malloc(sizeof(DLinkNode));

    s->data = e;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}

void dlinklist::PrintList(DLinkNode *L)
{
    DLinkNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool dlinklist::GetElementViaLocation(DLinkNode *L, int location, ElemType &element)
{
    if (L == NULL || location < 1)
        return false;

    DLinkNode *p = L;
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

int dlinklist::GetLocationViaElement(DLinkNode *L, ElemType element)
{
    int i = 1;
    DLinkNode *p = L->next;

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

bool dlinklist::IsNullList(DLinkNode *L)
{
    return L->next == NULL;
}

int dlinklist::ListLength(DLinkNode *L)
{
    int n = 0;
    DLinkNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}

bool dlinklist::InsertElementInList(DLinkNode *&L, int location, ElemType element)
{
    int i = 0;
    DLinkNode *p = L;

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
        DLinkNode *newNode = (DLinkNode *)malloc(sizeof(DLinkNode));
        newNode->data = element;
        newNode->next = p->next;
        p->next = newNode;
        return true;
    }
}

bool dlinklist::DeleteElementInList(DLinkNode *&L, int i, ElemType &element)
{
    int j = 0;
    DLinkNode *p = L, *q;

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
        if(p->next!=NULL)
            p->next->prior = p;
        free(q);
        return true;
    }
}

void dlinklist::FreeList(DLinkNode *&L)
{
    DLinkNode *pre = L, *p = L->next;

    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}