/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:14:01 by rpatoux           #+#    #+#             */
/*   Updated: 2017/01/29 17:41:04 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1024

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAP map->size
# define ALP ft_isalpha
# define TLT tetrim[l].tab
# define TJ tmp[j]

typedef struct	s_tetris
{
	char		**tab;
	int			size_map_min;
	int			x;
	int			y;
	char		letter;
}				t_tetris;

typedef struct	s_map
{
	char		**map;
	int			size;
	int			nb_tetris;
	t_tetris	*tetrim;
}				t_map;

int				ft_can_place(char **str, int i, int j, int x, int y);
char			**ft_introduce(t_map *map, int x, int y, int i);
char			**ft_create_map(int k);
int				main(int argc, char **argv);
int				ft_check_nbline(char *str);
char			**ft_tetrim(char *str);
int				ft_check_value(char *str);
char			*ft_read(int fd);
void			fillit(char **argv);
t_tetris		*ft_stock(t_tetris *tetrim, char *str);
int				ft_check_nb_tetri(char *str);
int				ft_check_tetri(char *str);
char			**ft_push_left(t_tetris *tetrim, int l);
char			**ft_change_str(char **tmp, int m, char c);
char			**ft_change_str_up(char **tmp, int m, char c);
char			**ft_push_up(char **tmp);
char			**ft_push_up_left(t_tetris *tetrim, int l);
int				ft_check_nb_diez(t_tetris *tetrim, char *str);
void			ft_malloc_tab(t_tetris *tetrim, int nb_tetri);
int				ft_check_all(char *str);
int				ft_check_tetris(t_tetris *tetrim, char *str, int nb_tetris);
void			ft_pos_tetri(t_tetris *tetrim, int l);
int				ft_check_point_line(char *str);
char			**ft_malloc_tmp(char **tmp);

#endif
