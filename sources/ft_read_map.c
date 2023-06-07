/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:03:23 by gmacias-          #+#    #+#             */
/*   Updated: 2023/05/10 17:37:51 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_bad_malloc(void)
{
	write(2, "Error\nMap not malloc\n", 21);
	exit (EXIT_FAILURE);
}

void	ft_map_size(t_info_map *data)
{
	char	*line;
	int		fd;

	fd = open(data->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nMap not read\n", 19);
		exit (EXIT_FAILURE);
	}
	data->width = ft_strlen(line) - 1;
	data->hight = 0;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != data->width)
		{
			write(2, "Error\nMap not valid\n", 20);
			exit (EXIT_FAILURE);
		}
		data->hight++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_malloc_map(t_info_map *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (data->hight));
	if (!data->map)
		ft_bad_malloc();
	while (i < data->hight)
	{
		line = get_next_line(fd);
		if (!line)
			ft_bad_malloc();
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			ft_bad_malloc();
		data->map[i][data->width] = '\0';
		i++;
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}
