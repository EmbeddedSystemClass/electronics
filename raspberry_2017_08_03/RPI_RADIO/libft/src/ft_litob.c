/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:12:49 by alngo             #+#    #+#             */
/*   Updated: 2017/07/25 21:01:32 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			length_s(uintmax_t n, int base)
{
	size_t				i;

	i = 0;
	if (!(n))
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char					*ft_litob(uintmax_t n, t_arg *arg, int base, char *s)
{
	char				*tmp;
	int					pos;
	uintmax_t			dat;

	dat = arg->n;
	dat = dat ? dat : dat;
	if (!(tmp = ft_strnew(length_s(n, base))))
		return (NULL);
	pos = length_s(n, base);
	if (!(n))
		tmp[--pos] = '0';
	while (n != 0)
	{
		tmp[--pos] = s[n % base];
		n = n / base;
	}
	return (tmp);
}
