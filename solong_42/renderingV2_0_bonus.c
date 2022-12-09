/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderingV2_0_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:35:11 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 21:54:45 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (m->g_neo.req[0] > 0)
	{
		m->img = mlx_xpm_file_to_image(m->mlx_p, "./fps/E.xpm", &i[0], &i[1]);
		mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
		mlx_destroy_image(m->mlx_p, m->img);
	}
	else
	{
		if (m->p_i[0] > 3)
			m->p_i[0] = 0;
		field(m, i);
		m->img = mlx_xpm_file_to_image(m->mlx_p, m->p[m->p_i[0]], &i[0], &i[1]);
		mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
		mlx_destroy_image(m->mlx_p, m->img);
		m->p_i[0] += 1;
	}
}

void	token(t_data *m, int *i)
{
	field(m, i);
	if (m->p_i[1] > 3 && m->g_neo.req[0] % 4 != 0)
		m->p_i[1] = 0;
	else if (m->p_i[1] > 3)
		m->p_i[1] = 1;
	m->img = mlx_xpm_file_to_image(m->mlx_p, m->gem[m->p_i[1]], &i[0], &i[1]);
	mlx_put_image_to_window(m->mlx_p, m->w, m->img, i[2] * 50, i[3] * 50);
	mlx_destroy_image(m->mlx_p, m->img);
	m->p_i[1] += 1;
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
