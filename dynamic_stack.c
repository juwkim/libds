/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:05 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_stack.h"

void InitStack(DStack* pstack)
{
	pstack->top = NULL;
}

bool IsEmpty(DStack *pstack)
{
	return pstack->top == NULL;
}

Data Peek(DStack* pstack)
{
	if (IsEmpty(pstack))
		exit(EXIT_FAILURE);
	return pstack->top->item;
}

void Push(DStack* pstack, Data item)
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	if (newNode == NULL)
		exit(EXIT_FAILURE);
	newNode->item = item;
	newNode->next = pstack->top;
	pstack->top = newNode;
}

void Pop(DStack* pstack)
{
	if (IsEmpty(pstack))
		exit(EXIT_FAILURE);

	Node* temp = pstack->top;
	pstack->top = pstack->top->next;
	free(temp);
}
