/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:01:53 by alngo             #+#    #+#             */
/*   Updated: 2016/11/09 18:35:15 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	tmp = ft_strnew(len);
	if (tmp != NULL)
	{
		i = 0;
		while ((i < len) && s[start + i])
		{
			tmp[i] = s[start + i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
