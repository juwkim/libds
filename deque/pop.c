/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:50:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 03:58:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	dq_pop_front(t_deque *dq)
{
	dq->head = (dq->head + 1) % QUEUE_SIZE;
}

void	dq_pop_back(t_deque *dq)
{
	if (dq->tail == 0)
		dq->tail = QUEUE_SIZE - 1;
	else
		dq->tail = dq->tail - 1;
}
