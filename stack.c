/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void InitStack(stack* pstack)
{
	pstack->top = -1;
}

bool IsFull(stack* pstack)
{
	return pstack->top == STACK_SIZE - 1;
}

bool IsEmpty(stack* pstack)
{
	return pstack->top == -1;
}

Data Peek(stack* pstack)
{
	if (IsEmpty(pstack))
		exit(EXIT_FAILURE); //error: empty stack
	return pstack->items[pstack->top];
}

void Push(stack* pstack, Data item)
{
	if (IsFull(pstack))
		exit(EXIT_FAILURE); //error: stack full
	pstack->items[++(pstack->top)] = item;
}

void Pop(stack* pstack)
{
	if (IsEmpty(pstack))
		exit(EXIT_FAILURE); //error: empty stack
	pstack->top--;
}

void ReversePrint(char* s, int len)
{
	stack stack;
	char ch;

	InitStack(&stack); // Make a stack empty.
	for (int i = 0; i < len; i++)
		Push(&stack, s[i]);

	// Pop characters.
	while (!IsEmpty(&stack))
	{
		ch = Peek(&stack);
		printf("%c", ch);
		Pop(&stack);
	}
}
