/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:50:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 20:03:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	dq_push_front(t_deque *dq, t_dq_data item)
{
	if (dq->head == 0)
		dq->head = QUEUE_SIZE - 1;
	else
		--dq->head;
	dq->items[dq->head] = item;
}

void	dq_push_back(t_deque *dq, t_dq_data item)
{
	dq->items[dq->tail] = item;
	dq->tail = (dq->tail + 1) % QUEUE_SIZE;
}
