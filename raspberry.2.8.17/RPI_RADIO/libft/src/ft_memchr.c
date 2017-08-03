/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:01:28 by alngo             #+#    #+#             */
/*   Updated: 2016/11/10 11:02:50 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmps;

	tmps = (unsigned char *)s;
	while (n > 0)
	{
		if (*tmps == (unsigned char)c)
			return ((void *)tmps);
		tmps++;
		n--;
	}
	return (NULL);
}
