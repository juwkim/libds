/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:47:41 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 03:57:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_deque.h"

void	dq_init(t_dynamic_deque *dq)
{
	dq->size = 0;
	dq->head = NULL;
	dq->tail = NULL;
}

void	destroy(t_dynamic_deque *dq)
{
	while (dq->size)
		pop_back(dq);
}

bool	is_empty(t_dynamic_deque *dq)
{
	return (dq->head == NULL);
}

size_t	size(t_dynamic_deque *dq)
{
	return (dq->size);
}
