/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:03:50 by alngo             #+#    #+#             */
/*   Updated: 2016/11/09 13:44:41 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *dest, const char *src)
{
	char		*tmpd;

	tmpd = dest;
	while (*dest != '\0')
		dest++;
	ft_strcpy(dest, src);
	return (tmpd);
}
