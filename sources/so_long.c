/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:05:15 by gmacias-          #+#    #+#             */
/*   Updated: 2023/05/09 18:31:44 by galo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_img(t_info_map *data)
{
	int	img_hight;
	int	img_width;

	data->images = malloc(sizeof(t_images));
	data->images->player = mlx_xpm_file_to_image(data->mlx,
			PLAYER, &img_width, &img_hight);
	data->images->wall = mlx_xpm_file_to_image(data->mlx,
			WALL, &img_width, &img_hight);
	data->images->empty = mlx_xpm_file_to_image(data->mlx,
			EMPTY, &img_width, &img_hight);
	data->images->exit = mlx_xpm_file_to_image(data->mlx,
			EXIT, &img_width, &img_hight);
	data->images->collect = mlx_xpm_file_to_image(data->mlx,
			COLLECT, &img_width, &img_hight);
	data->images->winner = mlx_xpm_file_to_image(data->mlx,
			WINNER, &img_width, &img_hight);
}

void	ft_reset_data(t_info_map *data, char *name)
{
	data->hight = 0;
	data->width = 0;
	data->x = 0;
	data->y = 0;
	data->player = 0;
	data->count = 0;
	data->step = 0;
	data->finish = 0;
	data->txt = name;
	ft_load_img(data);
}

void	ft_general_check(t_info_map *data)
{
	ft_check_outline(data);
	ft_check_format_dotber(data);
	ft_check_map_inputs(data);
	ft_check_map_objects(data);
}

int	ft_frame(t_info_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_draw_map(data);
	if (data->count == 0 && data->player == 1 && data->finish == 1)
		ft_game_result(data);
	return (0);
}

int	main(int words, char **arguments)
{
	t_info_map	data;

	if (words == 2)
	{
		data.mlx = mlx_init();
		ft_reset_data(&data, arguments[1]);
		ft_map_size(&data);
		ft_malloc_map(&data);
		ft_general_check(&data);
		data.win = mlx_new_window(data.mlx, data.width * 40,
				data.hight * 40, "so_long");
		mlx_hook(data.win, 17, 0, ft_exit, &data);
		mlx_hook(data.win, 02, 0, ft_press_key, &data);
		mlx_loop_hook(data.mlx, ft_frame, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
