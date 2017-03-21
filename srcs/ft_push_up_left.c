/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_up_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:49:36 by rpatoux           #+#    #+#             */
/*   Updated: 2016/12/12 16:35:25 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_change_str(char **tmp, int m, char c)
{
	while (m < 4)
	{
		tmp[0][m] = c;
		tmp[1][m] = c;
		tmp[2][m] = c;
		tmp[3][m] = c;
		m++;
	}
	return (tmp);
}

char	**ft_change_str_up(char **tmp, int m, char c)
{
	while (m < 4)
	{
		tmp[m][0] = c;
		tmp[m][1] = c;
		tmp[m][2] = c;
		tmp[m][3] = c;
		m++;
	}
	return (tmp);
}

int		ft_check_nb_diez(t_tetris *tetrim, char *str)
{
	int		i;
	int		j;
	int		l;
	int		k;

	l = 0;
	while (l < ft_check_nb_tetri(str))
	{
		i = -1;
		j = 0;
		while (++i < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (ft_isalpha(tetrim[l].tab[i][k]))
					j++;
				k++;
			}
		}
		if (j != 4)
			return (1);
		l++;
	}
	return (0);
}
