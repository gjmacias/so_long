/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:57:18 by gmacias-          #+#    #+#             */
/*   Updated: 2023/02/21 17:01:02 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_info_map *data)
{
	(void)	*data;
	exit(EXIT_SUCCESS);
}

void	ft_game_result(t_info_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->images->winner,
		data->width * 40 / 2.4, data->hight * 40 / 4);
}
