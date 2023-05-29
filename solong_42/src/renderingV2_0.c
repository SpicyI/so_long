/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderingV2_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:35:11 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 21:41:19 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall(t_data *m, int *i)
{
	m->img = mlx_xpm_file_to_image(m->mlx_p, "./fps/W.xpm", &i[0], &i[1]);
	mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
	mlx_destroy_image(m->mlx_p, m->img);
}

void	field(t_data *m, int *i)
{
	m->img = mlx_xpm_file_to_image(m->mlx_p, "./fps/G.xpm", &i[0], &i[1]);
	mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
	mlx_destroy_image(m->mlx_p, m->img);
}

void	f_exit(t_data *m, int *i)
{
	m->img = mlx_xpm_file_to_image(m->mlx_p, "./fps/E.xpm", &i[0], &i[1]);
	mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
	mlx_destroy_image(m->mlx_p, m->img);
}

void	token(t_data *m, int *i)
{
	field(m, i);
	m->img = mlx_xpm_file_to_image(m->mlx_p, "./fps/T0.xpm", &i[0], &i[1]);
	mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
	mlx_destroy_image(m->mlx_p, m->img);
}

void	player(t_data *m, int *i)
{
	m->g_neo.x = i[2];
	m->g_neo.y = i[3];
	m->img = mlx_xpm_file_to_image(m->mlx_p, "./fps/G.xpm", &i[0], &i[1]);
	mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
	mlx_destroy_image(m->mlx_p, m->img);
	m->img = mlx_xpm_file_to_image(m->mlx_p, "./fps/P.xpm", &i[0], &i[1]);
	mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
	mlx_destroy_image(m->mlx_p, m->img);
}
