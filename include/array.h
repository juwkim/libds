/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:32:26 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 23:32:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdio.h>
# include <assert.h>
# include <stdlib.h>
# include <stdbool.h>

# define ARRAY_SIZE 100000

typedef void *	t_array_data;

typedef struct s_array
{
	size_t			size;
	t_array_data	items[ARRAY_SIZE];
}	t_array;

// usils.c
void			array_init(t_array *array);
bool			array_is_empty(t_array *array);
bool			array_is_full(t_array *array);
size_t			array_size(t_array *array);

// push.c
void			array_push_front(t_array *array, t_array_data item);
void			array_push_back(t_array *array, t_array_data item);
void			array_insert(t_array *array, int pos, t_array_data item);

// pop.c
void			array_pop_front(t_array *array);
void			array_pop_back(t_array *array);
void			array_erase(t_array *array, int pos);

// getter.c
t_array_data	array_front(t_array *array);
t_array_data	array_back(t_array *array);
t_array_data	array_get_item(t_array *array, int pos);

// operation.c
void			array_print(t_array *array);
void			array_reverse(t_array *array);
t_array			*array_concatenate(t_array *array1, t_array *array2);

#endif // array_H
