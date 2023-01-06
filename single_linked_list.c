/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:47 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "single_linked_list.h"

// Make a list empty.
void InitList(LinkedList* plist)
{
	// Create a dummy node;
	plist->head = (Node*) malloc(sizeof(Node));
	if (plist->head == NULL)
		exit(EXIT_FAILURE);

	plist->head->next = NULL;
	plist->len = 0;
}

// Check whether the list is empty.
bool IsEmpty(LinkedList* plist)
{
	return plist->len == 0;
}

// Insert an item at the pos-th position.
void InsertMiddle(LinkedList* plist, int pos, Data item)
{
	if (pos < 0 || pos > plist->len)
		exit(EXIT_FAILURE);

	// Create a new node.
	Node *newNode = (Node*) malloc(sizeof(Node));
	if (newNode == NULL)
		exit(EXIT_FAILURE);

	newNode->item = item;
	newNode->next = NULL;

	// Move the cur pointer to the (pos - 1)-th position.
	Node* cur = plist->head;
	while (pos--)
		cur = cur->next;

	// Insert the new node to the pos-th position.
	newNode->next = cur->next;
	cur->next = newNode;
	plist->len++;
}

// Remove an item at the pos-th position.
void RemoveMiddle(LinkedList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(EXIT_FAILURE);

	// Move the cur pointer to the (pos - 1)-th position.
	Node *cur = plist->head;
	while (pos--)
		cur = cur->next;

	// Remove the node to the pos-th position.
	Node *temp = cur->next;
	cur->next = cur->next->next;
	plist->len--;
	free(temp);
}

void RemoveFirst(LinkedList* plist)
{
	if (IsEmpty(plist))
		exit(EXIT_FAILURE);

	Node* head = plist->head;
	Node* temp = head->next;

	head->next = head->next->next;
	plist->len--;
	free(temp);
}

// Read an item at the pos-th position.
Data ReadItem(LinkedList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(EXIT_FAILURE);

	// Move the cur pointer to the pos-th position.
	Node *cur = plist->head->next;
	while (pos--)
		cur = cur->next;

	return cur->item;
}

// Print each item in a list in sequence.
void PrintList(LinkedList* plist)
{
	Node* cur = plist->head->next;
	
	while (cur != NULL)
	{
		printf("%d\n", cur->item);
		cur = cur->next;
	}
}

// Remove all nodes in a list in sequence.
void ClearList(LinkedList* plist)
{
	while (plist->head->next != NULL)
		RemoveFirst(plist);
	free(plist->head);
}

LinkedList* Concatenate(LinkedList* plist1, LinkedList* plist2)
{
	if (plist1->head->next == NULL)
		return plist2;
	else if (plist2->head->next == NULL)
		return plist1;
	else
	{
		// Move the current pointer to the last position.
		Node* cur = plist1->head->next;
		while (cur->next != NULL)
			cur = cur->next;

		// Link the current pointer to the second list.
		cur->next = plist2->head->next;

		// Remove the dummy node from the second list.
		free(plist2->head);
		return plist1;
	}
}

// Make the list in reverse sequence.
void Reverse(LinkedList* plist)
{
	Node *prev = NULL;
	Node *cur = NULL;
	Node* next = plist->head->next;

	// Repeat the next node is NULL.
	while (next != NULL) {
		// Set the previous, current, and next nodes.
		prev = cur;
		cur = next;
		next = next->next;
		// Change the link of the current node.
		cur->next = prev;
	}
	// Connect the dummy node to the current node.
	plist->head->next = cur;
}
