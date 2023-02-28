/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:54:26 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:08:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

static void	__clist_pop_init_item(t_clist *list)
{
	free(list->tail);
	--list->size;
	list->tail = NULL;
}

void	clist_pop_front(t_clist *list)
{
	if (list->size == 1)
		__clist_pop_init_item(list);
	else
		clist_erase(list, 0);
}

void	clist_pop_back(t_clist *list)
{
	int				i;
	t_clist_node	*cur;
	t_clist_node	*temp;

	if (list->size == 1)
		__clist_pop_init_item(list);
	else
	{
		i = list->size - 1;
		cur = list->tail;
		while (i--)
			cur = cur->next;
		temp = cur->next;
		cur->next = temp->next;
		list->tail = cur;
		--list->size;
		free(temp);
	}
}

void	clist_erase(t_clist *list, int pos)
{
	t_clist_node	*cur;
	t_clist_node	*temp;

	if (list->size == 1)
		__clist_pop_init_item(list);
	else
	{
		cur = list->tail;
		while (pos--)
			cur = cur->next;
		temp = cur->next;
		cur->next = temp->next;
		--list->size;
		free(temp);
	}
}
