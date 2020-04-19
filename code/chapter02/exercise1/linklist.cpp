#include <string.h>
#include "linklist.h"

void linklist::CreateListF(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;

    for (size_t i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

void linklist::CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *p,*s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    p = L;

    for (size_t i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        p->next = s;
        p = s;
    }
    p->next = NULL;
}

void linklist::InitalList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void linklist::InsertList(LinkNode *&L, ElemType e)
{
    LinkNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }

    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));

    newNode->data = e;
    p->next = newNode;
}

void linklist::PrintList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool linklist::GetElementViaLocation(LinkNode *L, int location, ElemType &element)
{
    if (L == NULL || location < 1)
        return false;

    LinkNode *p = L;
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
        element = L->data;
        return true;
    }
}

int linklist::GetLocationViaElement(LinkNode *L, ElemType element)
{
    int i = 1;
    LinkNode *p = L->next;

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

bool linklist::IsNullList(LinkNode *L)
{
    return L->next == NULL;
}

int linklist::ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}

bool linklist::InsertElementInList(LinkNode *&L, int location, ElemType element)
{
    int i = 0;
    LinkNode *p = L;

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
        LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
        newNode->data = element;
        newNode->next = p->next;
        p->next = newNode;
        return true;
    }
}

bool linklist::DeleteElementInList(LinkNode *&L, int location, ElemType &element)
{
    int i = 0;
    LinkNode *p = L, *q;

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
        q = p->next;
        if (q == NULL)
            return false;
        element = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}

void linklist::FreeList(LinkNode *&L)
{
    LinkNode *pre = L, *p = L->next;

    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}