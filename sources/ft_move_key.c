#include "so_long.h"

void	move_w(t_info_map *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'C' ||
		   	data->map[data->y - 1][data->x] == '0')
		{
			if (data->map[data->y - 1][data->x] == 'C')
				data->count--;
			data->map[data->y][data->x] == '0';
			data->map[data->y - 1][data->x] == 'P';
		}
		else if (data->map[data->y - 1][data->x] == 'E'
			 && data->count == 0)
			data->finish = 1;
		data->y--;
		data->step++;
	}
}

void	move_s(t_info_map *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		if (data->map[data->y + 1][data->x] == 'C' ||
		   	data->map[data->y + 1][data->x] == '0')
		{
			if (data->map[data->y + 1][data->x] == 'C')
				data->count--;
			data->map[data->y][data->x] == '0';
			data->map[data->y + 1][data->x] == 'P';
		}
		else if (data->map[data->y + 1][data->x] == 'E'
			 && data->count == 0)
			data->finish = 1;
		data->y--;
		data->step++;
	}
}

void	move_a(t_info_map *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		if (data->map[data->y1][data->x - 1] == 'C' ||
		   	data->map[data->y][data->x - 1] == '0')
		{
			if (data->map[data->y][data->x - 1] == 'C')
				data->count--;
			data->map[data->y][data->x] == '0';
			data->map[data->y][data->x - 1] == 'P';
		}
		else if (data->map[data->y][data->x - 1] == 'E'
			 && data->count == 0)
			data->finish = 1;
		data->y--;
		data->step++;
	}
}

void	move_d(t_info_map *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		if (data->map[data->y1][data->x + 1] == 'C' ||
		   	data->map[data->y][data->x + 1] == '0')
		{
			if (data->map[data->y][data->x + 1] == 'C')
				data->count--;
			data->map[data->y][data->x] == '0';
			data->map[data->y][data->x + 1] == 'P';
		}
		else if (data->map[data->y][data->x + 1] == 'E'
			 && data->count == 0)
			data->finish = 1;
		data->y--;
		data->step++;
	}
}

int	press_key(int keycode, t_info_map *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		move_w(data);
	else if (keycode == S)
		move_s(data);
	else if (keycode == A)
		move_a(data);
	else if (keycode == D)
		move_d(data);
	return (0);
}
