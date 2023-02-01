#include "so_long.h"

void	ft_reset_data(t_info_map *data, char *name)
{
	data->hight = 0;
	data->weight = 0;
	data->x = 0;
	data->y = 0;
	data->player = 0;
	data->step = 0;		//ver para que sirve
	data->txt = name;
}

int	main(int argc, char **argv)
{
	t_info_map	data;
	
	if (argc == 2)
	{
		data.mlx = mlx_init();
		ft_reset_data(&data, argv[1]);
		
	}
}
