/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:09:51 by alngo             #+#    #+#             */
/*   Updated: 2016/11/10 16:47:57 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*tmpd;
	const char		*tmps;
	size_t			n;
	size_t			dlen;

	tmpd = dest;
	tmps = src;
	n = size;
	while (n-- && *tmpd)
		tmpd++;
	dlen = tmpd - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(tmps));
	while (*tmps)
	{
		if (n > 1)
		{
			*tmpd++ = *tmps;
			n--;
		}
		tmps++;
	}
	*tmpd = '\0';
	return (dlen + (tmps - src));
}
