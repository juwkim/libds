/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 04:25:02 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:04:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

t_clist_data	clist_front(t_clist *list)
{
	return (clist_get_item(list, 0));
}

t_clist_data	clist_back(t_clist *list)
{
	return (list->tail->item);
}

t_clist_data	get_item(t_clist *list, int pos)
{
	t_clist_node	*cur;

	cur = list->tail;
	while (pos--)
		cur = cur->next;
	return (cur->next->item);
}
