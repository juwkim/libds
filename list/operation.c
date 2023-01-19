/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/19 12:11:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_print(t_list *list)
{
	size_t	cur;

	cur = 0;
	while (cur < list->size)
		ft_printf("%s\n", list->items[cur++]);
}

void	list_reverse(t_list *list)
{
	size_t		left;
	size_t		right;
	t_list_data	temp;

	left = 0;
	right = list->size - 1;
	while (left < right)
	{
		temp = list->items[left];
		list->items[left] = list->items[right];
		list->items[right] = temp;
		++left;
		--right;
	}
}

t_list	*list_concatenate(t_list *list1, t_list *list2)
{
	t_list *const	list = (t_list *) malloc(sizeof(t_list));
	size_t			cur;

	if (list == NULL)
		exit(EXIT_FAILURE);
	list_init(list);
	cur = 0;
	while (cur < list1->size)
		list_push_back(list, list1->items[cur++]);
	cur = 0;
	while (cur < list2->size)
		list_push_back(list, list2->items[cur++]);
	return (list);
}
