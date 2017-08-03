/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:31:59 by alngo             #+#    #+#             */
/*   Updated: 2016/11/09 18:36:45 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char		*tmp;
	int			i;

	if (s == NULL)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s));
	if (tmp != NULL)
	{
		i = 0;
		while (*s)
		{
			tmp[i] = (*f)(*s++);
			i++;
		}
	}
	return (tmp);
}
