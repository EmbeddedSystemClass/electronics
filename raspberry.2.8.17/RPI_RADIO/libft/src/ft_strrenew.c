/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:21:19 by alngo             #+#    #+#             */
/*   Updated: 2016/11/29 14:21:34 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrenew(char *s, size_t n)
{
	char			*tmp;

	if (!(s) && n)
		return (ft_strnew(n));
	else if (s && !(n))
		ft_strdel(&s);
	else if (s && n)
	{
		if ((tmp = ft_strnew(n)))
			return (NULL);
		tmp = ft_strcpy(tmp, s);
		ft_strdel(&s);
		s = tmp;
	}
	return (s);
}
