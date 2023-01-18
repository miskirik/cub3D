/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:18:53 by miskirik          #+#    #+#             */
/*   Updated: 2023/01/18 19:27:07 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

int main(int argc, char **argv)
{
	t_map *map;
	t_mlx *mlx;
	if(argc !=3)
	{
		ft_check_args(argc,argv);
		ft_check_file(argv[1]);
	}
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	map = (t_map *)malloc(sizeof(t_map));
	ft_get_map(argv[1], map);
	mlx->map = map;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "Cub3D");
	mlx->img = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
	mlx->data_ptr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->size_line, &mlx->endian);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 500, 500, 0x00FF0000);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
