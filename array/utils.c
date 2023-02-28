/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:31:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 05:22:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_init(t_array *array)
{
	array->size = 0;
}

bool	array_is_empty(t_array *array)
{
	return (array->size == 0);
}

bool	array_is_full(t_array *array)
{
	return (array->size == ARRAY_SIZE);
}

size_t	array_size(t_array *array)
{
	return (array->size);
}
