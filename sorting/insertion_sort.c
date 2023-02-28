/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:45:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:58:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	insertion_sort(t_sort_data *list, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = list[i];
		j = i - 1;
		while (j >= 0 && key < list[j])
		{
			list[j + 1] = list[j];
			--j;
		}
		list[j + 1] = key;
		++i;
	}
}
