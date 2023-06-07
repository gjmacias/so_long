/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_posible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:10:42 by gmacias-          #+#    #+#             */
/*   Updated: 2023/05/15 16:10:47 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_and_fill(t_checker *c, t_info_map *data)
{
	int	i;
	int	j;

	c->map = malloc(sizeof(int *) * data->hight);
	i = -1;
	while (++i < data->hight)
		c->map[i] = malloc(sizeof(int *) * data->width);
	i = -1;
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			c->map[i][j] = 0;
	}
}

void	free_checker(t_checker *c, int hight)
{
	int	i;

	i = -1;
	while (++i < hight)
		free(c->map[i]);
	free(c->map);
	c->map = NULL;
}

void	iter_checker(t_checker *c, t_info_map *data, int i, int j)
{
	if (c->coins_left == 0)
		return ;
	if (c->map[i][j] == 0 && data->map[i][j] != '1')
	{
		c->map[i][j] = 1;
		if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
			c->coins_left--;
		if (data->map[i][j] == 'E')
			return ;
		iter_checker(c, data, i + 1, j);
		iter_checker(c, data, i - 1, j);
		iter_checker(c, data, i, j + 1);
		iter_checker(c, data, i, j - 1);
	}
}

void	ft_is_posible(t_info_map *data, int j, int i, int left)
{
	t_checker	c;

	c.coins_left = left;
	malloc_and_fill(&c, data);
	iter_checker(&c, data, j, i);
	if (c.coins_left != 0)
	{
		write(2, "Error\nMap is imposible\n", 23);
		exit(EXIT_FAILURE);
	}
	free_checker(&c, data->hight);
}
