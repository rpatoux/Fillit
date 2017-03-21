/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:21 by rpatoux           #+#    #+#             */
/*   Updated: 2017/01/18 20:04:34 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_double(t_map *map)
{
	int y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			ft_putchar(map->map[y][x]);
		}
		ft_putchar('\n');
	}
}

void	ft_pos_push_up_left(int nb_tetris, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->nb_tetris)
	{
		map->tetrim[j].tab = ft_push_up_left(map->tetrim, j);
		j++;
	}
	while (i < map->nb_tetris)
	{
		ft_pos_tetri(map->tetrim, i);
		i++;
	}
}

int		ft_fillit_finish(t_map *map, char *str)
{
	if ((ft_check_tetris(map->tetrim, str, map->nb_tetris) +
		ft_check_nb_diez(map->tetrim, str)) != 0)
	{
		free(map);
		ft_putstr("error\n");
		return (1);
	}
	ft_pos_push_up_left(map->nb_tetris, map);
	map->size = ft_sqrt(map->nb_tetris * 4);
	map->map = ft_create_map(map->size);
	while (!(map->map = ft_introduce(map, 0, 0, 0)))
	{
		free(map->map);
		map->size++;
		map->map = ft_create_map(map->size);
	}
	return (0);
}

void	fillit(char **argv)
{
	int			fd;
	char		*str;
	t_map		*map;

	fd = open(argv[1], O_RDONLY);
	if (!(str = ft_read(fd)))
	{
		ft_putstr("error\n");
		return ;
	}
	if (ft_check_all(str) > 0)
	{
		ft_putstr("error\n");
		return ;
	}
	close(fd);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return ;
	map->nb_tetris = ft_check_nb_tetri(str);
	map->tetrim = (t_tetris*)malloc(sizeof(t_tetris) * map->nb_tetris);
	ft_malloc_tab(map->tetrim, map->nb_tetris);
	ft_stock(map->tetrim, str);
	if (ft_fillit_finish(map, str) == 1)
		return ;
	ft_print_double(map);
}
