/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:15:20 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 22:43:13 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creator(t_data m)
{
	m.mlx_p = mlx_init();
	m.w = mlx_new_window(m.mlx_p, m.g_x * 50, m.g_y * 50, "so_long");
	mlx_loop_hook(m.mlx_p, (int (*)()) & render_map, &m);
	mlx_hook(m.w, 2, 0, &controls, &m);
	mlx_hook(m.w, 17, 0, (int (*)()) & exit_game, &m);
	mlx_loop(m.mlx_p);
}

int	controls(int key, t_data *m)
{
	if (key == 53)
		exit_game(m);
	if (m->map[m->g_neo.y][m->g_neo.x] == 'P')
	{
		if (key == 2 && m->map[m->g_neo.y][m->g_neo.x + 1] != '1')
		{
			left(m);
			ft_display_stats(m);
		}
		else if (key == 0 && m->map[m->g_neo.y][m->g_neo.x - 1] != '1')
		{
			right(m);
			ft_display_stats(m);
		}
		else if (key == 1 && m->map[m->g_neo.y + 1][m->g_neo.x] != '1')
		{
			down(m);
			ft_display_stats(m);
		}
		else if (key == 13 && m->map[m->g_neo.y - 1][m->g_neo.x] != '1')
		{
			up(m);
			ft_display_stats(m);
		}
	}
	return (0);
}

void	render_map(t_data *m)
{
	int	idx[4];

	idx[3] = 0;
	while (m->map[idx[3]])
	{
		idx[2] = 0;
		while (m->map[idx[3]][idx[2]])
		{
			if (m->map[idx[3]][idx[2]] == '1')
				wall(m, idx);
			else if (m->map[idx[3]][idx[2]] == '0')
				field(m, idx);
			else if (m->map[idx[3]][idx[2]] == 'E')
				f_exit(m, idx);
			else if (m->map[idx[3]][idx[2]] == 'C')
				token(m, idx);
			else if (m->map[idx[3]][idx[2]] == 'P')
				player(m, idx);
			idx[2] += 1;
		}
		idx[3] += 1;
	}
}

void	ft_display_stats(t_data *m)
{
	char	*stats;

	stats = ft_strjoin(ft_itoa(m->g_neo.mvs), " Moves");
	ft_putendl_fd(stats, 1);
	free(stats);
}

void	ft_finish_game(void)
{
	ft_putendl_fd("YOU WON", 1);
	exit(0);
}
