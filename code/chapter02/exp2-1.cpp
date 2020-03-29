#include<iostream>
#include"sqlist.h"

using namespace std;

int main()
{
    SqList* L = (SqList*)malloc(sizeof(SqList));
    
    cout<<"sizeof(SqList) = "<<sizeof(SqList)<<endl;
    InitalList(L);
    InsertList(L,'a');
    InsertList(L,'b');
    InsertList(L,'c');
    InsertList(L,'d');
    InsertList(L,'e');
    PrintList(L);
    if(isNullList(L)==true)
        cout<<"该链表是空链表!"<<endl;
    else
        cout<<"该链表不是空链表!"<<endl;        
    
    return 0;
}