/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:50:48 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/16 07:10:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	pop_front(t_deque *dq)
{
	dq->head = (dq->head + 1) % QUEUE_SIZE;
}

void	pop_back(t_deque *dq)
{
	dq->tail = (dq->tail - 1) % QUEUE_SIZE;
}
