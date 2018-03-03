/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 22:32:47 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/02 13:12:57 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int ac, char *av[])
{
	char	**files;
	char	**start;
	char	*line;
	int		*fds;
	int		i;
	int		j;

	if (ac < 2)
		return (1);
	i = 1;
	if (!(fds = (int *)ft_memalloc(sizeof(int) * (ac - 1))))
			return (1);
	if (!(files = (char **)ft_memalloc(sizeof(char *) * ac)))
		return (1);
	start = files;
	while (i < ac)
		*files++ = ft_strdup(av[i++]);
	files = start;
	i = 0;
	while (i < (ac - 1))
		if (!(fds[i++] = open(*files++, O_RDONLY)))
			return (1);
	j = 0;
	while (j++ < 4)
	{
		files = start;
		line = NULL;
		i = 0;
		while (*files && (i < (ac - 1)))
		{
			ft_putnbr(fds[i]);
			ft_putchar(' ');
			ft_putendl(*files++);
			ft_putnbr(get_next_line(fds[i++], &line));
			ft_putchar('\n');
			if (line)
			{
				ft_putendl(line);
				free(line);
			}
		}
	}
	i = 0;
	while (i < (ac - 1))
		close(fds[i++]);
	return (0);
}
