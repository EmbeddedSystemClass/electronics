/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:25:28 by alngo             #+#    #+#             */
/*   Updated: 2017/06/28 22:32:53 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*get_p(const int fd, t_gnl **lst)
{
	t_gnl			*tmp;
	t_gnl			*pos;

	tmp = *lst;
	pos = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		pos = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	tmp->fd = fd;
	tmp->str = NULL;
	tmp->next = NULL;
	if (pos)
		return ((pos->next = tmp));
	*lst = tmp;
	return (tmp);
}

static void			del_p(const int fd, t_gnl **lst, char **line)
{
	t_gnl			*tmp;
	t_gnl			*bef;
	t_gnl			*aff;

	tmp = *lst;
	bef = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		bef = tmp;
		tmp = tmp->next;
	}
	aff = tmp->next;
	free(tmp);
	if (bef)
		bef->next = aff;
	*lst = bef;
	*line = NULL;
}

static int			stack(char **s, char **line, int ret)
{
	char			*tmp;

	if ((tmp = ft_strchr(*s, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*s);
		tmp = ft_strdup(tmp + 1);
		free(*s);
		*s = tmp;
		return (1);
	}
	if (**s && ret < BUFF_SIZE)
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (1);
	}
	if (!(**s) && !(ret))
	{
		free(*s);
		*s = NULL;
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*p;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !(line) || !(p = get_p(fd, &lst)))
		return (-1);
	while ((p->ret = read(fd, buf, BUFF_SIZE)) || (p->str))
	{
		if (p->ret == -1)
			return (-1);
		buf[p->ret] = '\0';
		if (p->ret)
		{
			tmp = ft_strjoin(p->str, buf);
			if (p->str)
				free(p->str);
			p->str = tmp;
		}
		if (stack(&(p->str), line, p->ret))
			return (1);
		ft_bzero(buf, BUFF_SIZE);
	}
	del_p(fd, &lst, line);
	return (0);
}
