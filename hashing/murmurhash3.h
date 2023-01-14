/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   murmurhash3.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 07:08:59 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/15 07:24:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MURMURHASH3_H
# define MURMURHASH3_H

# include <stdint.h>

//-----------------------------------------------------------------------------

void	murmurhash3_x86_32( const void *key, int len, uint32_t seed, void *out);

void	murmurhash3_x86_128( const void *key, int len, uint32_t seed, void *out);

void	murmurhash3_x64_128( const void *key, int len, uint32_t seed, void *out);

//-----------------------------------------------------------------------------

#endif // MURMURHASH3_H
