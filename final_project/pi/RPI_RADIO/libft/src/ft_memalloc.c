/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:35:19 by alngo             #+#    #+#             */
/*   Updated: 2016/11/07 18:14:43 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	char		*tmp;

	tmp = (char *)malloc(size);
	if (tmp != NULL)
		ft_bzero(tmp, size);
	return (tmp);
}
