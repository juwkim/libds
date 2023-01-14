/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:35:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 11:57:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dqueue.h"

void	init(t_dqueue *dq)
{
	dq->head = 0;
	dq->tail = 0;
}

bool	is_empty(t_dqueue *dq)
{
	return (size(dq) == 0);
}

bool	is_full(t_dqueue *dq)
{
	return (size(dq) == QUEUE_SIZE - 1);
}

size_t	size(t_dqueue *dq)
{
	return ((dq->tail - dq->head) % QUEUE_SIZE);
}
