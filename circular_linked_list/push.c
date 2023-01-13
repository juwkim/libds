/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:40:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 05:17:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"

static void	push_init_item(t_circular_list *list, t_data item)
{
	t_node *const	new_node = create_node(item);

	new_node->next = new_node;
	list->tail = new_node;
	++list->size;
}

void	push_front(t_circular_list *list, t_data item)
{
	if (is_empty(list))
		push_init_item(list, item);
	else
		insert(list, 0, item);
}

void	push_back(t_circular_list *list, t_data item)
{
	t_node	*new_node;

	if (is_empty(list))
		push_init_item(list, item);
	else
	{
		new_node = create_node(item);
		new_node->next = list->tail->next;
		list->tail->next = new_node;
		list->tail = new_node;
		++list->size;
	}
}

void	insert(t_circular_list *list, int pos, t_data item)
{
	t_node	*cur;
	t_node	*new_node;

	if (is_empty(list))
		push_init_item(list, item);
	else
	{
		cur = list->tail;
		while (pos--)
			cur = cur->next;
		new_node = create_node(item);
		new_node->next = cur->next;
		cur->next = new_node;
		++list->size;
	}
}
