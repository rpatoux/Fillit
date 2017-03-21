/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:33:46 by jamerlin          #+#    #+#             */
/*   Updated: 2016/12/19 15:12:58 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(int fd)
{
	char	*str;
	char	*buff;
	int		ret;

	buff = (char*)malloc(sizeof(char) * BUFF_SIZE);
	if (buff == NULL)
		return (NULL);
	ret = read(fd, buff, BUFF_SIZE);
	if (!(str = (char*)malloc(sizeof(char) * (ret + 1))))
		return (NULL);
	str = buff;
	str[ret] = '\0';
	if (str[ret - 1] != '\n')
		return (NULL);
	return (str);
}

void	ft_malloc_tab(t_tetris *tetrim, int nb_tetri)
{
	int		i;
	int		j;

	i = -1;
	while (++i < nb_tetri)
	{
		if (!(tetrim[i].tab = (char **)malloc(sizeof(char *) * 5)))
			return ;
		j = -1;
		while (++j < 5)
			if (!(tetrim[i].tab[j] = (char *)malloc(sizeof(char) * 5)))
				return ;
	}
}

int		main(int argc, char **argv)
{
	t_tetris	*tetrim;

	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr("usage: ./fillit input_one_file \n");
		else if (argc > 2)
			ft_putstr("usage: ./fillit input_one_file \n");
		return (1);
	}
	else
		fillit(argv);
	return (0);
}
