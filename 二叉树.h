//
// Created by zg on 2020/8/4.
//

#ifndef UNTITLED_二叉树_H
#define UNTITLED_二叉树_H


#include <iostream>

typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

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
#endif //UNTITLED_二叉树_H
