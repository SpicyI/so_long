/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:10:51 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 22:28:37 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_player
{
	int	x;
	int	y;
	int	req[4];
	int	mvs;
}	t_player;

typedef struct s_patrol
{
	int	x;
	int	y;
	int	dir;
}	t_patrol;

typedef struct s_data
{
	void		*w;
	void		*mlx_p;
	void		*img;
	char		**map;
	char		*p[4];
	char		*gem[4];
	int			p_i[2];
	int			i;
	int			speed;
	size_t		g_x;
	size_t		g_y;
	t_player	g_neo;
	t_patrol	*enms;
}	t_data;

typedef struct s_fpath
{
	int	path;
	int	c_nbr;
}	t_fpath;

/*-----------------Utils-------------------*/
int		ft_argcheck(const char *arg, char *to_find);
void	ft_finish_game(int f);
void	ft_error(char *err);
void	set_frames(t_data *m);
void	ft_free2(char **string);
/*-------------------MAP-----------------------*/
char	**get_map(const char *arg, t_data *m);
int		count_size(const char *s, t_data *m);
void	check_map(t_data m, int *req);
void	check_req(char *map, t_data m, int *req);
char	*ft_fgets(int fd);
/*-----------------Rendering-------------------*/
void	creator(t_data m);
void	render_map(t_data *m);
void	wall(t_data *m, int *i);
void	field(t_data *m, int *i);
void	f_exit(t_data *m, int *i);
void	token(t_data *m, int *i);
void	player(t_data *m, int *i);
void	ft_display_stats(t_data *m);
/*-----------------Controls-------------------*/
void	up(t_data *m);
void	down(t_data *m);
void	left(t_data *m);
void	right(t_data *m);
void	exit_game(t_data *m);
int		controls(int key, t_data *m);
/*----------------find-path------------------*/
void	find_path(t_data map);
void	get_coords(char **map, int e[2]);
t_fpath	*check_path(int x, int y, char **map, t_fpath *checker);
char	**temp_map(t_data m);
/*---------------Enemy----------------------*/
void	mv_enemy(t_data *m, int *i);
void	enemy(t_data *m, int *idx);
void	enmy_left(t_data *m, int *i);
void	enmy_right(t_data *m, int *i);

#endif
