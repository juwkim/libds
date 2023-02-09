/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:43:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/09 10:42:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*list_create_node(t_data item)
{
	t_node *const	new_node = (t_node*) malloc(sizeof(t_node));

	if (new_node == NULL)
		return (NULL);
	new_node->item = item;
	new_node->next = NULL;
	return (new_node);
}

bool	list_push_front(t_list *list, t_data item)
{
	return (list_insert(list, 0, item));
}

bool	list_push_back(t_list *list, t_data item)
{
	return (list_insert(list, list->size, item));
}

bool	list_insert(t_list *list, int pos, t_data item)
{
	t_node	*cur;
	t_node	*new_node;

	if (!item)
		return (false);
	new_node = list_create_node(item);
	if (new_node == NULL)
		return (false);
	cur = list->head;
	while (pos--)
		cur = cur->next;
	new_node->next = cur->next;
	cur->next = new_node;
	++list->size;
	return (true);
}
