/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:12:00 by miskirik          #+#    #+#             */
/*   Updated: 2023/01/18 19:11:28 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void ft_check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error",2);
		exit(1);
	}
	else
	{
		int	i;
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		if ((i<4) && !((argv[1][i] == 'b' && argv[1][i - 1] == 'u' \
		 && argv[1][i - 2] == 'c' && argv[1][i - 3] == '.')))
		{
			ft_putstr_fd("Map format is invalid", 2);
			exit(1);
		}
	}
}

void ft_check_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Map not exist", 2);
		exit(1);
	}
}
