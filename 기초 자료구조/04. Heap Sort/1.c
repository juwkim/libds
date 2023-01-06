/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 200
#define SIZE		10

typedef struct
{
	int key;
} element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_SIZE;
} HeapType;

void init(HeapType *h)
{
	h->heap_SIZE = 0;
}

void insert_max_heap(HeapType *h, element item)
{
	int i = ++(h->heap_SIZE);
	while (i != 1 && item.key > h->heap[i>>1].key)
	{
		h->heap[i] = h->heap[i>>1];
		i >>= 1;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h)
{
	int parent = 1;
	int child = 2;
	element item = item = h->heap[1];
	element temp = h->heap[(h->heap_SIZE)--];

	while (child <= h->heap_SIZE)
	{
		if (child < h->heap_SIZE && h->heap[child].key < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child <<= 1;
	}
	h->heap[parent] = temp;
	return item;
}

void MaxheapSort(element a[], int n)
{
	int i;
	HeapType h;

	init(&h);
	for (i = 0; i < n; ++i)
		insert_max_heap(&h, a[i]);

	for (i = n-1; i >= 0; --i)
		a[i] = delete_max_heap(&h);
}

void verifyMaxheapSort (element * e)
{
	for (int i = 0; i < 9; ++i)
	{
		if (e[i].key > e[i+1].key)
		{
			printf("%d 번째 수와 %d 번째 수가 정렬이 되어있지 않습니다.\n", i+1, i+2);
			return;
		}
	}
	printf("Maxheap정렬이 확인되었습니다.\n\n");
}

void insert_min_heap (HeapType *h, element item) {
	int i = ++(h->heap_SIZE);
	while (i != 1 && item.key < h->heap[i>>1].key)
	{
		h->heap[i] = h->heap[i>>1];
		i >>= 1;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType *h)
{
	int parent = 1;
	int child = 2;
	element item = item = h->heap[1];
	element temp = h->heap[(h->heap_SIZE)--];
	
	while (child <= h->heap_SIZE)
	{
		if (child < h->heap_SIZE && h->heap[child].key > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child <<= 1;
	}
	h->heap[parent] = temp;
	return item;
}


void MinheapSort(element a[], int n)
{
	int i;
	HeapType h;

	init(&h);
	for (i = 0; i < n; ++i)
		insert_min_heap(&h, a[i]);

	for (i = n-1; i >= 0; --i)
		a[i] = delete_min_heap(&h);
}

void verifyMinheapSort (element * e)
{
	for (int i = 0; i < 9; ++i)
	{
		if (e[i].key < e[i+1].key)
		{
			printf("%d 번째 수와 %d 번째 수가 정렬이 되어있지 않습니다.\n", i + 1, i + 2);
			return;
		}
	}
	printf("Minheap정렬이 확인되었습니다.\n\n");
}

int main()
{
	int i;
	element e[SIZE];

	srand(time(NULL));
	for (i = 0; i < SIZE; ++i) e[i].key = rand() % 9 + 1;

	printf("정렬 전 키 값 출력: ");
	for (i = 0; i < SIZE; ++i) printf("%3d", e[i].key);
	printf("\n");
	verifyMaxheapSort(e);

	MaxheapSort(e, SIZE);
	printf("Maxheap정렬 후 키 값 출력: ");
	for (i = 0; i < SIZE; ++i) printf("%3d", e[i].key);
	printf("\n");
	verifyMaxheapSort(e);	
	
	for (i = 0; i < SIZE; ++i) e[i].key = rand() % 9 + 1;

	printf("정렬 전 키 값 출력: ");
	for (i = 0; i < SIZE; ++i) printf("%3d", e[i].key);
	printf("\n");
	verifyMinheapSort(e);

	MinheapSort(e, SIZE);
	printf("Minheap정렬 후 키 값 출력: ");
	for (i = 0; i < SIZE; ++i) printf("%3d", e[i].key);
	printf("\n");
	verifyMinheapSort(e);

	return 0;
}