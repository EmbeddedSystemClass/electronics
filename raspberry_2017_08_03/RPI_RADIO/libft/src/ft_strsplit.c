/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:32:25 by alngo             #+#    #+#             */
/*   Updated: 2016/11/10 17:41:40 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		counter_w(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			count += 1;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static int		length_w(char const *s, char c)
{
	size_t		len;

	len = 0;
	while (*s++ != c)
		len++;
	return (len);
}

static char		**ft_split(char **tab, char const *s, char c)
{
	size_t		i;
	size_t		y;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			y = 0;
			tab[i] = (char *)malloc(sizeof(char) * (length_w(s, c) + 1));
			if (tab[i] == NULL)
				return (NULL);
			while (*s != c && *s)
				tab[i][y++] = *s++;
			tab[i++][y] = '\0';
		}
	}
	tab[i] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;

	if (s == NULL)
		return (NULL);
	if ((tab = (char **)malloc(sizeof(char *) * (counter_w(s, c) + 1))) == NULL)
		return (NULL);
	return (ft_split(tab, s, c));
}
