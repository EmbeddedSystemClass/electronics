/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chachange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:18:34 by alngo             #+#    #+#             */
/*   Updated: 2016/11/29 14:18:38 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_chachange(char *s, char t, char c)
{
	while (*s)
	{
		if (*s == t)
			*s = c;
		s++;
	}
}
