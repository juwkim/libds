/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:45:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 09:50:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

void	pop_front(t_double_linked_list *list)
{
	erase(list, 0);
}

void	pop_back(t_double_linked_list *list)
{
	erase(list, -1);
}

void	erase(t_double_linked_list *list, int pos)
{
	t_node *const	cur = get_iterator(list, pos);
	t_node *const	temp = cur->next;

	cur->next = temp->next;
	temp->next->prev = cur;
	--list->size;
	free(temp);
}
