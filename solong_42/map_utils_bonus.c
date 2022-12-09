/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:00:55 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/06 22:18:16 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**get_map(const char *arg, t_data *m)
{
	int		fd;
	char	**map;
	size_t	i;

	m->g_y = count_size(arg, m);
	i = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		perror("Error\nso_long:");
		exit(errno);
	}
	if (m->g_y < 3)
		ft_error("Error\nUnvalid map !!");
	map = (char **)ft_calloc(m->g_y + 1, sizeof(char *));
	while (i < m->g_y)
	{
		map[i] = ft_fgets(fd);
		i++;
	}
	close(fd);
	return (map);
}

int	count_size(const char *s, t_data *m)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nso_long: can't open");
	i = 0;
	line = ft_fgets(fd);
	m->g_x = ft_strlen(line);
	while (line)
	{
		if (m->g_x != ft_strlen(line) || m->g_x < 3)
		{
			free(line);
			ft_error("Error\nUnvalid map !!");
		}
		free(line);
		i++;
		line = ft_fgets(fd);
	}
	close(fd);
	return (i);
}

void	check_map(t_data m, int *req)
{
	size_t	i;
	int		j;

	i = 0;
	while (m.map[i])
	{
		j = 0;
		if (i == 0 || i == m.g_y - 1)
		{
			while (m.map[i][j])
			{
				if (m.map[i][j] != '1')
					ft_error("Error\nUnvalid map: no valid walls");
				j++;
			}
		}
		else
			check_req(m.map[i], m, req);
		i++;
	}
	if (req[0] < 1 || req[1] != 1 || req[2] != 1 || req[3] < 0)
		ft_error("Error\nUnvalid map: no valid requirements");
}

void	check_req(char *map, t_data m, int *req)
{
	size_t	j;

	j = 0;
	if (map[j] != '1' || map[m.g_x - 1] != '1')
		ft_error("Error\nUnvalid map: no valid side walls");
	j++;
	while (j < m.g_x - 1)
	{
		if (map[j] == 'C')
			req[0] += 1;
		else if (map[j] == 'E')
			req[1] += 1;
		else if (map[j] == 'P')
			req[2] += 1;
		else if (map[j] == '*')
			req[3] += 1;
		else if (map[j] != '0' && map[j] != '1')
			ft_error("Error\nUnvalid map !!");
		j++;
	}
}
