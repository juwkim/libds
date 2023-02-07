/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:49:30 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 07:14:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_data	list_front(t_list *list)
{
	return (list_get_item(list, 0));
}

t_data	list_back(t_list *list)
{
	return (list_get_item(list, list->size - 1));
}

t_data	list_get_item(t_list *list, int pos)
{
	t_node	*cur;

	cur = list->head->next;
	while (pos--)
		cur = cur->next;
	return (cur->item);
}
