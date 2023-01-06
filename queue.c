/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:40 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void InitQueue(Queue* pqueue)
{
	pqueue->front = 0;
	pqueue->rear = 0;
}

bool IsFull(Queue* pqueue)
{
	return pqueue->front == (pqueue->rear + 1) % QUEUE_SIZE;
}

bool IsQEmpty(Queue* pqueue)
{
	return pqueue->front == pqueue->rear;
}

Data QPeek(Queue* pqueue)
{
	if (IsQEmpty(pqueue))
		exit(EXIT_FAILURE); //error: empty stack
	return pqueue->items[pqueue->front];
}

void EnQueue(Queue* pqueue, Data item)
{
	if (IsFull(pqueue))
		exit(EXIT_FAILURE); //error: stack full
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % QUEUE_SIZE;
}

void DeQueue(Queue* pqueue)
{
	if (IsQEmpty(pqueue))
		exit(EXIT_FAILURE); //error: empty stack
	pqueue->front = (pqueue->front + 1) % QUEUE_SIZE;
}
