/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:26:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:05:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	clist_print(t_clist *list)
{
	t_clist_node	*cur;

	cur = list->tail->next;
	while (cur != NULL)
	{
		printf("%06d", *(int *) cur->item);
		cur = cur->next;
	}
}

void	clist_reverse(t_clist *list)
{
	t_clist_node	*prev;
	t_clist_node	*cur;
	t_clist_node	*next;

	cur = NULL;
	next = list->tail->next;
	while (next != NULL)
	{
		prev = cur;
		cur = next;
		next = next->next;
		cur->next = prev;
	}
	list->tail->next = cur;
}

t_clist	*clist_concatenate(t_clist *list1, t_clist *list2)
{
	t_clist *const	list = (t_clist *) malloc(sizeof(t_clist));
	t_clist_node	*cur;

	assert(list != NULL);
	clist_init(list);
	cur = list1->tail->next;
	while (cur)
	{
		clist_push_back(list, cur->item);
		cur = cur->next;
	}
	cur = list2->tail->next;
	while (cur)
	{
		clist_push_back(list, cur->item);
		cur = cur->next;
	}
	return (list);
}
