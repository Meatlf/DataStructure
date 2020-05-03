#ifndef LINK_ST_NODE_H_
#define LINK_ST_NODE_H_

#include <iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

typedef struct linknode
{
    ElemType data;
    struct linknode *next;
} LinkStNode;

namespace linknodestack
{
// O(1)
void InitStack(LinkStNode *&s);

// O(n)
void DestoryStack(LinkStNode *&s);

// O(1)
bool StackEmpty(LinkStNode *s);

// O(1)
void Push(LinkStNode *&s, ElemType e);

// O(1)
bool Pop(LinkStNode *&s, ElemType &e);

// O(1)
bool GetTop(LinkStNode *s, ElemType &e);

} // namespace linknodestack
#endif