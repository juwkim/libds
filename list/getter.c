/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:49:30 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:46:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_data	list_front(t_list *list)
{
	return (list_get_item(list, 0));
}

t_list_data	list_back(t_list *list)
{
	return (list_get_item(list, list->size - 1));
}

t_list_data	list_get_item(t_list *list, int pos)
{
	t_list_node	*cur;

	cur = list->head->next;
	while (pos--)
		cur = cur->next;
	return (cur->item);
}
