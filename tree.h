/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:15 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include <stdio.h>
# include <stdlib.h>

# include "queue.h"

typedef int BData;
typedef struct _bTreeNode
{
	BData key;
	struct _bTreeNode *left_child;
	struct _bTreeNode *right_child;
} BTreeNode;

// Create a new node.
BTreeNode* CreateNode(BData key);

// Destroy a node.
void DestroyNode(BTreeNode *node);

// Conect the root to a left-side node.
void CreateLeftSubtree(BTreeNode* root, BTreeNode* left);

// Conect the root to a right-side node.
void CreateRightSubtree(BTreeNode* root, BTreeNode* right);

// # of nodes from the node
int Nodes(BTreeNode* node);

int Max(int a, int b);

// Height from the node
int Height(BTreeNode* node);

// Traversal
void Inorder(BTreeNode* root);
void Preorder(BTreeNode* root);
void Postorder(BTreeNode* root);
void Levelorder(BTreeNode* root);

// Remove key
void Remove(BTreeNode* root, BData key);

#endif
