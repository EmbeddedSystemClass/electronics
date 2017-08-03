/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:36:21 by alngo             #+#    #+#             */
/*   Updated: 2016/11/03 15:51:12 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_sqrt(int nb)
{
	int result;

	result = 1;
	while (result * result != nb && result < (nb / 2))
		result++;
	if (result * result == nb)
		return (result);
	else
		return (0);
}
