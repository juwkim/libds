/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:23:38 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/11 06:43:53 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../../libft/includes/libft.h"
# include "murmurhash3_x86_32.h"

# define TABLE_SIZE 24593

typedef char *	t_key;
typedef char *	t_value;

typedef struct s_hash_table_node
{
	t_key		key;
	t_value		value;
}	t_hash_table_node;

typedef struct s_hash_table
{
	t_hash_table_node	items[TABLE_SIZE];
}	t_hash_table;

void	hash_table_init(t_hash_table *table);
void	hash_table_destroy(t_hash_table *table);
void	hash_table_insert(t_hash_table *table, t_key key, t_value value);
void	hash_table_remove(t_hash_table *table, t_key key);
t_value	hash_table_search(t_hash_table *table, t_key key);

#endif // HASH_TABLE_H
