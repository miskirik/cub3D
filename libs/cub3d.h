#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_map
{
	char	**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
	int		x;
	int		y;
	float	ang;
	int		floor_color;
	int		ceiling_color;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*data_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_map	*map;
}				t_mlx;

void ft_check_args(int argc, char **argv);
void ft_check_file(char *file);
void ft_get_map(char *file, t_map *map);

#endif
