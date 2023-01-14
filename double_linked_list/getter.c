/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:14:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 09:41:39 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

t_data	front(t_double_linked_list *list)
{
	return (get_item(list, 0));
}

t_data	back(t_double_linked_list *list)
{
	return (get_item(list, -1));
}

t_data	get_item(t_double_linked_list *list, int pos)
{
	return (get_iterator(list, pos)->next->item);
}
