/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:11 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

// Create a new node.
BTreeNode* CreateNode(BData key)
{
	BTreeNode *node = (BTreeNode *) malloc(sizeof(BTreeNode));
	if (node == NULL)
		exit(EXIT_FAILURE);

	node->key = key;
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

// Destroy a node.
void DestroyNode(BTreeNode *node)
{
	free(node);
}

// Conect the root to a left-side node.
void CreateLeftSubtree(BTreeNode* root, BTreeNode* left)
{
	if (root->left_child != NULL)
		exit(EXIT_FAILURE);
	root->left_child = left;
}

// Conect the root to a right-side node.
void CreateRightSubtree(BTreeNode* root, BTreeNode* right)
{
	if (root->right_child != NULL)
		exit(EXIT_FAILURE);
	root->right_child = right;
}

// # of nodes from the node
int Nodes(BTreeNode* node)
{
	int r = 0;
	int l = 0;

	if (node->right_child != NULL)
		r = Nodes(node->right_child);
	if (node->left_child != NULL)
		l = Nodes(node->left_child);

	return r + l + 1;
}

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int Height(BTreeNode* node)
{
	int r = 0;
	int l = 0;

	if (node->right_child != NULL)
		r = Height(node->right_child);
	if (node->left_child != NULL)
		l = Height(node->left_child);

	return Max(r, l) + 1;
}

void Inorder(BTreeNode* root)
{
	if (root != NULL) {
		Inorder(root->left_child);
		printf("%d ", root->key);
		Inorder(root->right_child);
	}
}

void Preorder(BTreeNode* root)
{
	if (root != NULL) {
		printf("%d ", root->key);
		Preorder(root->left_child);
		Preorder(root->right_child);
	}
}

void Postorder(BTreeNode* root)
{
	if (root != NULL) {
		Postorder(root->left_child);
		Postorder(root->right_child);
		printf("%d ", root->key);
	}
}

void Levelorder(BTreeNode* root)
{
	Queue queue;
	if (root == NULL)
		return;

	InitQueue(&queue);
	EnQueue(&queue, root);
	while (!IsEmpty(&queue)) {
		root = Peek(&queue);
		DeQueue(&queue);
		printf("%d ", root->key);
		if (root->left_child != NULL)
			EnQueue(&queue, root->left_child);
		if (root->right_child != NULL)
			EnQueue(&queue, root->right_child);
	}
}

void Remove(BTreeNode* root, BData key)
{
	BTreeNode* cur = root;
	BTreeNode* parent = NULL;

	// Find the current node and its parent node.
	while (cur != NULL && cur->key != key)
	{
		parent = cur; // Update the parent node.
		if (cur->key > key)
			cur = cur->left_child;
		else
			cur = cur->right_child;
	}

	if (cur == NULL)
		exit(EXIT_FAILURE);

	if (cur->left_child == NULL && cur->right_child == NULL)
	{
		if (parent == NULL)
			cur = NULL; // The current node is the root.
		else
		{
			// Remove the current node depending on its position.
			if (parent->left_child == cur)
				parent->left_child = NULL;
			else
				parent->right_child = NULL;
		}
	}
	else if (cur->left_child == NULL || cur->right_child == NULL)
	{
		BTreeNode* child;
		// Replace a node with its child node.
		if (cur->left_child != NULL)
			child = cur->left_child;
		else
			child = cur->right_child;

		// Replace the child node of its parent node.
		if (parent != NULL)
		{
			if (parent->left_child == cur)
				parent->left_child = child;
			else
				parent->right_child = child;
		}
	}
	else
	{
		BTreeNode* succ_parent = cur;
		BTreeNode* succ = cur->right_child;

		// Find the successor (left-most node of the current node.)
		while (succ->left_child != NULL)
		{
			succ_parent = succ;
			succ = succ->left_child;
		}
		
		// If the successor has a child, update its the child node.
		if (succ_parent->right_child == succ)
			succ_parent->right_child = succ->right_child;
		else
			succ_parent->left_child = succ->right_child;

		cur->key = succ->key;
		cur = succ; // remove the seccessor.
	}
	free(cur);
}
