#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100
#define ElemType int

typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

void InitList(SqList *L)
{
    L->length = 0;
}

bool ListInsert(SqList *L, int i, ElemType e)
{
    if(i<1 || i>L->length+1)
        return false;
    if(L->length>=MAXSIZE)
        return false;
    
    for(int j=L->length;j>=i;j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList *L, int i, ElemType *e)
{
    if(i<1 || i>L->length)
        return false;
    if(L->length == 0)
        return false;
    
    *e = L->data[i-1];
    for(int j = i;j<L->length;j++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return true;
}

bool GetElem(SqList L, int i, ElemType *e)
{
    if(i<1 || i>L.length)
        return false;
    if(L.length == 0)
        return false;

    *e = L.data[i-1];

    return true;
}

int LocateElem(SqList L, ElemType e)
{
    if(L.length == 0)
        return 0;
    for(int i=0;i<L.length;i++){
        if(L.data[i] == e)
            return i+1;
    }

    return 0;
}

void PrintList(SqList L)
{
    printf("The length of list is %d\nThe elements of list:\n", L.length);
    for(int i = 1; i <= L.length;i++)
        printf("%d\t",L.data[i-1]);
    printf("\n\n");
}

int main()
{
    bool result;
    ElemType temp;
    SqList L;
    InitList(&L);

    result = ListInsert(&L,1,1);
    result = ListInsert(&L,2,3);
    result = ListInsert(&L,3,5);
    result = ListInsert(&L,4,7);
    PrintList(L);

    result = ListDelete(&L,1,&temp);
    printf("Delete %d\n\n", temp);

    PrintList(L);

    result = GetElem(L,1,&temp);
    printf("Get element is %d\n\n",temp);

    int pos = LocateElem(L,5);
    printf("The position of the element is %d\n\n",pos);

    return 0;
}