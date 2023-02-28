/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:53:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 07:15:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ddeque.h"

static t_ddq_node	*__ddq_create_node(t_ddq_data item)
{
	t_ddq_node *const	new_node = (t_ddq_node *) malloc(sizeof(t_ddq_node));

	assert(new_node != NULL);
	new_node->item = item;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ddq_push_front(t_ddeque *dq, t_ddq_data item)
{
	t_ddq_node *const	new_node = __ddq_create_node(item);

	if (ddq_is_empty(dq) == true)
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

void	ddq_push_back(t_ddeque *dq, t_ddq_data item)
{
	t_ddq_node *const	new_node = __ddq_create_node(item);

	if (ddq_is_empty(dq) == true)
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
