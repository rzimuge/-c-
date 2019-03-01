#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char TElemType;/*The Tree Type*/
typedef struct BiTNode
{
	TElemType data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef BiTree StackType;/*The Stack Type*/


typedef struct stack
{
	StackType sdata;
	stack *back;
}*Stack;
typedef struct StackTop {
	Stack top;
}StackTop;

