/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   murmurhash3_x86_32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 08:31:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/15 10:06:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "murmurhash3_x86_32.h"

uint32_t	rotl32(uint32_t x, int8_t r)
{
	return ((x << r) | (x >> (32 - r)));
}

uint32_t	fmix32(uint32_t h)
{
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return (h);
}

uint32_t	murmurhash3_x86_32_body(const uint32_t *blocks, const int nblocks, \
																uint32_t h1)
{
	uint32_t		k1;
	int				i;

	i = -nblocks;
	while (i)
	{
		k1 = blocks[i] * X86_32_C1;
		k1 = rotl32(k1, 15) * X86_32_C2;
		h1 ^= k1;
		h1 = rotl32(h1, 13) * 5 + X86_32_C3;
		++i;
	}
	return (h1);
}

uint32_t	murmurhash3_x86_32_tail(const uint8_t *tail, const int len, \
															uint32_t h1)
{
	uint32_t	k1;
	const int	remainder = len & 3;

	k1 = 0;
	if (remainder >= 3)
		k1 ^= tail[2] << 16;
	if (remainder >= 2)
		k1 ^= tail[1] << 8;
	if (remainder >= 1)
	{
		k1 ^= tail[0];
		k1 = rotl32(k1 * X86_32_C1, 15);
		h1 ^= k1 * X86_32_C2;
	}
	h1 = fmix32(h1 ^ len);
	return (h1);
}

uint32_t	murmurhash3_x86_32(const void *key, const int len, uint32_t seed)
{
	uint32_t		h1;
	const int		nblocks = len / 4;
	const uint8_t	*data = (const uint8_t*) key;

	h1 = murmurhash3_x86_32_body((const uint32_t *)(data + nblocks * 4), \
													nblocks, seed);
	h1 = murmurhash3_x86_32_tail(data + nblocks * 4, len, h1);
	return (h1);
}
