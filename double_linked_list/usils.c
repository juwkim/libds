/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:55:42 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 09:41:18 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

void	init(t_double_linked_list *list)
{
	t_node *const	head = (t_node*) malloc(sizeof(t_node));
	t_node *const	tail = (t_node*) malloc(sizeof(t_node));

	if (head == NULL || tail == NULL)
		exit(EXIT_FAILURE);
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
	list->head = head;
	list->tail = tail;
	list->size = 0;
}

void	destroy(t_double_linked_list *list)
{
	while (list->head->next)
		pop_front(list);
	free(list->head);
}

bool	is_empty(t_double_linked_list *list)
{
	return (list->size == 0);
}

size_t	size(t_double_linked_list *list)
{
	return (list->size);
}

t_node	*get_iterator(t_double_linked_list *list, int pos)
{
	t_node	*cur;

	if (pos >= 0)
	{
		cur = list->head;
		while (pos--)
			cur = cur->next;
	}
	else
	{
		cur = list->tail->prev;
		while (pos++)
			cur = cur->prev;
	}
	return (cur);
}
