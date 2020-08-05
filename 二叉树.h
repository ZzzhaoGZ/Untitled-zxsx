//
// Created by zg on 2020/8/4.
//

#ifndef UNTITLED_二叉树_H
#define UNTITLED_二叉树_H


#include <iostream>

#define maxSize 30
typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

void Visit(BTNode *p){}

void preorder(BTNode *p)
{
    if (p!=NULL)
    {
        Visit(p);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(BTNode *p)
{
    if (p!=NULL)
    {
        inorder(p->lchild);
        Visit(p);
        inorder(p->rchild);
    }
}

void postorder(BTNode *p)
{
    if (p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        Visit(p);
    }
}

int op(int A, int B,char C)
{
    if (C=='+')
        return A+B;
    if (C=='-')
        return A-B;
    if (C=='*')
        return A*B;
    if (C=='/')
        return A/B;
}

int comp(BTNode *p)
{
    int A,B;
    if (p!=NULL)
    {
        if (p->lchild!=NULL&&p->rchild!=NULL)
        {
            A = comp(p->lchild);
            B = comp(p->rchild);
            return op(A,B,p->data);
        } else
            return p->data-'0';
    } else return 0;
}

int getDepth(BTNode *p)
{
    int LD,RD;
    if (p==NULL)
    {
        return 0;
    } else{
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        return (LD>RD?LD:RD)+1;
    }
}

void search(BTNode *p,BTNode *&q,int key)
{
    if(p!=NULL)
    {
        if (p->data==key)
            q=p;
        else
        {
            search(p->lchild,q,key);
            search(p->rchild,q,key);
        }
    }
}

void search(BTNode *p,BTNode *&q,int key)
{
    if(p!=NULL)
    {
        if (p->data==key)
            q=p;
        else
        {
            search(p->lchild,q,key);
            if(q==NULL)
                search(p->rchild,q,key);
        }
    }
}

int n = 0;
void trave(BTNode *p,int k)
{
    if (p!=NULL)
    {
        ++n;
        if (k==n)
        {
            cout<<p->data<<endl;
            return;
        }
        trave(p->lchild,k);
        trave(p->rchild,k);
    }
}

//记忆
void level(BTNode *p)
{
    //层次遍历
    int front,rear;
    BTNode *que[maxSize];
    front = rear =0;
    BTNode *q;
    if(p!=NULL)
    {
        rear=(rear+1)%maxSize;
        que[rear]=p;
        while (front!=rear)
        {
            front=(front+1)%maxSize;
            q=que[front];
            Visit(q);
            if(q->lchild!=NULL){
                rear=(rear+1)%maxSize;
                que[rear]=q->lchild;
            }
            if(q->rchild!=NULL){
                rear=(rear+1)%maxSize;
                que[rear]=q->rchild;
            }
        }
    }
}

typedef struct
{
    BTNode *p;      //结点指针
    int lno;        //结点所在层次号
}St;
int maxNode(BTNode *b)
{
    St  que[maxSize];
    int front,rear;
    int Lno=0,i,j,n,max=0;
    front=rear=0;
    BTNode *q;
    if(b!=NULL)
    {
        ++rear;
        que[rear].p=b;
        que[rear].lno=1;
        while (front!=rear)
        {
            ++front;
            q=que[front].p;
            Lno=que[front].lno;  //Lno用来存储当前结点的层次号
            if(q->lchild!=NULL)
            {
                ++rear;
                que[rear].p=q->lchild;
                que[rear].lno=Lno+1;
            }
            if(q->rchild!=NULL)
            {
                ++rear;
                que[rear].p=q->rchild;
                que[rear].lno=Lno+1;
            }
        }//循环结束，Lno中保存的是这颗二叉树的最大层数
        //以下代码找出了含有结点最多的层中的结点数。
        max=0;
        for (i = 0; i <= Lno ; ++i) {
            n=0;
            for(j=0;j<rear;++j)
                if(que[j].lno==i)
                    ++n;
                if(max<n)
                    max=n;
        }
        return max;
    } else return 0; //空树直接访问0
}
#endif //UNTITLED_二叉树_H
