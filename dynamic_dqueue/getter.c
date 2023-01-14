/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 11:15:44 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_dqueue.h"

t_data	front(t_dqueue *dq)
{
	return (dq->head->item);
}

t_data	back(t_dqueue *dq)
{
	return (dq->tail->item);
}
