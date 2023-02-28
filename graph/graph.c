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

void	graph_init(t_graph *graph, size_t size)
{
	size_t	i;

	graph->size = size;
	graph->heads = (t_graph_node **) malloc(size * sizeof(t_graph_node *));
	assert(graph->heads != NULL);
	i = 0;
	while (i < size)
	{
		graph->heads[i] = (t_graph_node *) malloc(sizeof(t_graph_node));
		assert(graph->heads[i] != NULL);
		graph->heads[i]->next = NULL;
		++i;
	}
}

void	graph_destroy(t_graph *graph)
{
	size_t			i;
	t_graph_node	*cur;
	t_graph_node	*temp;

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

t_graph_node	*graph_create_node(int id)
{
	t_graph_node *const	new_node = \
		(t_graph_node *) malloc(sizeof(t_graph_node));

	assert(new_node != NULL);
	new_node->id = id;
	new_node->next = NULL;
	return (new_node);
}

void	graph_add_edge(t_graph *graph, int src, int dst)
{
	t_graph_node		*cur;
	t_graph_node *const	new_node1 = graph_create_node(src);
	t_graph_node *const	new_node2 = graph_create_node(dst);

	cur = graph->heads[dst];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node1;
	cur = graph->heads[src];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node2;
}

void	graph_print(t_graph *graph)
{
	size_t			i;
	t_graph_node	*cur;

	i = 0;
	while (i < graph->size)
	{
		cur = graph->heads[i]->next;
		printf("Head #%ld ", i);
		while (cur != NULL)
		{
			printf("%06d", cur->id);
			cur = cur->next;
		}
		printf("\n");
		++i;
	}
}
