/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

void	init(t_double_linked_list *list)
{
	t_node	*dummy1 = (t_node*) malloc(sizeof(t_node));
	t_node	*dummy2 = (t_node*) malloc(sizeof(t_node));

	if (dummy1 == NULL || dummy2 == NULL)
		exit(EXIT_FAILURE);

	dummy1->prev = NULL;
	dummy1->next = dummy2;
	
	dummy2->prev = dummy1;
	dummy2->next = NULL;
	
	list->head = dummy1;
	list->len = 0;
}

void InsertMiddle(t_double_linked_list* list, int pos, Data item)
{
	// Create a new t_node.
	t_node *newt_node = (t_node*) malloc(sizeof(t_node));
	if (newt_node == NULL)
		exit(EXIT_FAILURE);

	newt_node->item = item;
	newt_node->prev = NULL;
	newt_node->next = NULL;

	// Move the cur pointer to the (pos - 1)-th position.
	t_node *cur = list->head;
	while (pos--)
		cur = cur->next;

	// Insert the new t_node to the pos-th position.
	newt_node->prev = cur;
	newt_node->next = cur->next;
	cur->next->prev = newt_node;
	cur->next = newt_node;
	list->len++;
}

void RemoveMiddle(t_double_linked_list* list, int pos)
{
	if (list->len == 0 || pos < 0 || pos >= list->len)
		exit(EXIT_FAILURE);

	// Move the cur pointer to the (pos-1)-th position.
	t_node *cur = list->head;
	while (pos--)
		cur = cur->next;

	// Connect adjacent t_nodes to remove the pos-th t_node.
	t_node *temp = cur->next;
	temp->next->prev = cur;
	cur->next = temp->next;

	// Remove the t_node to the pos-th position.
	list->len--;
	free(temp);
}
