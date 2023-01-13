/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 08:04:06 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	print(t_list *list)
{
	int	cur;

	cur = 0;
	while (cur < list->size)
		ft_printf("%06d", list->items[cur++]);
}

void	reverse(t_list *list)
{
	int		left;
	int		right;
	t_data	temp;

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

t_list	*concatenate(t_list *list1, t_list *list2)
{
	t_list *const	list = (t_list *) malloc(sizeof(t_list));
	int				cur;

	if (list == NULL)
		exit(EXIT_FAILURE);
	init(list);
	cur = 0;
	while (cur < list1->size)
		push_back(list, list1->items[cur++]);
	cur = 0;
	while (cur < list2->size)
		push_back(list, list2->items[cur++]);
	return (list);
}
