/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:18:44 by alngo             #+#    #+#             */
/*   Updated: 2017/07/26 12:49:54 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf.h"
# define ABS(Value)	(Value < 0 ? -Value : Value)
# define WCHAR_07BITS 	0x0
# define WCHAR_11BITS 	0xC080
# define WCHAR_16BITS 	0xE08080
# define WCHAR_21BITS 	0xF0808080

/*
**_____STRUCTURE_DEFINITION_____
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_div
{
	int				q;
	int				r;
}					t_div;

typedef struct		s_ldiv
{
	long			q;
	long			r;
}					t_ldiv;

typedef struct		s_wchart
{
	wchar_t			all;
	int				len;
	unsigned char	c;
}					t_wchart;

/*
**_____STRING_DIR_____
*/
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(char const *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
/*
**_____STDLIB_DIR_____
*/
int					ft_abs(int n);
long				ft_labs(long n);
t_div				ft_div(int n, int d);
t_ldiv				ft_ldiv(long n, long d);
int					ft_atoi(const char *s);
long				ft_atol(const char *s);
/*
**_____CTYPE_DIR_____
*/
int					ft_isdigit(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*
**_____LST_P_DIR_____
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstat(t_list *lst, size_t n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newelem);
void				ft_lstaddafter(t_list **alst, t_list *newelem);
size_t				ft_lstcount(t_list *lst);
/*
**_____STR_P_DIR_____
*/
char				*ft_strdup(char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strcasestr(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrenew(char *s, size_t n);
void				ft_chachange(char *s, char t, char c);
int					ft_foreachar(const char *s, int (*f)(int));
int					ft_strlenchr(char *s, char c);
/*
**_____PUT_P_DIR_____
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putstrtab(char **tab, size_t n);
void				ft_putnstr_fd(char *s, size_t n, int fd);
void				ft_putinttab(int **tab, int c, size_t x, size_t y);
int					ft_putwchar(wchar_t c);
int					ft_putwchar_fd(wchar_t c, int fd);
void				ft_putnchar(size_t n, int c);
/*
**_____MEM_P_DIR_____
*/
void				*ft_memalloc(size_t size);
void				*ft_memrealloc(void *ap, size_t n);
void				ft_memdel(void **ap);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				ft_bzero(void *s, size_t n);
/*
**_____MATH_P_DIR_____
*/
int					ft_sqrt(int nb);
int					ft_iterative_factorial(int nb);
void				ft_foreach(int *tab, int length, void (*f)(int));
/*
**_____PERS_P_DIR_____
*/
int					get_next_line(const int fd, char **line);
void				miniprintf(const char *fmt, ...);
void				print_memory(const void *addr, size_t size);
/*
**_____CONV_P_DIR_____
*/
char				*ft_itoa_base(int n, int base, char *s);
char				*ft_itoa(int n);
/*
**_______WCHAR_C_________
*/
int					xseg_wchart(t_wchart *w, wchar_t c);

#endif
