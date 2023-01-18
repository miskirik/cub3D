/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:14:39 by miskirik          #+#    #+#             */
/*   Updated: 2023/01/18 21:52:28 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void ft_get_map(char *file, t_map *map)
{
	int fd;
	char *line;
	char *temp;
	int i;

	i = 0;
	fd = open(file, O_RDONLY);
	line=get_next_line(fd);
	temp = malloc(1);
	while (line)
	{
		if (line[0] == 'N' && line[1]=='O')
			map->no = ft_strdup(line + 2);
		else if (line[0] == 'S' && line[1]=='O')
			map->so = ft_strdup(line + 2);
		else if (line[0] == 'W' && line[1]=='E')
			map->we = ft_strdup(line + 2);
		else if (line[0] == 'E' && line[1]=='A')
			map->ea = ft_strdup(line + 2);
		else if (line[0] == 'F')
			map->f = ft_strdup(line + 1);
		else if (line[0] == 'C')
			map->c = ft_strdup(line + 1);
		else if (line[0] == '1' || line[0] == '0')
		{
			temp = ft_strjoin(temp,line);
		}
		line = get_next_line(fd);
	}
	map->map = ft_split(temp, '\n');
	printf("%s\n", map->no);
	printf("%s\n", map->so);
	printf("%s\n", map->we);
	printf("%s\n", map->ea);
	printf("%s\n", map->f);
	printf("%s\n", map->c);
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}
