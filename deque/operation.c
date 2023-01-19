/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:26:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/18 19:05:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	dq_print(t_deque *dq)
{	
	int	cur;

	ft_printf("size [%d]:", dq_size(dq));
	cur = dq->head;
	while (cur != dq->tail)
	{
		ft_printf(" %d", dq->items[cur]);
		cur = (cur + 1) % QUEUE_SIZE;
	}
	ft_printf("\n");
}

bool	dq_is_duplication(const t_deque *dq)
{
	t_bst_node	*root;
	size_t		nodes;
	int			cur;

	root = NULL;
	cur = dq->head;
	while ((dq->tail - cur) % QUEUE_SIZE != 0)
		root = bst_insert(root, dq->items[cur++]);
	nodes = bst_count_nodes(root);
	bst_destroy(root);
	return (nodes != dq_size((t_deque *) dq));
}

void	dq_set_rank(t_deque *a)
{
	t_heap	heap;
	int		cur;
	int		rank;

	heap_init(&heap);
	cur = a->head;
	while ((a->tail - cur) % QUEUE_SIZE != 0)
	{
		heap_insert(&heap, cur, a->items[cur]);
		cur = (cur + 1) % QUEUE_SIZE;
	}
	rank = dq_size(a);
	while (rank)
	{
		a->items[heap_delete(&heap)] = rank;
		--rank;
	}
}

bool	dq_nsorted(t_deque *dq, size_t n, bool (*key)(int a, int b))
{
	int	cur;
	int	next;

	cur = dq->head;
	next = (cur + 1) % QUEUE_SIZE;
	while (--n && key(dq->items[cur], dq->items[next]) == true)
	{
		cur = next;
		next = (next + 1) % QUEUE_SIZE;
	}
	return (n == 0);
}

t_dq_data	*get_rank_arr(t_deque *dq, size_t n)
{
	size_t		i;
	int			cur;
	t_heap		heap;
	t_dq_data	*arr;
	int			rank;

	i = 0;
	cur = dq->head;
	heap_init(&heap);
	while (i < n)
	{
		heap_insert(&heap, i, dq->items[cur]);
		cur = (cur + 1) % QUEUE_SIZE;
		++i;
	}
	arr = malloc(dq_size(dq) * sizeof(t_dq_data));
	if (arr == NULL)
		exit(EXIT_FAILURE);
	rank = n;
	while (rank)
	{
		arr[heap_delete(&heap)] = rank;
		--rank;
	}
	return (arr);
}
