/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:02:32 by alngo             #+#    #+#             */
/*   Updated: 2016/11/07 12:02:58 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*tmpd;
	const char	*tmps;
	size_t		i;

	tmpd = (char *)dest;
	tmps = (const char *)src;
	i = 0;
	while (i < n && *tmps != c)
	{
		*tmpd++ = *tmps++;
		i++;
	}
	if (i < n)
	{
		*tmpd++ = *tmps++;
		return ((void *)tmpd);
	}
	else
		return (NULL);
}
