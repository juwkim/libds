/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:01:26 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 11:17:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_dqueue.h"

void	pop_front(t_dqueue *dq)
{
	t_node *const	temp = dq->head;

	if (size(dq) == 1)
	{
		dq->head = NULL;
		dq->tail = NULL;
	}
	else
	{
		temp->next->prev = NULL;
		dq->head = temp->next;
	}
	--dq->size;
	free(temp);
}

void	pop_back(t_dqueue *dq)
{
	t_node *const	temp = dq->tail;

	if (size(dq) == 1)
	{
		dq->head = NULL;
		dq->tail = NULL;
	}
	else
	{
		temp->prev->next = NULL;
		dq->tail = temp->prev;
	}
	--dq->size;
	free(temp);
}
