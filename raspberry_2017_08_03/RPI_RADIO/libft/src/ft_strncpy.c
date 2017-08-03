/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:29:58 by alngo             #+#    #+#             */
/*   Updated: 2016/11/12 18:50:26 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	char		*tmpd;

	if (n == 0)
		return (dest);
	tmpd = dest;
	while (*src && n--)
		*tmpd++ = *src++;
	if (!(*src) && n)
		while (n--)
			*tmpd++ = '\0';
	return (dest);
}
