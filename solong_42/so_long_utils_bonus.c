/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:40:58 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 22:32:21 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free2(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}

void	set_frames(t_data *m)
{
	m->p[0] = "./fps/portal/p0.xpm";
	m->p[1] = "./fps/portal/p1.xpm";
	m->p[2] = "./fps/portal/p2.xpm";
	m->p[3] = "./fps/portal/p3.xpm";
	m->gem[0] = "./fps/gem/T0.xpm";
	m->gem[1] = "./fps/gem/T1.xpm";
	m->gem[2] = "./fps/gem/T2.xpm";
	m->gem[3] = "./fps/gem/T3.xpm";
}

char	*ft_fgets(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line && line[ft_strlen(line) - 1] == 10)
		line[ft_strlen(line) - 1] = 0;
	return (line);
}

void	enemy(t_data *m, int *i)
{
	field(m, i);
	m->img = mlx_xpm_file_to_image(m->mlx_p, "./fps/V.xpm", &i[0], &i[1]);
	mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
	mlx_destroy_image(m->mlx_p, m->img);
}

void	mv_enemy(t_data *m, int *i)
{
	enemy(m, i);
	if (m->speed == 25)
	{
		if (m->g_neo.req[3] > 1 && m->enms[m->i - 1].dir == 0
			&& i[3] == m->enms[m->i - 1].y)
			return ;
		if (m->i == m->g_neo.req[3])
			m->i = 0;
		m->enms[m->i].x = i[2];
		m->enms[m->i].y = i[3];
		if (m->enms[m->i].dir == 0)
			enmy_right(m, i);
		else if (m->enms[m->i].dir == 1)
			enmy_left(m, i);
		m->i += 1;
		m->speed = 0;
	}
	else
		m->speed += 1;
}
