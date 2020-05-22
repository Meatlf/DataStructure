#ifndef CDLINKLIST_H_
#define CDLINKLIST_H_

#include <iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

typedef struct CDLNode
{
    ElemType data;        // 存放元素值
    struct CDLNode *prior; // 指向前驱结点
    struct CDLNode *next;  // 指向后继结点
} CDLinkNode;              // 双链表结点类型

namespace cdlinklist
{
    // 建立单链表
    // 头插法
    // // O(n)
    void CreateListF(CDLinkNode *&L, ElemType a[], int n);

    // 建立单链表
    // 尾插法
    // // O(n)
    void CreateListR(CDLinkNode *&L, ElemType a[], int n);

    // O(1)
    void InitalList(CDLinkNode *&L);

    // 尾插法
    // O(n)
    bool InsertList(CDLinkNode *&L, int i, ElemType a);

    // O(n)
    void PrintList(CDLinkNode *L);

    // O(n)
    bool GetElementViaLocation(CDLinkNode *L, int location, ElemType &element);

    // O(n)
    int GetLocationViaElement(CDLinkNode *L, ElemType element);

    // O(1)
    bool IsNullList(CDLinkNode *L);

    // O(n)
    int ListLength(CDLinkNode *L);

    // O(n)
    bool InsertElementInList(CDLinkNode *&L, int location, ElemType element);

    // O(n)
    bool DeleteElementInList(CDLinkNode *&L, int location, ElemType &element);

    // O(n)
    void FreeList(CDLinkNode *&L);
} // namespace cdlinklist
#endif