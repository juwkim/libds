/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:49:30 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 07:50:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_data	front(t_linked_list *list)
{
	return (get_item(list, 0));
}

t_data	back(t_linked_list *list)
{
	return (get_item(list, list->size - 1));
}

t_data	get_item(t_linked_list *list, int pos)
{
	t_node	*cur;

	cur = list->head->next;
	while (pos--)
		cur = cur->next;
	return (cur->item);
}
