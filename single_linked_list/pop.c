/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 06:40:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 06:55:49 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "single_linked_list.h"

void	pop_front(t_single_linked_list *list)
{
	erase(list, 0);
}

void	pop_back(t_single_linked_list *list)
{
	erase(list, list->size - 1);
}

void	erase(t_single_linked_list *list, int pos)
{
	t_node	*cur;
	t_node	*temp;

	cur = list->head;
	while (pos--)
		cur = cur->next;

	temp = cur->next;
	cur->next = cur->next->next;
	--list->size;
	free(temp);
}
