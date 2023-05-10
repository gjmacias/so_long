/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:52:53 by gmacias-          #+#    #+#             */
/*   Updated: 2023/05/10 17:38:29 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->wall, (*j) * 40, (*i) * 40);
}

void	put_empty_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->empty, (*j) * 40, (*i) * 40);
}

void	put_player_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->player, (*j) * 40, (*i) * 40);
	data->y = *i;
	data->x = *j;
}

void	ft_draw_map(t_info_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] && i <= 10)
	{
		j = 0;
		while (data->map[i][j] && j <= 50)
		{
			if (data->map[i][j] == '1')
				put_wall_img(data, &j, &i);
			else if (data->map[i][j] == '0')
				put_empty_img(data, &j, &i);
			else if (data->map[i][j] == 'P')
				put_player_img(data, &j, &i);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->collect, j * 40, i * 40);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->exit, j * 40, i * 40);
			j++;
		}
		i++;
	}
}
