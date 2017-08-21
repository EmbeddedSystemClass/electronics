/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:20:57 by alngo             #+#    #+#             */
/*   Updated: 2016/11/29 14:21:03 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memrealloc(void *ap, size_t n)
{
	void			*tmp;

	if (!(ap))
		return (ft_memalloc(n));
	if (!(n))
	{
		if (ap)
			free(ap);
		return (NULL);
	}
	if (!(tmp = ft_memalloc(n)))
		return (NULL);
	ft_memcpy(tmp, ap, n);
	free(ap);
	return (tmp);
}
