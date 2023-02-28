/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:24:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:24:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

static t_dlist_node	*__dlist_create_node(t_dlist_data item)
{
	t_dlist_node *const	new_node = (t_dlist_node*) malloc(sizeof(t_dlist_node));

	assert(new_node != NULL);
	new_node->item = item;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	dlist_push_front(t_dlist *list, t_dlist_data item)
{
	dlist_insert(list, 0, item);
}

void	dlist_push_back(t_dlist *list, t_dlist_data item)
{
	dlist_insert(list, -1, item);
}

void	dlist_insert(t_dlist *list, int pos, t_dlist_data item)
{
	t_dlist_node *const	new_node = __dlist_create_node(item);
	t_dlist_node *const	cur = dlist_get_iterator(list, pos);

	cur->next->prev = new_node;
	new_node->next = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
	++list->size;
}
