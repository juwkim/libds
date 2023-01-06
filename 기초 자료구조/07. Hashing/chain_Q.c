/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_Q.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:19:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:19:25 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5
#define TABLE_SIZE	7	// 해싱 테이블의 크기=소수 

int collision_count; //충돌 횟수


typedef struct {
	int key;
} element;

struct list
{
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE];

// 제산 함수를 사용한 해싱 함수
int hash_function(int key)
{
	return key % TABLE_SIZE;
}

// 체인법을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node = ht[hash_value];

	if (node == NULL)
	{
		ht[hash_value] = malloc(sizeof(struct list));
		if (ht[hash_value] == NULL)
			return;
		ht[hash_value]->item = item;
		ht[hash_value]->link = NULL;
		return;
	}
	while (1)
	{
		printf("인덱스 %d에서 충돌 발생. 충돌 횟수 = %d\n", hash_value, ++collision_count);
		if (node->item.key == item.key)
		{
			printf("인덱스 %d에서 탐색키가 중복되었습니다.\n", hash_value);
			return;
		}
		if (node->link == NULL)
		{
			struct list* new = malloc(sizeof(struct list));
			if (new == NULL)
				return;
			new->item = item;
			new->link = NULL;
			node->link = new;
			return;
		}
		node = node->link;
	}
}

// 체인법을 이용하여 테이블에 저장된 키를 탐색
void hash_chain_search(element item, struct list* ht[])
{
	int search_count = 1; // 탐색 횟수
	int hash_value = hash_function(item.key);
	struct list* node = ht[hash_value];

	while (node && node->item.key != item.key)
	{
		node = node->link;
		++search_count;
	}

	if (node == NULL)
		printf("키를 찾지 못했음\n");
	else
		printf("탐색 %d 성공 탐색 횟수: %d 번\n", item.key, search_count);
}

// 해싱 테이블의 내용을 출력
void hash_chain_print(struct list* ht[])
{
	struct list* node;
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++) {
		printf("[%d]->", i);
		for (node = ht[i]; node; node = node->link) {
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("===============================\n\n");
}


// 해싱 테이블을 사용한 예제 
int main(void)
{
	int data[SIZE] = { 8, 1, 9, 6, 13 };
	element e;

	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}
	return 0;
}