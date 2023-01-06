/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "max_heap.h"

// Make a heap empty.
void InitHeap(Heap *pheap)
{
	pheap->num = 0;
}

// check whether a heap is empty.
bool IsEmpty(Heap *pheap)
{
	return pheap->num == 0;
}

// Check whether a heap is full.
bool IsFull(Heap* pheap)
{
	return pheap->num == HEAP_SIZE;
}

// Get a parent index for a given index.
int GetParent(int idx)
{
	return idx >> 1;
}

// Get a left child index for a given index.
int GetLChild(int idx)
{
	return idx << 1;
}

// Get a right child index for a given index.
int GetRChild(int idx)
{
	return (idx << 1) + 1;
}

int GetHighPrioityChild(Heap* pheap, int idx)
{
	int left = GetLChild(idx);
	int right = GetRChild(idx);

	if (left > pheap->num) // No child nodes exist.
		return 0;
	else if (left == pheap->num) // Exist a left child only.
		return left;
	else // Choose a child node with the highest priority.
	{
		if (pheap->items[left].priority > pheap->items[right].priority)
			return left;
		else
			return right;
	}
}

void Insert(Heap* pheap, Data data, int priority)
{
	if (IsFull(pheap))
		exit(EXIT_FAILURE);

	// Compare the new node with its parent.
	int idx = pheap->num + 1;
	int parent = GetParent(idx);
	while (idx > 1 && priority > pheap->items[parent].priority)
	{
		pheap->items[idx] = pheap->items[parent];
		idx = parent;
		parent = GetParent(idx);
	}

	pheap->items[idx].data = data;
	pheap->items[idx].priority = priority;
	pheap->num++;
}

Data Delete(Heap* pheap)
{
	Data max = pheap->items[1].data;
	HNode last = pheap->items[pheap->num];

	int parent = 1;
	int child = GetHighPrioityChild(pheap, parent);

	// Compare the root with its child nodes.
	while (child && last.priority < pheap->items[child].priority)
	{
		pheap->items[parent] = pheap->items[child];
		parent = child;
		child = GetHighPrioityChild(pheap, parent);
	}

	pheap->items[parent] = last;
	pheap->num--;
	return max;
}
