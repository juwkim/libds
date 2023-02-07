/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:40:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 07:14:45 by juwkim           ###   ########.fr       */
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
