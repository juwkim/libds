/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:40:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:12:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

static t_clist_node	*__clist_create_node(t_clist_data item)
{
	t_clist_node *const	new_node = (t_clist_node*) malloc(sizeof(t_clist_node));

	assert(new_node != NULL);
	new_node->item = item;
	return (new_node);
}

static void	__clist_push_init_item(t_clist *list, t_clist_data item)
{
	t_clist_node *const	new_node = __clist_create_node(item);

	new_node->next = new_node;
	list->tail = new_node;
	++list->size;
}

void	clist_push_front(t_clist *list, t_clist_data item)
{
	if (clist_is_empty(list) == true)
		__clist_push_init_item(list, item);
	else
		clist_insert(list, 0, item);
}

void	clist_push_back(t_clist *list, t_clist_data item)
{
	t_clist_node	*new_node;

	if (clist_is_empty(list) == true)
		__clist_push_init_item(list, item);
	else
	{
		new_node = __clist_create_node(item);
		new_node->next = list->tail->next;
		list->tail->next = new_node;
		list->tail = new_node;
		++list->size;
	}
}

void	clist_insert(t_clist *list, int pos, t_clist_data item)
{
	t_clist_node	*cur;
	t_clist_node	*new_node;

	if (clist_is_empty(list) == true)
		__clist_push_init_item(list, item);
	else
	{
		cur = list->tail;
		while (pos--)
			cur = cur->next;
		new_node = __clist_create_node(item);
		new_node->next = cur->next;
		cur->next = new_node;
		++list->size;
	}
}
