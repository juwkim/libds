/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

# include <stdlib.h>
# include <stdbool.h>

# include "libft_headers/ft_printf.h"

typedef int	t_data;

typedef struct s_node
{
	t_data			item;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_double_linked_list
{
	size_t	size;
	t_node	*head;
}	t_double_linked_list;

#endif // DOUBLE_LINKED_LIST_H
