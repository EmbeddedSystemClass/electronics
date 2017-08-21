/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:07:02 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 12:50:03 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft.h"

# define SP 	1
# define PL 	2
# define MI 	4
# define SH 	8
# define ZE 	16
# define TY_H 	1
# define TY_HH 	2
# define TY_L 	3
# define TY_LL 	4
# define TY_J 	5
# define TY_Z 	6

typedef struct		s_arg
{
	uintmax_t		n;
	intmax_t		nb;
	char			*s;
	char			spec;
	char			dot;
	size_t			width;
	size_t			prec;
	short			flags;
	short			type;
	size_t			length;
	size_t			limit;
	size_t			tmp;
	char			warn;
	char			att;
	int				wild;
}					t_arg;

/*
**_______FT_PRINTF_C____
*/
int					ft_printf(const char *fmt, ...);
/*
**_______FT_XPRINTF_C____
*/
int					ft_xprintf(const char *fmt, va_list *args, int fd);
/*
**_______UTILS_C________
*/
int					isspec(char c, t_arg *arg);
int					isparsable(char c);
void				pad(char c, size_t n, size_t *len);
void				push_tmp(char *tmp, t_arg *arg, size_t *len, size_t size);
/*
**_______PARSER_C________
*/
char				*parse(const char *s, t_arg *arg, va_list *ap);
/*
**_______LITOB_C________
*/
char				*ft_litob(uintmax_t n, t_arg *arg, int base, char *s);
/*
**_______HANDLER_________
*/
void				handle_percent(t_arg *arg, size_t *len);
void				handle_character(t_arg *arg, va_list *ap, size_t *len);
void				handle_string(t_arg *arg, va_list *ap, size_t *len);
void				handle_decimal(t_arg *arg, va_list *ap, size_t *len);
void				handle_pointer(t_arg *arg, va_list *ap, size_t *len);
void				handle_hexadecimal(t_arg *arg, va_list *ap, size_t *len);
void				handle_octal(t_arg *arg, va_list *ap, size_t *len);
void				handle_unsigned(t_arg *arg, va_list *ap, size_t *len);
void				handle_binary(t_arg *arg, va_list *ap, size_t *len);
void				handle_upper(t_arg *arg, va_list *ap, size_t *len);

#endif
