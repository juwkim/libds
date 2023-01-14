/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:40:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 16:45:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	bubble_sort(t_data *list, int n)
{
	int	i;
	int	j;

	i = n - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (list[j] > list[j + 1])
				ft_swap(list + j, list + j + 1);
			++j;
		}
		--i;
	}
}
