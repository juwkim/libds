/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:50:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/15 21:04:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dqueue.h"

void	push_front(t_deque *dq, t_data item)
{
	dq->head = (dq->head - 1) % QUEUE_SIZE;
	dq->items[dq->head] = item;
}

void	push_back(t_deque *dq, t_data item)
{
	dq->items[dq->tail] = item;
	dq->tail = (dq->tail + 1) % QUEUE_SIZE;
}
