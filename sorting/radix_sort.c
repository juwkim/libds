/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:32:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 07:04:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	counting(t_sort_data *list, int n, int exp)
{
	int			count[10];
	int			output[MAX_SIZE];
	int			i;

	i = -1;
	while (++i < 10)
		count[i] = 0;
	i = -1;
	while (++i < n)
		count[(list[i] / exp) % 10]++;
	i = 0;
	while (++i < 10)
		count[i] += count[i - 1];
	i = n - 1;
	while (i >= 0)
	{
		output[count[(list[i] / exp) % 10]-- - 1] = list[i];
		--i;
	}
	i = -1;
	while (++i < n)
		list[i] = output[i];
}

void	radix_sort(t_sort_data *list, int n)
{
	int	i;
	int	max;
	int	exp;

	i = 1;
	max = list[0];
	while (i < n)
	{
		if (list[i] > max)
			max = list[i];
		++i;
	}
	exp = 1;
	while (max >= exp)
	{
		counting(list, n, exp);
		exp *= 10;
	}
}
