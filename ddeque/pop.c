/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:01:26 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:32:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ddeque.h"

void	ddq_pop_front(t_ddeque *dq)
{
	t_ddq_node *const	temp = dq->head;

	if (ddq_size(dq) == 1)
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

void	ddq_pop_back(t_ddeque *dq)
{
	t_ddq_node *const	temp = dq->tail;

	if (ddq_size(dq) == 1)
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
