/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:51:16 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 06:01:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	pop_front(t_list *list)
{
	erase(list, 0);
}

void	pop_back(t_list *list)
{
	erase(list, list->size - 1);
}

void	erase(t_list *list, int pos)
{
	size_t	i;

	i = pos;
	while (i < list->size - 1)
	{
		list->items[i] = list->items[i + 1];
		++i;
	}
	--list->size;
}
