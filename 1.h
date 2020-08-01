//
// Created by zg on 2020/8/1.
//

#ifndef UNTITLED_1_H
#define UNTITLED_1_H

#include <iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define  FALSE 0
#define MAXSIZE 20
typedef int Status ;
typedef int ElemType ;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

typedef struct Node
{
    ElemType data;
    struct Node * next;
}Node;

typedef Node * LinkList;

Status GetElem(SqList L,int i,ElemType *e)
{
    if (L.length==0||i<1||i>L.length)
        return ERROR;
    *e=L.data[i-1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length==MAXSIZE)
        return ERROR;
    if (i<1||i>L->length)
        return ERROR;
    if (i<=L->length)
    {
        for (k=L->length-1;k>=i-1;k--)
            L->data[k+1]=L->data[k];
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if (L->length==0)
        return ERROR;
    if (i<1||i>L->length-1)
        return ERROR;
    *e=L->data[i-1];
    if (i<L->length)
    {
        for (k=i;k<L->length;k++)
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}

Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;
    j = 1;
    while (p&&j<i)
    {
        p = p->next;
        ++j;
    }
    if (!p||j>i)
        return ERROR;
    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L,int i, ElemType e)
{
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    while (p&&j<i)
    {
        p = p->next;
        ++j;
    }
    if (!p||j>i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList *L,int i,ElemType *e)
{
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while (p->next&&j<i)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next)||j>i)
        return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

void CreateListHead(LinkList *L,int n)
{
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for (i = 0;i<n;i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail(LinkList *L, int n)
{
    LinkList p,r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (i = 0;i<n;i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

Status ClearList(LinkList *L)
{
    LinkList p,q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

#endif //UNTITLED_1_H
