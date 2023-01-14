/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:51:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 11:51:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dqueue.h"

t_data	front(t_dqueue *dq)
{
	return (dq->items[dq->head]);
}

t_data	back(t_dqueue *dq)
{
	return (dq->items[(dq->tail - 1) % QUEUE_SIZE]);
}
