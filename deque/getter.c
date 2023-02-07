/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:51:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 03:58:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_dq_data	dq_front(t_deque *dq)
{
	return (dq_get_front_item(dq, 0));
}

t_dq_data	dq_back(t_deque *dq)
{
	return (dq_get_back_item(dq, -1));
}

t_dq_data	dq_get_front_item(t_deque *dq, int pos)
{
	return (dq->items[(dq->head + pos) % QUEUE_SIZE]);
}

t_dq_data	dq_get_back_item(t_deque *dq, int pos)
{
	int	cur;

	cur = dq->tail + pos;
	if (cur < 0)
		cur += QUEUE_SIZE;
	return (dq->items[cur]);
}
