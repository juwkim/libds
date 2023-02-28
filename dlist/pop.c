/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:45:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:23:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dlist_pop_front(t_dlist *list)
{
	dlist_erase(list, 0);
}

void	dlist_pop_back(t_dlist *list)
{
	dlist_erase(list, -1);
}

void	dlist_erase(t_dlist *list, int pos)
{
	t_dlist_node *const	cur = dlist_get_iterator(list, pos);
	t_dlist_node *const	temp = cur->next;

	cur->next = temp->next;
	temp->next->prev = cur;
	--list->size;
	free(temp);
}
