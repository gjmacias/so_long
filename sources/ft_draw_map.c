#include "so_long.h"

int	ft_exit(t_info_map *data)
{
	(void) *data;
	exit(EXIT_SUCCESS);
}

void	put_wall_img(t_init_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->wall, j * 40, i * 40);
}


void	put_empty_img(t_init_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->empty, j * 40, i * 40);
}

void	put_player_img(t_init_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->player, j * 40, i * 40);
}

void	ft_draw_map(t_info_map *data)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_wall_img(data, &i, &j);
			else if (data->map[i][j] == '0')
				put_empty_img(data, &i, &j);
			else if (data->map[i][j] == 'P')
				put_player_img(data, &i, &j);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->graph->collect, j * 40, i * 40);			
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->graph->exit, j * 40, i * 40);
			j++;
		}
	}
	j = 0;
	i++;
}
