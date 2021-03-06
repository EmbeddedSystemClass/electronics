/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreachar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:27:54 by alngo             #+#    #+#             */
/*   Updated: 2017/01/15 16:27:55 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_foreachar(const char *s, int (*f)(int))
{
	while (*s)
	{
		if (!((*f)(*s)))
			return (0);
		s++;
	}
	return (1);
}
