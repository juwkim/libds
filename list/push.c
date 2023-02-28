/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:43:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 07:17:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_node	*list_create_node(t_list_data item)
{
	t_list_node *const	new_node = (t_list_node*) malloc(sizeof(t_list_node));

	assert(new_node != NULL);
	new_node->item = item;
	new_node->next = NULL;
	return (new_node);
}

void	list_push_front(t_list *list, t_list_data item)
{
	list_insert(list, 0, item);
}

void	list_push_back(t_list *list, t_list_data item)
{
	list_insert(list, list->size, item);
}

void	list_insert(t_list *list, int pos, t_list_data item)
{
	t_list_node	*cur;
	t_list_node	*new_node;

	new_node = list_create_node(item);
	cur = list->head;
	while (pos--)
		cur = cur->next;
	new_node->next = cur->next;
	cur->next = new_node;
	++list->size;
}

t_list_node	*list_insert_list(t_list *list1, t_list_node *prev, t_list *list2)
{
	t_list_node	*next;
	t_list_node	*cur;

	next = prev->next;
	cur = list2->head->next;
	prev->next = cur;
	while (cur->next != NULL)
	{
		++list1->size;
		cur = cur->next;
	}
	cur->next = next;
	return (cur);
}
