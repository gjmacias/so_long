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

void	ft_map_size(t_info_map *data)
{
	char	*line;
	int		fd;

	fd = open(data->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		write(1, "Error\nMap not read\n", 19);
		exit (EXIT_FAILURE);
	}
	data->width = ft_strlen(line) - 1;
	data->hight = 0;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != data->width)
		{
			write(1, "Error\nMap not valid\n", 14);
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
	line = get_next_line(fd);
	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (data->hight));
	if (!data->map)
	{
		write(1, "Error\nMap not malloc\n", 15);
		exit (EXIT_FAILURE);
	}
	while (i < data->hight)
	{
		data->map[i] = line;
		data->map[i][data->width] = '\0';
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	line = NULL;
	close(fd);
}
