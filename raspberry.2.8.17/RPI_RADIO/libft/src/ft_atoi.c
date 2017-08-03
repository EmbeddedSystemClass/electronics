/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:57:57 by alngo             #+#    #+#             */
/*   Updated: 2016/11/04 15:21:25 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int i;
	int min;
	int result;

	i = 0;
	min = 1;
	result = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		min = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		result = (result * 10) + (s[i] - 48);
		i++;
	}
	return (result * min);
}
