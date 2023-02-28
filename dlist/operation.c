/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:51:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 09:51:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dlist_print(t_dlist *list)
{
	t_dlist_node	*cur;

	cur = list->head->next;
	while (cur != NULL)
	{
		printf("%06d", *(int *) cur->item);
		cur = cur->next;
	}
}

void	dlist_reverse(t_dlist *list)
{
	t_dlist_node	*prev;
	t_dlist_node	*cur;
	t_dlist_node	*next;

	cur = NULL;
	next = list->head->next;
	while (next != NULL)
	{
		prev = cur;
		cur = next;
		next = next->next;
		cur->next = prev;
		prev->prev = cur;
	}
	list->tail = list->head;
	list->head = cur;
}

t_dlist	*dlist_concatenate(t_dlist *list1, t_dlist *list2)
{
	t_dlist *const	list = (t_dlist *) malloc(sizeof(t_dlist));
	t_dlist_node	*cur;

	assert(list != NULL);
	dlist_init(list);
	cur = list1->head->next;
	while (cur->next)
	{
		dlist_push_back(list, cur->item);
		cur = cur->next;
	}
	cur = list2->head->next;
	while (cur->next)
	{
		dlist_push_back(list, cur->item);
		cur = cur->next;
	}
	return (list);
}
