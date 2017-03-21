/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 04:06:26 by jamerlin          #+#    #+#             */
/*   Updated: 2017/01/18 20:02:26 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*ft_stock(t_tetris *tetrim, char *str)
{
	int i;
	int j;
	int k;
	int l;

	i = -1;
	j = 0;
	l = 0;
	while (str[++i])
	{
		k = 0;
		while (str[i] != '\n' && str[i])
			tetrim[l].tab[j][k++] = (str[i++] == '#') ? 'A' + l : '.';
		tetrim[l].letter = 'A' + l;
		tetrim[l].tab[j][k] = '\0';
		j++;
		if (j == 5)
		{
			l++;
			tetrim[l].tab[j] = NULL;
			j = 0;
		}
	}
	return (tetrim);
}
