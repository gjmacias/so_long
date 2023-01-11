#include "so_long.h"

void	ft_map_size(t_info_map *data)
{
	char	*line;
	int		fd;
	
	fd = open(data->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		write(1,"Map not read\n",13);
		exit (EXIT_FAILURE);
	}
	data->width = ft_strlen(line);
	data->height = 0;
	while(line)
	{
		if (ft_strlen(line) != data->width)
		{
			write(1,"Map not valid\n",14);
			exit (EXIT_FAILURE);
		}
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

v7oid	ft_malloc_map(t_info_map *data)
{
	char	*line;
	int		fd;
	int		i;
	
	fd = open(data->txt, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (data->height + 1));
	if (!data->map)
	{
		write(1,"Map not malloc\n",15);
		exit (EXIT_FAILURE);
	}
	while (i < data->height)
	{
		data->map[i] = line;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	line = NULL
	close(fd);
}
