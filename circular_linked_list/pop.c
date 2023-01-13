/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:54:26 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 05:16:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"

static void	pop_init_item(t_circular_list *list)
{
	free(list->tail);
	--list->size;
	list->tail = NULL;
}

void	pop_front(t_circular_list *list)
{
	if (list->size == 1)
		pop_init_item(list);
	else
		erase(list, 0);
}

void	pop_back(t_circular_list *list)
{
	int		i;
	t_node	*cur;
	t_node	*temp;

	if (list->size == 1)
		pop_init_item(list);
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

void	erase(t_circular_list *list, int pos)
{
	t_node	*cur;
	t_node	*temp;

	if (list->size == 1)
		pop_init_item(list);
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
