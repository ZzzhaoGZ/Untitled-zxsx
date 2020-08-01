//
// Created by zg on 2020/8/1.
//

#ifndef UNTITLED_栈_H
#define UNTITLED_栈_H

#include <iostream>
#define MAXSIZE 100
#define ERROR 0
#define FALSE 0
#define OK 1
#define TRUE 1
typedef int SElemType ;
typedef int Status ;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;


Status Push(SqStack *S,SElemType e)
{
    if (S->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}

Status Push(SqStack *S,SElemType *e)
{
    if (S->top==-1)
        return ERROR;
    *e=S->data[S->top];
    S->top--;
    return OK;
}

Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

/*Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if (StackEmpty(*S))
        return ERROR;
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;

}*/




#endif //UNTITLED_栈_H
