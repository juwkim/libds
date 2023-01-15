/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:53:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/15 21:04:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_dqueue.h"

static t_node	*create_node(t_data item)
{
	t_node *const	new_node = (t_node *) malloc(sizeof(t_node));

	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->item = item;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	push_front(t_deque *dq, t_data item)
{
	t_node *const	new_node = create_node(item);

	if (is_empty(dq))
	{
		dq->head = new_node;
		dq->tail = new_node;
	}
	else
	{
		dq->head->prev = new_node;
		new_node->next = dq->head;
		dq->head = new_node;
	}
	++dq->size;
}

void	push_back(t_deque *dq, t_data item)
{
	t_node *const	new_node = create_node(item);

	if (is_empty(dq))
	{
		dq->head = new_node;
		dq->tail = new_node;
	}
	else
	{
		dq->tail->next = new_node;
		new_node->prev = dq->tail;
		dq->tail = new_node;
	}
	++dq->size;
}
