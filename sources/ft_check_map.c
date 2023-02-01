#include "so_long.h"

void	ft_check_outline(t_info_map *data)
{
	int	i;
	int	err;
	
	i = 0;
	err = 0;
	while(i < data->width)
	{
		if(data->map[0][i] != '1' || data->map[data->width - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while(i < data->height)
	{
		if(data->map[i][0] != '1' || data->map[i][data->height - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
	{
		write(1,"Map outline bad\n",17);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_format_dotber(t_info_map *data)
{
	if (ft_strcmpr(&data->txt[ft_strlen(data->txt) - 4],".ber") != 0
		|| ft_strlen(data->txt) =< 4)
	{
		write(1,"Bad extension\n",14);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_map_inputs(t_info_map *data)
{
	int	i;
	int	j;

	j = 0;
	while (map->data[j])
	{
		i = 0;
		while (map->data[j][i])
		{
			if (data->map[j][i] != '1' && data->map[j][i] != '0'
				&& data->map[j][i] != 'C' && data->map[j][i] != 'P'
				&& data->map[j][i] != 'E')
			{
				write(1,"Bad map inputs\n",15);
				exit (EXIT_FAILURE);
			}
			else
			i++;
		}
		j++;
	}
	
}

void	ft_check_map_objects(t_info_map *data)
{
	int	objects[3];
	int	i;
	int	j;
	
	objects[0] = 0;
	objects[1] = 0;
	objects[2] = 0;
	j = 0;
	while (map->data[j])
	{
		i = 0;
		while (map->data[j][i])
		{
			if (data->map[j][i] == 'P')
				objects[0]++;
			if (data->map[j][i] == 'C')
				objects[1]++;
			if (data->map[j][i] == 'E')
				objects[2]++;
			i++;
		}
		j++;
	}
	if (objects[0] != 1 || objects[1] < 1 ||9 objects[2] != 1)
	{
		write(1,"Bad map inputs\n",15);
		exit (EXIT_FAILURE);
	}
}
