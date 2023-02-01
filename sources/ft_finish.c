#include "so_long.h"

int	ft_exit(t_info_map * data)
{
	(void)	*data;
	exit(EXIT_SUCCESS);
}

void	ft_game_result(t_info_map * data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->graph->win,
			       data->width * 40 /2,4, data->higth * 40 / 4);
}
