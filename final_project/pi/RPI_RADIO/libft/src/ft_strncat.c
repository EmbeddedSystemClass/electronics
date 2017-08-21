/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:04:05 by alngo             #+#    #+#             */
/*   Updated: 2016/11/09 17:44:45 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *dest, const char *src, size_t n)
{
	char		*tmpd;
	const char	*tmps;

	tmpd = dest;
	tmps = src;
	while (*dest != '\0')
		dest++;
	while (*tmps && n > 0)
	{
		*dest = *tmps;
		dest++;
		tmps++;
		n--;
	}
	*dest++ = '\0';
	return (tmpd);
}
