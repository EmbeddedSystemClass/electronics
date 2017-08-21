/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:44:11 by alngo             #+#    #+#             */
/*   Updated: 2016/11/10 11:10:46 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		m;

	if (!(*s2))
		return ((char *)s1);
	while (*s1 && n > 0)
	{
		i = 0;
		if (*s1 == s2[i])
		{
			m = n;
			while (s1[i] == s2[i] && s2[i] && s1[i] && m > 0)
			{
				m--;
				i++;
			}
			if (s2[i] == '\0')
				return ((char *)s1);
		}
		s1++;
		n--;
	}
	return (NULL);
}
