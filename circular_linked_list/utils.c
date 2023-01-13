/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:41:27 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 07:31:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"

void	init(t_circular_linked_list *list)
{
	list->size = 0;
	list->tail = NULL;
}

void	destroy(t_circular_linked_list *list)
{
	while (is_empty(list) == false)
		pop_front(list);
}

bool	is_empty(t_circular_linked_list *list)
{
	return (list->size == 0);
}

size_t	size(t_circular_linked_list *list)
{
	return (list->size);
}
