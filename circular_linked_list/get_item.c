/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 04:25:02 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 05:04:42 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"

t_data	front(t_circular_list *list)
{
	return (get_item(list, 0));
}

t_data	back(t_circular_list *list)
{
	return (list->tail->item);
}

t_data	get_item(t_circular_list *list, int pos)
{
	t_node	*cur;

	cur = list->tail;
	while (pos--)
		cur = cur->next;
	return (cur->next->item);
}
