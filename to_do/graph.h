/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:15 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <stdlib.h>

# include "stack.h"
# include "queue.h"

typedef struct _GNode
{
	int id;
	struct _GNode* next;
} GNode;

typedef struct
{
	int size;
	GNode** heads;
} Graph;

// Create a graph.
void CreateGraph(Graph* pgraph, int size);

// Destroy a graph.
void DestroyGraph(Graph* pgraph);

// Add an undirected edge from src to dest.
void AddEdge(Graph* pgraph, int src, int dest);

// Print a graph for each vertex.
void PrintGraph(Graph* pgraph);

// Depth first search
void DFS(Graph* pgraph);
		
// Breadth first search
void BFS(Graph* pgraph);

#endif
