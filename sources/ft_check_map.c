/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:37:51 by gmacias-          #+#    #+#             */
/*   Updated: 2023/02/21 17:12:30 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_outline(t_info_map *data)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->width - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < data->hight)
	{
		if (data->map[i][0] != '1' || data->map[i][data->hight - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
	{
		write(1, "Map outline bad\n", 17);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_format_dotber(t_info_map *data)
{
	if (ft_strcmpr(&data->txt[ft_strlen(data->txt) - 4], ".ber") != 0
		|| ft_strlen(data->txt) <= 4)
	{
		write(1, "Bad extension\n", 14);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_map_inputs(t_info_map *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != '1' && data->map[j][i] != '0'
				&& data->map[j][i] != 'C' && data->map[j][i] != 'P'
				&& data->map[j][i] != 'E')
			{
				write(1, "Bad map inputs\n", 15);
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
	int	j;
	int	i;
	int	end;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				data->player++;
			if (data->map[j][i] == 'C')
				data->count++;
			if (data->map[j][i] == 'E')
				end++;
			i++;
		}
		j++;
	}
	if (data->player != 1 || data->count < 1 || end != 1)
	{
		write(1, "Bad map inputs\n", 15);
		exit (EXIT_FAILURE);
	}
}
