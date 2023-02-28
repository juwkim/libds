/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:14:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:19:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist_data	dlist_front(t_dlist *list)
{
	return (dlist_get_item(list, 0));
}

t_dlist_data	dlist_back(t_dlist *list)
{
	return (dlist_get_item(list, -1));
}

t_dlist_data	dlist_get_item(t_dlist *list, int pos)
{
	return (dlist_get_iterator(list, pos)->next->item);
}
