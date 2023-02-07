/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 03:57:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_deque.h"

t_data	front(t_dynamic_deque *dq)
{
	return (dq->head->item);
}

t_data	back(t_dynamic_deque *dq)
{
	return (dq->tail->item);
}
