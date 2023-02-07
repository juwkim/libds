/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:35:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 03:58:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	dq_init(t_deque *dq)
{
	dq->head = 0;
	dq->tail = 0;
}

void	dq_destroy(t_deque *dq)
{
	int	cur;

	cur = dq->head;
	while (cur != dq->tail)
	{
		free(dq->items[cur]);
		cur = (cur + 1) % QUEUE_SIZE;
	}
}

bool	dq_is_empty(t_deque *dq)
{
	return (dq_size(dq) == 0);
}

bool	dq_is_full(t_deque *dq)
{
	return (dq_size(dq) == QUEUE_SIZE - 1);
}

size_t	dq_size(t_deque *dq)
{
	if (dq->tail >= dq->head)
		return (dq->tail - dq->head);
	else
		return (dq->tail - dq->head + QUEUE_SIZE);
}
