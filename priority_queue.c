/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"

void InitPQueue(PQueue* ppqueue)
{
	InitHeap(ppqueue);
}

bool IsPQEmpty(PQueue* ppqueue)
{
	return IsEmpty(ppqueue);
}

bool IsPQFull(PQueue* ppqueue)
{
	return IsFull(ppqueue);
}

void Enqueue(PQueue* ppqueue, Data data, int priority)
{
	Insert(ppqueue, data, priority);
}

Data Dequeue(PQueue* ppqueue)
{
	return Delete(ppqueue);
}

void HeapSort(Data a[], int n)
{
	Heap heap;
	InitHeap(&heap);

	// Insert all elements to the heap.
	for (int i = 0; i < n; i++)
		Insert(&heap, a[i], a[i]);

	// Remove all elements from the heap.
	for (int i = n - 1; i >= 0; i--)
		a[i] = Delete(&heap);
}
