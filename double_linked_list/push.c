/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:24:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 09:43:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

static t_node	*create_node(t_data item)
{
	t_node *const	new_node = (t_node*) malloc(sizeof(t_node));

	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->item = item;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	push_front(t_double_linked_list *list, t_data item)
{
	insert(list, 0, item);
}

void	push_back(t_double_linked_list *list, t_data item)
{
	insert(list, -1, item);
}

void	insert(t_double_linked_list *list, int pos, t_data item)
{
	t_node *const	new_node = create_node(item);
	t_node *const	cur = get_iterator(list, pos);

	cur->next->prev = new_node;
	new_node->next = cur->next;
	cur->next = new_node;
	new_node->prev = cur;
	++list->size;
}
