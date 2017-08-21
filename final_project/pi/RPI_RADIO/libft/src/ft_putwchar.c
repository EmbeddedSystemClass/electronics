/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:14:42 by alngo             #+#    #+#             */
/*   Updated: 2017/06/05 15:38:46 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				xfill_wchart(t_wchart *w, wchar_t c, int shape, int i)
{
	w->all = shape;
	w->len = i;
	if (i == 1)
	{
		w->all = w->all | c;
		return (1);
	}
	while (i)
	{
		w->all = w->all | ((c >> (6 * (i - 1))) & 63) << (8 * (i - 1));
		i--;
	}
	return (1);
}

static int				xft_putwchar(t_wchart *w, wchar_t c)
{
	w->len = 0;
	while (c >> w->len)
		w->len++;
	if (w->len > 21)
		return (0);
	if (w->len <= 7)
		return (xfill_wchart(w, c, WCHAR_07BITS, 1));
	else if (w->len > 7 && w->len <= 11)
		return (xfill_wchart(w, c, WCHAR_11BITS, 2));
	else if (w->len > 11 && w->len <= 16)
		return (xfill_wchart(w, c, WCHAR_16BITS, 3));
	else if (w->len > 16 && w->len <= 21)
		return (xfill_wchart(w, c, WCHAR_21BITS, 4));
	return (1);
}

int						ft_putwchar(wchar_t c)
{
	t_wchart	tmp;

	if (!(xft_putwchar(&tmp, c)))
		return (0);
	while (tmp.len)
	{
		tmp.c = (tmp.all >> ((tmp.len - 1) * 8));
		write(1, &tmp.c, 1);
		tmp.len--;
	}
	return (1);
}
