#include <string.h>
#include "cdlinklist.h"

void cdlinklist::CreateListF(CDLinkNode *&L, ElemType a[], int n)
{
    CDLinkNode *s;
    L = (CDLinkNode *)malloc(sizeof(CDLinkNode));
    L->prior = L->next = NULL;

    CDLinkNode *p;

    if (n > 0)
    {
        s = (CDLinkNode *)malloc(sizeof(CDLinkNode));
        s->data = a[0];

        p = s;
        L->next = p;
        p->prior = L;
    }

    for (size_t i = 1; i < n; i++)
    {
        s = (CDLinkNode *)malloc(sizeof(CDLinkNode));
        s->data = a[i];

        s->next = L->next;
        if (L->next != NULL) // 这个条件容易忘记
            L->next->prior = s;

        L->next = s;
        s->prior = L;
    }
}

void cdlinklist::CreateListR(CDLinkNode *&L, ElemType a[], int n)
{
    CDLinkNode *p, *s; // p始终指向链表的尾
    L = (CDLinkNode *)malloc(sizeof(CDLinkNode));
    p = L;

    for (size_t i = 0; i < n; i++)
    {
        s = (CDLinkNode *)malloc(sizeof(CDLinkNode));
        s->data = a[i];
        p->next = s;
        s->prior = p;
        p = s;
    }
    L->prior = p;
    p->next = L;
}

void cdlinklist::InitalList(CDLinkNode *&L)
{
    L = (CDLinkNode *)malloc(sizeof(CDLinkNode));
    L->prior = L->next = NULL;
}

bool cdlinklist::InsertList(CDLinkNode *&L, int i, ElemType e)
{
    int j = 0;
    CDLinkNode *p = L;
    if (i <= 0)
        return false;
        
    while (j < i - 1 && p != NULL)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;

    CDLinkNode *s = (CDLinkNode *)malloc(sizeof(CDLinkNode));

    s->data = e;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}

void cdlinklist::PrintList(CDLinkNode *L)
{
    CDLinkNode *p = L->next;
    while (p->next != L)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool cdlinklist::GetElementViaLocation(CDLinkNode *L, int location, ElemType &element)
{
    if (L == NULL || location < 1)
        return false;

    CDLinkNode *p = L;
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

int cdlinklist::GetLocationViaElement(CDLinkNode *L, ElemType element)
{
    int i = 1;
    CDLinkNode *p = L->next;

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

bool cdlinklist::IsNullList(CDLinkNode *L)
{
    return L->next == NULL;
}

int cdlinklist::ListLength(CDLinkNode *L)
{
    int n = 0;
    CDLinkNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}

bool cdlinklist::InsertElementInList(CDLinkNode *&L, int location, ElemType element)
{
    int i = 0;
    CDLinkNode *p = L;

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
        CDLinkNode *newNode = (CDLinkNode *)malloc(sizeof(CDLinkNode));
        newNode->data = element;
        newNode->next = p->next;
        p->next = newNode;
        return true;
    }
}

bool cdlinklist::DeleteElementInList(CDLinkNode *&L, int i, ElemType &element)
{
    int j = 0;
    CDLinkNode *p = L, *q;

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

void cdlinklist::FreeList(CDLinkNode *&L)
{
    CDLinkNode *pre = L, *p = L->next;

    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}