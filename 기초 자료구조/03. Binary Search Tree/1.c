/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:45 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
#define max(a,b) (((a) > (b)) ? (a) : (b))

typedef int element;
typedef struct TreeNode
{
	element			key;
	struct TreeNode	*left;
	struct TreeNode	*right;
} TreeNode;

typedef struct
{
	TreeNode	*data[MAX_QUEUE_SIZE];
	int			front;
	int			rear;
} Queue;

void enqueue(Queue	*queue, TreeNode *node) {
	if (node)
		queue->data[++queue->rear] = node;
}

TreeNode	*dequeue(Queue* queue) {
	return queue->data[++queue->front];
}

int isempty(Queue* queue)
{
	return queue->front == queue->rear;
}

void level_order(TreeNode* node) {
	if (node == NULL)
		return;

	Queue queue;
	queue.front = 0;
	queue.rear = 0;
	enqueue(&queue, node);

	while (!isempty(&queue))
	{
		TreeNode	*node = dequeue(&queue);
		printf("[%d] ", node->key);
		enqueue(&queue, node->left);
		enqueue(&queue, node->right);
	}
}

void insert_node(TreeNode **root, int key)
{
	TreeNode* parent = NULL;
	TreeNode	*cur = *root;

	while (cur) {
		if (key == cur->key)
			return;
		parent = cur;
		if (key < cur->key)
			cur = cur->left;
		else
			cur = cur->right;
	}
	TreeNode* new_node = malloc(sizeof(TreeNode));
	if (new_node == NULL)
		return;

	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent)
		if (key < parent->key )
			parent->left = new_node;
		else
			parent->right = new_node;
	else
		*root = new_node;
}

TreeNode	*minValueNode(TreeNode	*node) {
	TreeNode	*cur = node;
	while (cur && cur->left)
		cur = cur->left;
	return cur;
}
TreeNode	*delete_node(TreeNode *root, int key)
{ 
	TreeNode	*temp;
	if (root == NULL)
		return root;  
	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

TreeNode* search(TreeNode* node, int key)
{
	while (node) {
		if (key == node->key)
			return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}

int	get_height(TreeNode	*node)
{
	if (node == NULL)
		return 0;
	return 1 + max(get_height(node->left), get_height(node->right));
}

int	get_node_count(TreeNode * node)
{
	if (node == NULL)
		return 0;
	return 1 + get_node_count(node->left) + get_node_count(node->right);
}

void preorder(TreeNode *node)
{
	if (node == NULL)
		return;
	printf("[%d] ", node->key);
	preorder(node->left);
	preorder(node->right);
}

void inorder(TreeNode* node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	printf("[%d] ", node->key);
	inorder(node->right);
}

void postorder(TreeNode* node)
{
	if (node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("[%d] ", node->key);
}

int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	int x;
	printf("이진 탐색 트리에 삽입할 key를 입력하시오:(음수를 입력하면 삽입 종료)");
	while (scanf("%d", &x) && (x >= 0))
	{
		insert_node(&root, x);
		printf("이진 탐색 트리에 삽입할 key를 입력하시오:(음수를 입력하면 삽입 종료)");
	}
	printf("\n이진 탐색 트리 전위 순회 결과 \n");
	preorder(root);
	printf("\n\n");

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");

	printf("이진 탐색 트리 후위 순회 결과 \n");
	postorder(root);
	printf("\n\n");

	printf("이진 탐색 트리 레벨 순회 결과 \n");
	level_order(root);
	printf("\n\n");

	printf("이진 탐색 트리에서 탐색할 key를 입력하시오:");
	if (scanf("%d", &x))
	{
		if (search(root, x) != NULL)
			printf("이진 탐색 트리 탐색: %d 탐색 성공\n", x);
		else
			printf("이진 탐색 트리 탐색: %d 탐색 실패 \n", x);
	}

	printf("\n이진 탐색 트리의 높이: %d\n", get_height(root));
	printf("이진 탐색 트리의 노드 개수: %d\n", get_node_count(root));

	printf("\n이진 탐색 트리에서 삭제할 key를 입력하시오:(음수를 입력하면 종료)");
	while (scanf("%d", &x) && x >= 0) {
		root = delete_node(root, x);

		printf("삭제 후 이진 탐색 트리 전위 순회 결과 \n");
		preorder(root);
		printf("\n\n");

		printf("삭제 후 이진 탐색 트리 중위 순회 결과 \n");
		inorder(root);
		printf("\n\n");

		printf("삭제 후 이진 탐색 트리 후위 순회 결과 \n");
		postorder(root);
		printf("\n\n");

		printf("삭제 후 이진 탐색 트리 레벨 순회 결과 \n");
		level_order(root);
		printf("\n\n");

		printf("삭제 후 이진 탐색 트리의 높이: %d\n", get_height(root));
		printf("삭제 후 이진 탐색 트리의 노드 개수: %d\n", get_node_count(root));
		printf("\n이진 탐색 트리에서 삭제할 key를 입력하시오:(음수를 입력하면 종료)");
	}

	return 0;
}