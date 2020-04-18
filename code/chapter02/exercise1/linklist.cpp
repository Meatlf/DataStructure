#include <string.h>
#include "linklist.h"

// void linklist::CreateList(SqList *&L, ElemType a[], int n)
// {
//     L = (SqList *)malloc(sizeof(SqList));
//     if (a != nullptr && n > 0)
//     {
//         for (int i = 0; i < n; i++)
//             L->data[i] = a[i];
//         L->length = n;
//     }
// }

void linklist::InitalList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void linklist::InsertList(LinkNode *&L, ElemType e)
{
    LinkNode *headNode = L;
    while (L->next != NULL)
    {
        L = L->next;
    }

    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));

    newNode->data = e;
    L->next = newNode;
    L = headNode;
}

void linklist::PrintList(LinkNode *&L)
{
    LinkNode *headNode = L;
    while (L != NULL)
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
    L = headNode;
}

bool linklist::GetElementViaLocation(LinkNode *&L, int location, ElemType &element)
{
    if (L == NULL || location < 1)
        return false;
    LinkNode *headNode = L;
    int i = 0;
    while (i < location && L->next != NULL)
    {
        L = L->next;
        i++;
    }
    element = L->data;
    L = headNode;
    return true;
}

int linklist::GetLocationViaElement(LinkNode *&L, ElemType element)
{
    int i = 0;
    LinkNode *headNode = L;

    while (L != NULL)
    {
        if (L->data - element == 0)
        {
            L = headNode;
            return i;
        }
        L = L->next;
        i++;
    }
    L = headNode;
    return 0;
}

bool linklist::IsNullList(LinkNode *&L)
{
    return L->next == NULL;
}

int linklist::ListLength(LinkNode *&L)
{
    int i = 0;
    LinkNode *headNode = L;
    while (L->next != NULL)
    {
        L = L->next;
        i++;
    }
    L = headNode;
    return i;
}

bool linklist::InsertElementInList(LinkNode *&L, int location, ElemType element)
{
    if (L == NULL || L->next == NULL || location < 1)
        return false;

    int i = 0;
    LinkNode *headNode = L;

    while (L != NULL)
    {
        i++;
        if (i == location)
        {
            LinkNode *p0 = L->next;
            LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
            L->next = newNode;
            newNode->data = element;
            newNode->next = p0;
            L = headNode;
            return true;
        }
        L = L->next;
    }
    L = headNode;
    return false;
}

bool linklist::DeleteElementInList(LinkNode *&L, int location)
{
    if (L == NULL || L->next == NULL || location < 1)
        return false;

    int i = 0;
    LinkNode *headNode = L;

    while (L != NULL)
    {
        i++;
        if (i == location)
        {
            L->next = L->next->next;
            L = headNode;
            return true;
        }
        L = L->next;
    }
    L = headNode;
    return false;
}

void linklist::FreeList(LinkNode *&L)
{
    free(L);
}