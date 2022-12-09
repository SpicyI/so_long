/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:55:47 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 21:55:18 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_path(t_data m)
{
	t_fpath	*checker;
	char	**temp;
	int		p_pos[2];

	get_coords(m.map, p_pos);
	temp = temp_map(m);
	checker = (t_fpath *)ft_calloc(1, sizeof(t_fpath));
	checker->path = 0;
	checker->c_nbr = 0;
	checker = check_path(p_pos[0], p_pos[1], temp, checker);
	ft_free2(temp);
	if (checker->path == 0 || checker->c_nbr != m.g_neo.req[0])
	{
		free(checker);
		ft_error("Unvalid path");
	}
	free(checker);
}

void	get_coords(char **map, int e[2])
{
	int	j;
	int	i;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				e[0] = j;
				e[1] = i;
			}
			j++;
		}
		i++;
	}
}

t_fpath	*check_path(int x, int y, char **map, t_fpath *checker)
{
	if (y <= 0 && x <= 0)
		return (checker);
	if (map[y][x] == '1' || map[y][x] == '*')
		return (checker);
	if (map[y][x] == 'N')
		return (checker);
	if (map[y][x] == 'C')
		checker->c_nbr += 1;
	else if (map[y][x] == 'E')
	{
		checker->path = 1;
		return (checker);
	}
	map[y][x] = '1';
	if (map[y + 1][x] != 1)
		check_path(x, y + 1, map, checker);
	if (map[y - 1][x] != 1)
		check_path(x, y - 1, map, checker);
	if (map[y][x + 1] != 1)
		check_path(x + 1, y, map, checker);
	if (map[y][x - 1] != 1)
		check_path(x - 1, y, map, checker);
	return (checker);
}

char	**temp_map(t_data m)
{
	char	**temp;
	int		i;
	int		j;

	i = m.g_y;
	j = 0;
	temp = (char **)ft_calloc(m.g_y + 1, sizeof(char *));
	while (i--)
	{
		temp[j] = ft_strdup(m.map[j]);
		j++;
	}
	return (temp);
}
