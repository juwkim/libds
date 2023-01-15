/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   murmurhash3_x86_32.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 07:44:45 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/15 10:03:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MURMURHASH3_X86_32_H
# define MURMURHASH3_X86_32_H

# include <stdint.h>

# define X86_32_C1 0xcc9e2d51
# define X86_32_C2 0x1b873593
# define X86_32_C3 0xe6546b64

uint32_t	rotl32(uint32_t x, int8_t r);
uint32_t	fmix32(uint32_t h);

uint32_t	murmurhash3_x86_32_body(const uint32_t *blocks, const int nblocks, \
																uint32_t h1);
uint32_t	murmurhash3_x86_32_tail(const uint8_t *tail, const int len, \
															uint32_t h1);
uint32_t	murmurhash3_x86_32(const void *key, const int len, uint32_t seed);

#endif // MURMURHASH3_H
