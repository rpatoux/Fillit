/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:59:33 by rpatoux           #+#    #+#             */
/*   Updated: 2016/12/14 20:59:26 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_po(char *str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		while (str[i] && str[i] != '\n')
		{
			j++;
			i++;
		}
		if (str[i] == '\n' && str[i + 1] != '\n')
		{
			if (j != 4)
				return (1);
			j = 0;
		}
	}
	return (0);
}

int		ft_check_all(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	if (j < 19)
		i++;
	ft_check_po(str) == 0 ? i = i : i++;
	ft_check_nbline(str) == 0 ? i = i : i++;
	ft_check_value(str) == 0 ? i = i : i++;
	return (i);
}

void	ft_pos_tetri(t_tetris *tetrim, int l)
{
	int		i;
	int		j;
	int		k;
	int		m;

	i = 3;
	k = 0;
	m = 0;
	while (i >= 0)
	{
		j = 3;
		while (j >= 0)
		{
			if (j > k && ALP(TLT[i][j]))
				k = j;
			if (i > m && ALP(TLT[i][j]))
				m = i;
			j--;
		}
		i--;
	}
	tetrim[l].x = k;
	tetrim[l].y = m;
}

int		ft_k(char **str, int j, int i, int k)
{
	if (j >= 0 && j <= 2)
		ALP(str[i][j + 1]) == 0 ? k = k : k++;
	if (j >= 1 && j <= 3)
		ALP(str[i][j - 1]) == 0 ? k = k : k++;
	if (i >= 0 && i <= 2)
		ALP(str[i + 1][j]) == 0 ? k = k : k++;
	if (i >= 1 && i <= 3)
		ALP(str[i - 1][j]) == 0 ? k = k : k++;
	return (k);
}

int		ft_check_tetris(t_tetris *tetrim, char *str, int nb_tetris)
{
	int		i;
	int		j;
	int		k;
	int		l;

	l = -1;
	while (++l < nb_tetris)
	{
		i = -1;
		k = 0;
		while (TLT[++i] && i < 4)
		{
			j = -1;
			while (TLT[i][++j] && j < 4)
			{
				if (TLT[i][j] == 'A' + l)
				{
					k = ft_k(TLT, j, i, k);
				}
			}
		}
		if (k < 6)
			return (1);
	}
	return (0);
}
