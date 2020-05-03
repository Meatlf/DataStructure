#include <iostream>
#include "link_st_node.h"

using namespace std;

void linknodestack::InitStack(LinkStNode *&s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

void linknodestack::DestoryStack(LinkStNode *&s)
{
    LinkStNode *pre=s, *cur=s->next;
    while (cur!=NULL)
    {
        free(pre);
        pre = cur;
        cur = pre->next;
    }
    free(pre);
}

bool linknodestack::StackEmpty(LinkStNode *s)
{
    return s->next == NULL;
}

void linknodestack::Push(LinkStNode *&s, ElemType e)
{
    LinkStNode *p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;

    p->next = s->next;
    s->next = p;
}

bool linknodestack::Pop(LinkStNode *&s, ElemType &e)
{
    LinkStNode *p;
    if(s->next==NULL)
        return false;
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool GetTop(LinkStNode *s, ElemType &e)
{
    if(s->next==NULL)
        return false;
    e = s->next->data;
    return true;
}