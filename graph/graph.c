/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:12 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	init(t_graph *graph, size_t size)
{
	size_t	i;

	graph->size = size;
	graph->heads = (t_node **) malloc(size * sizeof(t_node *));
	if (graph->heads == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		graph->heads[i] = (t_node *) malloc(sizeof(t_node));
		if (graph->heads[i] == NULL)
			exit(EXIT_FAILURE);
		graph->heads[i]->next = NULL;
		++i;
	}
}

void	destroy(t_graph *graph)
{
	size_t	i;
	t_node	*cur;
	t_node	*temp;

	i = 0;
	while (i < graph->size)
	{
		cur = graph->heads[i];
		while (cur != NULL)
		{
			temp = cur;
			cur = cur->next;
			free(temp);
		}
		++i;
	}
	free(graph->heads);
}

t_node	*create_node(int id)
{
	t_node *const	new_node = (t_node *) malloc(sizeof(t_node));

	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->id = id;
	new_node->next = NULL;
	return (new_node);
}

void	add_edge(t_graph *graph, int src, int dst)
{
	t_node			*cur;
	t_node *const	new_node1 = create_node(src);
	t_node *const	new_node2 = create_node(dst);

	cur = graph->heads[dst];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node1;
	cur = graph->heads[src];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node2;
}

void	print(t_graph *graph)
{
	size_t	i;
	t_node	*cur;

	i = 0;
	while (i < graph->size)
	{
		cur = graph->heads[i]->next;
		ft_printf("Head #%d ", i);
		while (cur != NULL)
		{
			ft_printf("%06d", cur->id);
			cur = cur->next;
		}
		ft_printf("\n");
		++i;
	}
}
