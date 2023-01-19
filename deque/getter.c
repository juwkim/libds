/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:51:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/18 01:46:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_dq_data	dq_front(t_deque *dq)
{
	return (dq->items[dq->head]);
}

t_dq_data	dq_back(t_deque *dq)
{
	int	cur;

	if (dq->tail == 0)
		cur = QUEUE_SIZE - 1;
	else
		cur = dq->tail - 1;
	return (dq->items[cur]);
}
