/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:13:31 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 22:31:18 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_argcheck(const char	*arg, char *to_find)
{
	int	i;
	int	j;

	i = ft_strlen(arg);
	if (i < 5)
		return (0);
	j = ft_strlen(to_find) - 1;
	while (i-- >= 0)
	{
		if (!j)
			return (1);
		if (arg[i] != to_find[j])
			break ;
		j--;
	}
	return (0);
}

void	ft_error(char *err)
{
	ft_putendl_fd(err, 2);
	exit(1);
}

void	enmy_right(t_data *m, int *i)
{
	if (m->map[i[3]][i[2] + 1] == 'P')
		ft_finish_game(0);
	if (m->map[i[3]][i[2] + 1] == '1' || m->map[i[3]][i[2] + 1] == 'E' ||
		m->map[i[3]][i[2] + 1] == 'C' || m->map[i[3]][i[2] + 1] == '*')
		m->enms[m->i].dir = 1;
	else
	{
		m->map[i[3]][i[2]] = '0';
		m->map[i[3]][i[2] + 1] = '*';
	}
}

void	enmy_left(t_data *m, int *i)
{
	if (m->map[i[3]][i[2] - 1] == 'P')
		ft_finish_game(0);
	if (m->map[i[3]][i[2] - 1] == '1' || m->map[i[3]][i[2] - 1] == 'E' ||
		m->map[i[3]][i[2] - 1] == 'C' || m->map[i[3]][i[2] - 1] == '*')
		m->enms[m->i].dir = 0;
	else
	{
		m->map[i[3]][i[2]] = '0';
		m->map[i[3]][i[2] - 1] = '*';
	}
}

int	main(int ac, char **av)
{
	t_data	m;

	if (ac != 2 || !ft_argcheck(av[1], ".ber"))
		ft_error("Error\nUnvalid map, please try: './so_long \"*.ber\"'");
	m.g_x = 0;
	m.g_y = 0;
	m.p_i[0] = 0;
	m.p_i[1] = 0;
	m.speed = 0;
	m.i = 0;
	m.map = get_map(av[1], &m);
	check_map(m, m.g_neo.req);
	m.enms = (t_patrol *) ft_calloc(m.g_neo.req[3], sizeof(t_patrol));
	find_path(m);
	creator(m);
	exit(0);
}
