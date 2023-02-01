#include "so_long.h"

int	ft_exit(t_info_map *data)
{
	(void) *data;
	exit(EXIT_SUCCESS);
}

void	put_player_img()

void	ft_view_map(t_info_map *data)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == '1')
			put_wall_img(data, &i, &j);
		else if (data->map[i][j] == '0')
			put_empty_img(data, &i, &j);
		else if (data->map[i][j] == 'P')
			put_player_img(data, &i, &j);
		else if (data->map[i][j] == 'C')
			put_empty_img(data, &i, &j);
		else if (data->map[i][j] == 'E')
			put_empty_img(data, &i, &j);
	}
}
