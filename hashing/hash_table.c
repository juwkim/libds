/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:23:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 05:36:44 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

void	hash_table_init(t_hash_table *table)
{
	int	i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		table->items[i].key = NULL;
		table->items[i].value = NULL;
		++i;
	}
}

void	hash_table_destroy(t_hash_table *table)
{
	int	i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		free(table->items[i].key);
		free(table->items[i].value);
		++i;
	}
}

void	hash_table_insert(t_hash_table *table, t_key key, t_value value)
{
	const int		key_len = strlen(key);
	const uint32_t	hash = murmurhash3_x86_32(key, key_len, INT32_MAX);
	uint32_t		start;
	uint32_t		cur;

	start = hash % TABLE_SIZE;
	cur = start;
	while (table->items[cur].key != NULL && \
		strncmp(table->items[cur].key, key, key_len + 1) != 0)
	{
		cur = (cur + 1) % TABLE_SIZE;
		if (cur == start)
		{
			printf("Hash table is full\n");
			return ;
		}
	}
	if (table->items[cur].key == NULL)
	{
		table->items[cur].key = key;
		table->items[cur].value = value;
	}
}

void	hash_table_remove(t_hash_table *table, t_key key)
{
	const int		key_len = strlen(key);
	const uint32_t	hash = murmurhash3_x86_32(key, key_len, INT32_MAX);
	uint32_t		start;
	uint32_t		cur;

	start = hash % TABLE_SIZE;
	cur = start;
	while (table->items[cur].key != NULL && \
		strncmp(table->items[cur].key, key, key_len + 1) != 0)
	{
		cur = (cur + 1) % TABLE_SIZE;
		if (cur == start)
			return ;
	}
	free(table->items[cur].key);
	free(table->items[cur].value);
	table->items[cur].key = NULL;
	table->items[cur].value = NULL;
}

t_value	hash_table_search(t_hash_table *table, t_key key)
{
	const int		key_len = strlen(key);
	const uint32_t	hash = murmurhash3_x86_32(key, key_len, INT32_MAX);
	uint32_t		start;
	uint32_t		cur;

	start = hash % TABLE_SIZE;
	cur = start;
	while (table->items[cur].key != NULL && \
		strncmp(table->items[cur].key, key, key_len + 1) != 0)
	{
		cur = (cur + 1) % TABLE_SIZE;
		if (cur == start)
			return (NULL);
	}
	return (table->items[cur].value);
}
