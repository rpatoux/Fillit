/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_up_left_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:31:52 by jamerlin          #+#    #+#             */
/*   Updated: 2016/12/12 16:49:27 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_malloc_tmp(char **tmp)
{
	int		i;

	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (i < 5)
	{
		if (!(tmp[i] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		i++;
	}
	return (tmp);
}

char	**ft_push_left(t_tetris *tetrim, int l)
{
	char	**tmp;
	int		j;
	int		m;
	int		i;

	j = 0;
	m = 0;
	i = 0;
	tmp = ft_malloc_tmp(tmp);
	while (TLT[0][j] == '.' && TLT[1][j] == '.' && TLT[2][j] == '.' &&
		TLT[3][j] == '.')
		j++;
	while (((ALP(TLT[0][j]) || ALP(TLT[1][j])) || (ALP(TLT[2][j]) ||
		ALP(TLT[3][j]))) && j < 4)
	{
		tmp[0][m] = TLT[0][j];
		tmp[1][m] = TLT[1][j];
		tmp[2][m] = TLT[2][j];
		tmp[3][m] = TLT[3][j];
		m++;
		j++;
	}
	tmp = ft_change_str(tmp, m, '.');
	tmp[4] = NULL;
	return (tmp);
}

char	**ft_push_up(char **tmp)
{
	int		j;
	int		m;
	int		i;
	char	**tmp2;

	j = 0;
	m = 0;
	i = 0;
	tmp2 = ft_malloc_tmp(tmp2);
	while (TJ[0] == '.' && TJ[1] == '.' && TJ[2] == '.' && TJ[3] == '.')
		j++;
	while (j < 4 && (ALP(TJ[0]) || ALP(TJ[1]) || ALP(TJ[2]) || ALP(TJ[3])))
	{
		tmp2[m][0] = tmp[j][0];
		tmp2[m][1] = tmp[j][1];
		tmp2[m][2] = tmp[j][2];
		tmp2[m][3] = tmp[j][3];
		tmp2[m][4] = 0;
		m++;
		j++;
	}
	tmp2 = ft_change_str_up(tmp2, m, '.');
	tmp2[4] = NULL;
	free(tmp);
	return (tmp2);
}

char	**ft_push_up_left(t_tetris *tetrim, int l)
{
	char	**tmp;
	char	**tmp2;

	tmp = ft_push_left(tetrim, l);
	tmp2 = ft_push_up(tmp);
	return (tmp2);
}
