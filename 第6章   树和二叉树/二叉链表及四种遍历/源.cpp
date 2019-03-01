#include"stack.h"
#include"struct.h"
#define MAXSIZE 30

void get(TElemType *t)
{
	TElemType c;
	scanf_s("%c", &c);
	*t = c;
}
BiTree CreateTree(BiTree &T)//xian xu
{
	TElemType t = 0;
	get(&t);
	if (t == '#')
	{
		T = NULL;
	}
	else
	{

		if (!(T = (BiTNode *)malloc(sizeof(BiTNode) * 1))) return 0;
		T->data = t;
		T->lchild = CreateTree(T->lchild);
		T->rchild = CreateTree(T->rchild);

	}
	return T;
}

/*遍历(递归) */
void PreOrder(BiTree T, void(*Visit)(TElemType e))//先序(递归)
{
	if (T == NULL)
	{
	}
	else
	{
		Visit(T->data);
		PreOrder(T->lchild, Visit);
		PreOrder(T->rchild, Visit);
	}
}
void inOrder(BiTree T, void(*Visit)(TElemType e))//中序(递归)
{
	if (T == NULL)
	{
	}
	else
	{
		inOrder(T->lchild, Visit);
		Visit(T->data);
		inOrder(T->rchild, Visit);
	}
}
void PostOrder(BiTree T, void(*Visit)(TElemType e))//后序(递归)
{
	if (T == NULL)
	{
	}
	else
	{
		PostOrder(T->lchild, Visit);
		PostOrder(T->rchild, Visit);
		Visit(T->data);

	}
}

/*遍历(非递归)*/
void PreOrder2(BiTree T, void(*Visit)(TElemType e))//先序遍历(非递归)
{

	StackTop s;
	InitStack(&s);
	BiTree p = T;
	while (p || !StackEmpty(&s))
	{
		if (p)
		{
			push(&s, p);
			Visit(p->data);
			p = p->lchild;
		}
		else
		{
			pop(&s, &p);
			p = p->rchild;
		}
	}
}
void inOrder2(BiTree T, void(*Visit)(TElemType e))//中序遍历(非递归)
{
	StackTop s;
	InitStack(&s);
	BiTree p = T;
	while (p || !StackEmpty(&s))
	{
		if (p)
		{
			push(&s, p);
			p = p->lchild;
		}
		else
		{
			pop(&s, &p);
			Visit(p->data);
			p = p->rchild;
		}
	}
}

int cengxu(BiTree T, void(*Visit)(TElemType e))//层序遍历
{
	int front = 0;
	int rear = 0;
	BiTree BiQueue[MAXSIZE];
	BiTree tempNode;
	if (T)
	{
		BiQueue[rear++] = T;
		while (front != rear) 
		{
			//取出队头元素，并使队头指针向后移动一位　
			tempNode = BiQueue[front++];
			//判断左右子树是否为空,若不为空，则加入队列　
			if (tempNode->lchild)
				BiQueue[rear++] = tempNode->lchild;

			if (tempNode->rchild)
				BiQueue[rear++] = tempNode->rchild;
			
			Visit(tempNode->data);
		}
	}
	return 1;
}

void print(TElemType e)
{
	printf("%c ", e);
}
void printTree(BiTree T)
{
	printf("\n ");
	PreOrder(T, print); printf("\n ");
	inOrder(T, print); printf("\n ");
	PostOrder(T, print); printf("\n ");
	PreOrder2(T, print); printf("\n ");
	inOrder2(T, print); printf("\n ");
	cengxu(T, print); printf("\n");
}

int main()
{
	BiTree T = NULL;
	CreateTree(T);
	printTree(T);
	return 0;
}
//ABD##E##CB###
