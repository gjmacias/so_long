/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:29:12 by gmacias-          #+#    #+#             */
/*   Updated: 2023/02/21 18:50:07 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define COLLECT	"../images/collect.xpm"
# define EMPTY		"../images/empty.xpm"
# define EXIT		"../images/exit.xpm"
# define PLAYER		"../images/player.xpm"
# define WALL		"../images/wall.xpm"
# define WINNER		"../images/win.xpm"

# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

# include <unistd.h>
# include <stdlib.h>
# include <../../get_next_line/get_next_line.h>
# include <mlx.h>

typedef struct s_images
{
	void	*collect;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
	void	*winner;
}	t_images;

typedef struct s_info_map
{
	int			hight;
	int			width;
	int			x;
	int			y;
	int			player;
	int			count;
	int			finish;
	int			step;
	char		*txt;
	char		**map;
	void		*mlx;
	void		*win;
	t_images	*images;
}	t_info_map;

	/*---	ft_read_map		---*/
void	ft_map_size(t_info_map *data);
void	ft_malloc_map(t_info_map *data);

	/*---	ft_check_map	---*/
void	ft_check_outline(t_info_map *data);
void	ft_check_format_dotber(t_info_map *data);
void	ft_check_map_inputs(t_info_map *data);
void	ft_check_map_objects(t_info_map *data);

	/*---	ft_draw_map		---*/
void	ft_draw_map(t_info_map *data);

	/*---	ft_move_key		---*/
int		ft_press_key(int keycode, t_info_map *data);

	/*---	ft_finish.c		---*/
int		ft_exit(t_info_map *data);
void	ft_game_result(t_info_map *data);

	/*---	ft_utils.c		---*/
int		ft_strlen(char *string);
int		ft_strcmpr(char *s1, char *s2);

#endif
