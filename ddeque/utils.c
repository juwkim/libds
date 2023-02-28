/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:47:41 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:33:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ddeque.h"

void	ddq_init(t_ddeque *dq)
{
	dq->size = 0;
	dq->head = NULL;
	dq->tail = NULL;
}

void	ddq_destroy(t_ddeque *dq)
{
	while (dq->size)
		ddq_pop_back(dq);
}

bool	ddq_is_empty(t_ddeque *dq)
{
	return (dq->head == NULL);
}

size_t	ddq_size(t_ddeque *dq)
{
	return (dq->size);
}
