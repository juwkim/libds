/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:14:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/15 21:04:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static bool	*get_visited_array(size_t size)
{
	size_t		i;
	bool *const	visited = (bool *) malloc(size * sizeof(bool));

	if (visited == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
		visited[i++] = false;
	return (visited);
}

void	bfs(t_graph *graph)
{
	t_deque	dq;
	t_node		*cur;
	int			vertex;
	bool *const	visited = get_visited_array(graph->size);

	dq_init(&dq);
	push_back(&dq, 0);
	visited[0] = true;
	while (is_empty(&dq) == false)
	{
		vertex = front(&dq);
		pop_front(&dq);
		ft_printf("%06d ", vertex);
		cur = graph->heads[vertex]->next;
		while (cur != NULL)
		{
			if (visited[cur->id] == false)
			{
				push_back(&dq, cur->id);
				visited[cur->id] = true;
			}
			cur = cur->next;
		}
	}
}

void	dfs(t_graph *graph)
{
	t_deque	dq;
	t_node		*cur;
	int			vertex;
	bool *const	visited = get_visited_array(graph->size);

	dq_init(&dq);
	push_front(&dq, 0);
	visited[0] = true;
	while (is_empty(&dq) == false)
	{
		vertex = front(&dq);
		pop_front(&dq);
		ft_printf("%06d ", vertex);
		cur = graph->heads[vertex]->next;
		while (cur != NULL)
		{
			if (visited[cur->id] == false)
			{
				push_front(&dq, cur->id);
				visited[cur->id] = true;
			}
			cur = cur->next;
		}
	}
}
