//
// Created by zg on 2020/8/1.
//

#ifndef UNTITLED_队列链式存储_H
#define UNTITLED_队列链式存储_H

#include <iostream>
#include <math.h>

#define MAXSIZE 40
#define OK 1
#define ERROR 0
typedef int Status ;
typedef int QElemType ;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front,rear;
}LinkQueue;


Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr  s = (QueuePtr)malloc(sizeof(QNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return OK;

}

Status DeQueue(LinkQueue *Q,QElemType *e)
{
    QueuePtr p;
    if (Q->front == Q->rear)
        return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return OK;
}



#endif //UNTITLED_队列链式存储_H
