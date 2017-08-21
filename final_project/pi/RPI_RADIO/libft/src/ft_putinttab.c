/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:46:52 by alngo             #+#    #+#             */
/*   Updated: 2017/01/15 18:37:19 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putinttab(int **tab, int c, size_t x, size_t y)
{
	size_t			i;
	size_t			j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
