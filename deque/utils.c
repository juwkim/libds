/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:35:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 20:01:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	dq_init(t_deque *dq)
{
	dq->head = 0;
	dq->tail = 0;
}

bool	dq_is_empty(const t_deque *dq)
{
	return (dq_size(dq) == 0);
}

bool	dq_is_full(const t_deque *dq)
{
	return (dq_size(dq) == QUEUE_SIZE - 1);
}

size_t	dq_size(const t_deque *dq)
{
	if (dq->tail >= dq->head)
		return (dq->tail - dq->head);
	else
		return (dq->tail - dq->head + QUEUE_SIZE);
}
