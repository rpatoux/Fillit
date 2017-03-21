/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:00:06 by jamerlin          #+#    #+#             */
/*   Updated: 2016/12/14 20:53:02 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tetrim(char *str)
{
	char	**tetriminos;
	int		y;

	y = 0;
	if (!(tetriminos = (char **)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (y < 5)
	{
		while (*str != '\n')
			str++;
		tetriminos[y] = ft_strsub(str, 0, 5);
		str = str + 5;
		y++;
	}
	tetriminos[y] = NULL;
	return (tetriminos);
}

int		ft_check_nbline(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\0')
			j++;
		if (j == 4)
		{
			if (str[i + 1] != '\n')
				return (1);
			else
			{
				i++;
				j = 0;
			}
		}
		i++;
	}
	return (0);
}

int		ft_check_nb_tetri(char *str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') ||
			(str[i] == '\n' && str[i + 1] == '\0'))
			j++;
	}
	return (j);
}

int		ft_check_value(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (str[i] == '.' || str[i] == '#' ||
			(str[i] == '\n')))
		i++;
	if (i == ft_strlen(str))
		return (0);
	return (1);
}

int		ft_check_tetri(char *str)
{
	int		i;

	i = -1;
	while (str[i] && (str[i] == '.' || str[i] == '#' || str[i] == '\n'))
		i++;
	if (str[i] != '.' || str[i] != '#' || str[i] != '\n')
		return (1);
	return (0);
}
