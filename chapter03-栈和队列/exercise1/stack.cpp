#include <iostream>
#include "stack.h"

using namespace std;

void sqstack::InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}

void sqstack::DestoryStack(SqStack *&s)
{
    free(s);
}

bool sqstack::StackEmpty(SqStack *s)
{
    return (s->top == -1);
}

bool sqstack::Push(SqStack *&s, ElemType e)
{
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool sqstack::Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s, ElemType &e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}