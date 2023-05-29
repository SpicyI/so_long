/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:33:56 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 22:12:56 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	up(t_data *m)
{
	if (m->map[m->g_neo.y - 1][m->g_neo.x] == 'C')
		m->g_neo.req[0] -= 1;
	if (m->map[m->g_neo.y - 1][m->g_neo.x] == 'E' && m->g_neo.req[0] == 0)
		ft_finish_game(1);
	if (m->map[m->g_neo.y - 1][m->g_neo.x] == '*')
		ft_finish_game(0);
	else if (m->map[m->g_neo.y - 1][m->g_neo.x] != 'E')
	{
		m->map[m->g_neo.y][m->g_neo.x] = '0';
		m->map[m->g_neo.y - 1][m->g_neo.x] = 'P';
		m->g_neo.mvs++;
	}
}

void	down(t_data *m)
{
	if (m->map[m->g_neo.y + 1][m->g_neo.x] == 'C')
		m->g_neo.req[0] -= 1;
	if (m->map[m->g_neo.y + 1][m->g_neo.x] == 'E' && m->g_neo.req[0] == 0)
		ft_finish_game(1);
	if (m->map[m->g_neo.y + 1][m->g_neo.x] == '*')
		ft_finish_game(0);
	else if (m->map[m->g_neo.y + 1][m->g_neo.x] != 'E')
	{
		m->map[m->g_neo.y][m->g_neo.x] = '0';
		m->map[m->g_neo.y + 1][m->g_neo.x] = 'P';
		m->g_neo.mvs++;
	}
}

void	left(t_data *m)
{
	if (m->map[m->g_neo.y][m->g_neo.x + 1] == 'C')
		m->g_neo.req[0] -= 1;
	if (m->map[m->g_neo.y][m->g_neo.x + 1] == 'E' && m->g_neo.req[0] == 0)
		ft_finish_game(1);
	if (m->map[m->g_neo.y][m->g_neo.x + 1] == '*')
		ft_finish_game(0);
	else if (m->map[m->g_neo.y][m->g_neo.x + 1] != 'E')
	{
		m->map[m->g_neo.y][m->g_neo.x] = '0';
		m->map[m->g_neo.y][m->g_neo.x + 1] = 'P';
		m->g_neo.mvs++;
	}
}

void	right(t_data *m)
{
	if (m->map[m->g_neo.y][m->g_neo.x - 1] == 'C')
		m->g_neo.req[0] -= 1;
	if (m->map[m->g_neo.y][m->g_neo.x - 1] == 'E' && m->g_neo.req[0] == 0)
		ft_finish_game(1);
	if (m->map[m->g_neo.y][m->g_neo.x - 1] == '*')
		ft_finish_game(0);
	else if (m->map[m->g_neo.y][m->g_neo.x - 1] != 'E')
	{
		m->map[m->g_neo.y][m->g_neo.x] = '0';
		m->map[m->g_neo.y][m->g_neo.x - 1] = 'P';
		m->g_neo.mvs++;
	}
}

void	exit_game(t_data *m)
{
	mlx_destroy_window(m->mlx_p, m->w);
	exit(0);
}
