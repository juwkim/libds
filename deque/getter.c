/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:51:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/16 14:30:35 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_dq_node	dq_front(t_deque *dq)
{
	return (dq->nodes[dq->head]);
}

t_dq_node	dq_back(t_deque *dq)
{
	return (dq->nodes[(dq->tail - 1) % QUEUE_SIZE]);
}
