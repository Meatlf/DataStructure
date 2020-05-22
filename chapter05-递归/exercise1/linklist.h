#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

typedef struct LNode
{
    ElemType data;      // 存放元素值
    struct LNode *next; // 指向后继结点
} LinkNode;             // 单链表结点类型

namespace linklist
{
// 建立单链表
// 头插法
// // O(n)
void CreateListF(LinkNode *&L, ElemType a[], int n);

// 建立单链表
// 尾插法
// // O(n)
void CreateListR(LinkNode *&L, ElemType a[], int n);

// O(1)
void InitalList(LinkNode *&L);

// 尾插法
// O(n)
void InsertList(LinkNode *&L, ElemType a);

// O(n)
void PrintList(LinkNode *L);

// O(n)
bool GetElementViaLocation(LinkNode *L, int location, ElemType &element);

// O(n)
int GetLocationViaElement(LinkNode *L, ElemType element);

// O(1)
bool IsNullList(LinkNode *L);

// O(n)
int ListLength(LinkNode *L);

// O(n)
bool InsertElementInList(LinkNode *&L, int location, ElemType element);

// O(n)
bool DeleteElementInList(LinkNode *&L, int location, ElemType &element);

// O(n)
void FreeList(LinkNode *&L);
} // namespace linklist
#endif