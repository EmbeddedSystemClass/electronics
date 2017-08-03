/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:57:07 by alngo             #+#    #+#             */
/*   Updated: 2016/11/09 18:36:53 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s));
	if (tmp != NULL)
	{
		i = 0;
		while (*s)
		{
			tmp[i] = (*f)(i, *s++);
			i++;
		}
	}
	return (tmp);
}
