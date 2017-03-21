/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrim_on_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:51:17 by jamerlin          #+#    #+#             */
/*   Updated: 2017/01/18 20:02:39 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_deletemap(t_map *map, char letter)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == letter)
				map->map[y][x] = '.';
		}
	}
}

int		check_carac(t_map *map, int x, int y, int i)
{
	int		x_tet;
	int		y_tet;
	int		tmp;

	y_tet = -1;
	tmp = x;
	while (++y_tet <= map->tetrim[i].y)
	{
		x_tet = -1;
		if (!map->map[y])
			return (0);
		while (++x_tet <= map->tetrim[i].x)
		{
			if (!map->map[y][x])
				return (0);
			if (ft_isalpha(map->tetrim[i].tab[y_tet][x_tet])
				&& ft_isalpha(map->map[y][x]))
				return (0);
			x++;
		}
		x = tmp;
		y++;
	}
	return (1);
}

int		ft_place(t_map *map, int x, int y, int i)
{
	int		x_tet;
	int		y_tet;
	int		tmp;

	tmp = x;
	if (!check_carac(map, x, y, i))
		return (0);
	y_tet = -1;
	while (++y_tet <= map->tetrim[i].y)
	{
		x_tet = -1;
		while (++x_tet <= map->tetrim[i].x)
		{
			if (map->tetrim[i].tab[y_tet][x_tet] == '.')
				x++;
			if (ft_isalpha(map->tetrim[i].tab[y_tet][x_tet]))
			{
				if (map->map[y][x] == '.')
					map->map[y][x++] = map->tetrim[i].tab[y_tet][x_tet];
			}
		}
		y++;
		x = tmp;
	}
	return (1);
}

char	**ft_introduce(t_map *map, int x, int y, int i)
{
	while (!ft_place(map, x, y, i))
	{
		x++;
		if (x > map->size - 1)
		{
			y++;
			x = 0;
			if (y > map->size - 1)
				return (NULL);
		}
	}
	if (i + 1 < map->nb_tetris)
	{
		while (!(ft_introduce(map, 0, 0, i + 1)))
		{
			ft_deletemap(map, map->tetrim[i].letter);
			return (ft_introduce(map, x + 1, y, i--));
		}
	}
	return (map->map);
}
