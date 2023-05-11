/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:37:51 by gmacias-          #+#    #+#             */
/*   Updated: 2023/05/11 11:09:12 by galo             ###   ########.fr       */
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
		if (data->map[0][i] != '1' || data->map[data->hight - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < data->hight)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
	{
		write(1, "Error\nMap outline bad\n", 23);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_format_dotber(t_info_map *data)
{
	if (ft_strcmpr(&data->txt[ft_strlen(data->txt) - 4], ".ber") != 0
		|| ft_strlen(data->txt) <= 4)
	{
		write(1, "Error\nBad extension\n", 20);
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
				write(1, "Error\nBad map inputs\n", 21);
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

	end = 0;
	j = -1;
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'P')
				data->player++;
			if (data->map[j][i] == 'C')
				data->count++;
			if (data->map[j][i] == 'E')
				end++;
		}
	}
	if (data->player != 1 || data->count < 1 || end != 1)
	{
		write(1, "Error\nBad map inputs\n", 21);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_is_posible(t_info_map *data)
{
	int	i[2];
	int	j[2];
	int	left;

	left = 0;
	i[0] = -1;
	while (data->map[++i[0]])
	{
		i[1] = -1;
		while (data->map[i[0]][++i[1]])
		{
			if (data->map[i[0]][i[1]] == 'P')
			{
				j[0] = i[0];
				j[1] = j[1];
			}
			if (data->map[i[0]][i[1]] == 'E' || data->map[i[0]][i[1]] == 'C')
				left++;
		}
	}
//	ft_is_posible(data, j[0], j[1], left);
}
