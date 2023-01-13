/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:43:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 07:12:36 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "single_linked_list.h"

static t_node	*create_node(t_data item)
{
	t_node *const	new_node = (t_node*) malloc(sizeof(t_node));

	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->item = item;
	return (new_node);
}

void	push_front(t_single_linked_list *list, t_data item)
{
	insert(list, 0, item);
}

void	push_back(t_single_linked_list *list, t_data item)
{
	insert(list, list->size, item);
}

void	insert(t_single_linked_list *list, int pos, t_data item)
{
	t_node			*cur;
	t_node *const	new_node = create_node(item);

	cur = list->head;
	while (pos--)
		cur = cur->next;
	new_node->next = cur->next;
	cur->next = new_node;
	++list->size;
}
