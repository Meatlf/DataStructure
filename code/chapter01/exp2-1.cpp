#include"sqlist.h"

int main()
{
    Sqlist* L = (Sqlist*)malloc(sizeof(Sqlist));
    InitalList(L);
    InsertList(L,'a');
    PrintList(L);
}