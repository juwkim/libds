/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:47:41 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 11:19:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_dqueue.h"

void	init(t_dqueue *dq)
{
	dq->size = 0;
	dq->head = NULL;
	dq->tail = NULL;
}

void	destroy(t_dqueue *dq)
{
	while (dq->size)
		pop_back(dq);
}

bool	is_empty(t_dqueue *dq)
{
	return (dq->head == NULL);
}

size_t	size(t_dqueue *dq)
{
	return (dq->size);
}
