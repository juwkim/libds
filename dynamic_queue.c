/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_queue.h"

void InitQueue(DQueue* pqueue)
{
	pqueue->front = pqueue->rear = NULL;
}

bool IsEmpty(DQueue* pqueue)
{
	return pqueue->front == NULL;
}

Data Peek(DQueue* pqueue)
{
	if (IsEmpty(pqueue))
		exit(EXIT_FAILURE);
	return pqueue->front->item;
}

void EnQueue(DQueue* pqueue, Data item)
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	if (newNode == NULL)
		exit(EXIT_FAILURE);

	newNode->item = item;
	if (IsEmpty(pqueue))
	{
		pqueue->front = newNode;
		pqueue->rear = newNode;
	}
	else
	{
		pqueue->rear->next = newNode;
		pqueue->rear = newNode;
	}
}

void DeQueue(DQueue* pqueue)
{
	if (IsEmpty(pqueue))
		exit(EXIT_FAILURE);

	Node* temp = pqueue->front;
	if (temp->next == NULL)
	{
		pqueue->front = NULL;
		pqueue->rear = NULL;
	}
	else
		pqueue->front = temp->next;
	free(temp);
}
