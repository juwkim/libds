/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:29:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ddeque.h"

t_ddq_data	ddq_front(t_ddeque *dq)
{
	return (dq->head->item);
}

t_ddq_data	ddq_back(t_ddeque *dq)
{
	return (dq->tail->item);
}
