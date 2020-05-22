#ifndef DLINKLIST_H_
#define DLINKLIST_H_

#include <iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

typedef struct DLNode
{
    ElemType data;        // 存放元素值
    struct DLNode *prior; // 指向前驱结点
    struct DLNode *next;  // 指向后继结点
} DLinkNode;              // 双链表结点类型

namespace dlinklist
{
    // 建立单链表
    // 头插法
    // // O(n)
    void CreateListF(DLinkNode *&L, ElemType a[], int n);

    // 建立单链表
    // 尾插法
    // // O(n)
    void CreateListR(DLinkNode *&L, ElemType a[], int n);

    // O(1)
    void InitalList(DLinkNode *&L);

    // 尾插法
    // O(n)
    bool InsertList(DLinkNode *&L, int i, ElemType a);

    // O(n)
    void PrintList(DLinkNode *L);

    // O(n)
    bool GetElementViaLocation(DLinkNode *L, int location, ElemType &element);

    // O(n)
    int GetLocationViaElement(DLinkNode *L, ElemType element);

    // O(1)
    bool IsNullList(DLinkNode *L);

    // O(n)
    int ListLength(DLinkNode *L);

    // O(n)
    bool InsertElementInList(DLinkNode *&L, int location, ElemType element);

    // O(n)
    bool DeleteElementInList(DLinkNode *&L, int location, ElemType &element);

    // O(n)
    void FreeList(DLinkNode *&L);
} // namespace dlinklist
#endif