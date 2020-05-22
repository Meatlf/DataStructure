#ifndef CLINKLIST_H_
#define CLINKLIST_H_

#include <iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

typedef struct LNode
{
    ElemType data;      // 存放元素值
    struct LNode *next; // 指向后继结点
} CLinkNode;             // 单链表结点类型

namespace clinklist
{
// 建立单链表
// 头插法
// // O(n)
void CreateListF(CLinkNode *&L, ElemType a[], int n);

// 建立单链表
// 尾插法
// // O(n)
void CreateListR(CLinkNode *&L, ElemType a[], int n);

// O(1)
void InitalList(CLinkNode *&L);

// 尾插法
// O(n)
void InsertList(CLinkNode *&L, ElemType a);

// O(n)
void PrintList(CLinkNode *L);

// O(n)
bool GetElementViaLocation(CLinkNode *L, int location, ElemType &element);

// O(n)
int GetLocationViaElement(CLinkNode *L, ElemType element);

// O(1)
bool IsNullList(CLinkNode *L);

// O(n)
int ListLength(CLinkNode *L);

// O(n)
bool InsertElementInList(CLinkNode *&L, int location, ElemType element);

// O(n)
bool DeleteElementInList(CLinkNode *&L, int location, ElemType &element);

// O(n)
void FreeList(CLinkNode *&L);
} // namespace clinklist
#endif