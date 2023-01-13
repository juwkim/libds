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

// Create a graph.
void CreateGraph(Graph* pgraph, int size)
{
	pgraph->size = size;
	pgraph->heads = (GNode **) malloc(sizeof(GNode*) * size);
	if (pgraph->heads == NULL)
		exit(EXIT_FAILURE);

	for (int i = 0; i < size; ++i)
	{
		// Make a dummy node.
		pgraph->heads[i] = (GNode *) malloc(sizeof(GNode));
		if (pgraph->heads[i] == NULL)
			exit(EXIT_FAILURE);
		pgraph->heads[i]->next = NULL;
	}
}

// Destroy a graph.
void DestroyGraph(Graph* pgraph)
{
	for (int i = 0; i < pgraph->size; ++i)
	{
		GNode *cur = pgraph->heads[i];
		while (cur != NULL) {
			GNode *temp = cur;
			cur = cur->next;
			free(temp);
		}
	}
	free(pgraph->heads);
}

// Add an undirected edge from src to dest.
void AddEdge(Graph* pgraph, int src, int dest)
{
	GNode *newNode1 = (GNode *) malloc(sizeof(GNode));
	GNode *newNode2 = (GNode *) malloc(sizeof(GNode));
	if (newNode1 == NULL || newNode2 == NULL)
		exit(EXIT_FAILURE);

	newNode1->id = dest;
	newNode1->next = NULL;

	// Create a node for dest in src.
	GNode *cur = pgraph->heads[src]; 
	while (cur->next != NULL) // unsorted
		cur = cur->next; // parallel edges
	cur->next = newNode1;

	newNode2->id = src;
	newNode2->next = NULL;
	
	// Create a node for src in dest.
	cur = pgraph->heads[dest];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newNode2;
}

// Print a graph for each vertex.
void PrintGraph(Graph* pgraph)
{
	for (int i = 0; i < pgraph->size; ++i)
	{
		GNode *cur = pgraph->heads[i]->next;

		printf("Head #%d ", i);
		while (cur != NULL) {
			printf("%06d ", cur->id);
			cur = cur->next;
		}
		printf("\n");
	}
}

// Depth first search
void DFS(Graph* pgraph)
{
	stack stack;
	bool *visited = (bool *) malloc(sizeof(bool) * pgraph->size);
	if (visited == NULL)
		exit(EXIT_FAILURE);

	for (int i = 0; i < pgraph->size; i++)
		// Make all vertices unvisited.
		visited[i] = false;

	InitStack(&stack);
	// Push the initial vertex.
	Push(&stack, 0);

	while (!IsEmpty(&stack)) {
		GNode *cur;
		int vtx = Peek(&stack);
		Pop(&stack);

		// Skip if the vertex has been visited.
		if (visited[vtx] == true) continue;
		
		visited[vtx] = true;
		printf("%d ", vtx);

		// Push the vertex if it has not been visited.
		cur = pgraph->heads[vtx]->next;
		while (cur != NULL) {
			if (visited[cur->id] == false)
				Push(&stack, cur->id);
			cur = cur->next;
		}
	}
}
		
// Breadth first search
void BFS(Graph* pgraph)
{
	Queue queue;
	bool *visited = (bool *) malloc(sizeof(bool) * pgraph->size);
	if (visited == NULL)
		exit(EXIT_FAILURE);

	for (int i = 0; i < pgraph->size; i++)
		// Make all vertices unvisited.
		visited[i] = false;

	InitQueue(&queue);
	// Enqueue the initial vertex.
	EnQueue(&queue, 0);

	while (!IsQEmpty(&queue)) {
		GNode* cur;
		int vtx = QPeek(&queue);
		DeQueue(&queue);

		// Skip if the vertex has been visited.
		if (visited[vtx] == true) continue;

		visited[vtx] = true;
		printf("%d ", vtx);

		// Enqueue the vertex if it has been unvisited.
		cur = pgraph->heads[vtx]->next;
		while (cur != NULL) {
			if (visited[cur->id] == false)
				EnQueue(&queue, cur->id);
			cur = cur->next;
		}
	}
}
