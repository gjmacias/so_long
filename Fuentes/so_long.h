#ifndef SO_LONG_H
# define SO_LONG_H

# define (pictures) "location pictures"

# define (keys) "numbe"

# include <unistd.h>
# include <mlx.h>

typedef struct s_info_map
{
	int	hight;
	int	weight;
	int	x;
	int	y;
	int	player;
	int	count;
	int	finish;
	int	step;			//ver para que sirve
	char	**map;
	t_images;
}	t_info_map;

typedef struct s_images
{
	void	*empty;
	void	*wall;
	void	*collect;
	void	*player;
	void	*winner;
	void	*exit;
}	t_images;

	/---	ft_check_map	---/
void	ft_check_outline(t_info_map *data)
void	ft_check_format_dotber(t_info_map *data)
void	ft_check_map_inputs(t_info_map *data)
void	ft_check_map_objects(t_info_map *data)
