/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:40:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/12 12:17:22 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	list_pop_front(t_list *list, void (*del)(void *))
{
	list_erase(list, 0, del);
}

void	list_pop_back(t_list *list, void (*del)(void *))
{
	list_erase(list, list->size - 1, del);
}

void	list_erase(t_list *list, int pos, void (*del)(void *))
{
	t_node	*cur;
	t_node	*temp;

	cur = list->head;
	while (pos--)
		cur = cur->next;
	temp = cur->next;
	cur->next = cur->next->next;
	--list->size;
	del(temp->item);
	free(temp);
}

void	list_pop_next(t_node *prev, void (*del)(void *))
{
	t_node	*cur;

	cur = prev->next;
	prev->next = cur->next;
	del(cur->item);
	free(cur);
}
