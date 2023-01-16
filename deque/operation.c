/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:26:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/16 14:40:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

bool	dq_is_duplication(const t_deque *dq)
{
	t_bst_node	*root;
	size_t		nodes;
	int			cur;

	root = NULL;
	cur = dq->head;
	while ((dq->tail - cur) % QUEUE_SIZE != 0)
		root = bst_insert(root, dq->nodes[cur++].item);
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
		heap_insert(&heap, cur, a->nodes[cur].item);
		cur = (cur + 1) % QUEUE_SIZE;
	}
	rank = dq_size(a);
	while (rank)
	{
		a->nodes[heap_delete(&heap)].rank = rank;
		--rank;
	}
}
