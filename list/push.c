/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:41:27 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/20 18:08:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_push_front(t_list *list, t_list_data item)
{
	list_insert(list, 0, item);
}

void	list_push_back(t_list *list, t_list_data item)
{
	list->items[list->size++] = item;
}

void	list_insert(t_list *list, int pos, t_list_data item)
{
	int	i;

	i = list->size - 1;
	while (i >= pos)
	{
		list->items[i + 1] = list->items[i];
		--i;
	}
	list->items[pos] = item;
	++list->size;
}
