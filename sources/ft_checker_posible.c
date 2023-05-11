#include "so_long.h"
#include <stdio.h>
void	print(t_checker *c, t_info_map *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			printf("%d", c->map[i][j]);
		printf("\n");
	}
	i = -1;
	while (++i < data->hight)
	{
		j = -1;
		while (++j < data->width)
			printf("%c", data->map[i][j]);
		printf("\n");
	}
}

void	malloc_and_fill(t_checker *c, t_info_map *data)
{
	int i;
	int j;

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
	print(c, data);
}

void	free_checker(t_checker *c, int	hight)
{
	int i;
 
	i = -1; 
	while (i < hight + 1)
	{
		free(c->map[i]);
		printf("\n");
	}
	free(c->map);
	c->map = NULL;
}

void	ft_is_posible(t_info_map *data, int j, int i,int left)
{
	t_checker c;

	c.x = j;
	c.y = i;
	c.coins_left = left;
	c.result = 0;
	malloc_and_fill(&c, data);
	//iter_checker();
	if (c.result == 0)
		write(2, "Error\nMap is imposible\n", 23);
	else
		write(1, "Hello\n", 6);
//	free_checker(&c, data->hight);
	(void)c;
	(void)data;
	exit(EXIT_SUCCESS);
}
