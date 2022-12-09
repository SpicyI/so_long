/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:15:40 by del-khay          #+#    #+#             */
/*   Updated: 2022/11/26 23:14:19 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *dst, char *src)
{
	char	*rst;
	int		i;

	i = 0;
	if (!dst)
	{
		dst = ft_calloc(1, sizeof(char));
		if (!dst)
			return (0);
	}
	rst = ft_calloc(ft_strlen(dst) + ft_strlen(src) + 1, sizeof(char));
	if (!rst)
		return (0);
	while (dst && dst[i])
	{
		rst[i] = dst[i];
		i++;
	}
	while (*src)
		rst[i++] = *src++;
	free(dst);
	return (rst);
}

int	is_nl(char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}
