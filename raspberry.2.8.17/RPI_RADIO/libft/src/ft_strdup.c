/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:07:30 by alngo             #+#    #+#             */
/*   Updated: 2016/11/08 15:11:08 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*tmp;
	int		i;

	tmp = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (tmp != NULL)
	{
		i = 0;
		while (src[i])
		{
			tmp[i] = src[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
