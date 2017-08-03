/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:32:39 by alngo             #+#    #+#             */
/*   Updated: 2016/11/09 18:36:12 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		n;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (ft_isspace(s[n]) && n > 0)
		n--;
	return (ft_strsub(s, i, ((n - i) + 1)));
}
