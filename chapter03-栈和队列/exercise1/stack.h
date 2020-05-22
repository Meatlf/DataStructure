#ifndef SQSTACK_H_
#define SQSTACK_H_

#include <iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

typedef struct 
{
    ElemType data[MaxSize];
    int top;
} SqStack;

// 这6个算法的算法复杂度都是O(1)
namespace sqstack
{
void InitStack(SqStack *&s);

void DestoryStack(SqStack *&s);

bool StackEmpty(SqStack *s);

bool Push(SqStack *&s, ElemType e);

bool Pop(SqStack *&s, ElemType &e);

bool GetTop(SqStack *s, ElemType &e);

} // namespace sqstack
#endif