/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_probing_Q.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:19:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:19:31 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5			// 배열의 최대길이  
#define TABLE_SIZE	7	// 해싱 테이블의 크기=소수 
#define INIT -1			// 해싱 테이블의 초기값 -1

int count; //충돌 횟수

typedef struct {
	int key;
} element;

element hash_table[TABLE_SIZE];		// 해싱 테이블 

void init_table(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key = INIT;
	}
}
// 제산 함수를 사용한 해싱 함수
int hash_function(int key)
{
	// 키를 다음 테이블의 크기로 나누어 나머지를 반환
	return key % TABLE_SIZE;
}

// 선형 조사법을 이용하여 테이블에 키를 삽입하고, 
// 테이블이 가득 찬 경우는 종료     
void hash_lp_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	
	printf("hash_address = %d\n", i);
	do
	{
		if (ht[i].key == INIT)
		{
			ht[i] = item;
			printf("인덱스 %d에 insert item %d\n", i, item.key);
			return;
		}
		printf("인덱스 %d에서 충돌 발생. 충돌 횟수 = %d\n", i, ++count);
		i++;
		if (i == TABLE_SIZE)
			i = 0;
	} while (i != hash_value);
	printf("테이블이 가득찼습니다.\n");
}

// 선형조사법을 이용하여 테이블에 저장된 키를 탐색
void hash_lp_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	do
	{
		if (ht[i].key == item.key)
		{
			printf("탐색 %d: 위치 = %d\n", item.key, i);
			return;
		}
		i++;
		if (i == TABLE_SIZE)
			i = 0;
	} while (i != hash_value);
}

// 해싱 테이블의 내용을 출력
void hash_lp_print(element ht[])
{
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]	%d\n", i, ht[i].key);
	printf("===============================\n\n");
}


// 해싱 테이블을 사용한 예제 
int main(void)
{
	int data[SIZE] = { 8, 1, 9, 6, 13 };
	element e;
	init_table(hash_table);   //해싱 테이블 초기화

	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_lp_add(e, hash_table);
		hash_lp_print(hash_table);
	}
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_lp_search(e, hash_table);
	}
	return 0;
}