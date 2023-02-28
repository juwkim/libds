/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 08:55:42 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:26:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dlist_init(t_dlist *list)
{
	t_dlist_node *const	head = (t_dlist_node*) malloc(sizeof(t_dlist_node));
	t_dlist_node *const	tail = (t_dlist_node*) malloc(sizeof(t_dlist_node));

	assert(head != NULL && tail != NULL);
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
	list->head = head;
	list->tail = tail;
	list->size = 0;
}

void	dlist_destroy(t_dlist *list)
{
	while (list->head->next)
		dlist_pop_front(list);
	free(list->head);
}

bool	dlist_is_empty(t_dlist *list)
{
	return (list->size == 0);
}

size_t	dlist_size(t_dlist *list)
{
	return (list->size);
}

t_dlist_node	*get_iterator(t_dlist *list, int pos)
{
	t_dlist_node	*cur;

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
