#pragma once

#include"struct.h"
#define stack_init  100
#define stack_jia 10

void InitStack(StackTop *S)
{
	S->top = NULL;
}
int push(StackTop *s, StackType T)
{
	Stack p;
	p = (Stack)malloc(sizeof(stack));
	p->sdata = T;
	p->back = s->top;
	s->top = p;
	return 1;
}
int pop(StackTop *s, StackType *e)
{
	Stack p;
	p = (Stack)malloc(sizeof(stack));
	if (s->top == NULL) return 0;
	*e = s->top->sdata;
	p = s->top;
	s->top = p->back;
	free(p);
	return 1;
}
int DestoryStack(StackTop *s)
{
	if (s->top == NULL)
	{
		return 0;
	}
	else
	{
		Stack p, b;
		p = s->top;
		b = p->back;
		while (b != 0)
		{
			free(p);
			p = b;
			b = p->back;
		}
		free(p);
	}
}
int StackEmpty(StackTop *S)
{
	if (S->top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int stacksize(StackTop *s)
{
	Stack p;
	p = s->top;
	int i = 0;
	for (; p != NULL; i++)
	{
		p = p->back;
	}
	return i;
}
