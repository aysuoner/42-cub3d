/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:53:57 by aoner             #+#    #+#             */
/*   Updated: 2022/11/30 20:54:22 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_start_pos(t_data *data, t_map *map)
{
	int		i;
	int		k;
	int		t;

	t = 0;
	i = -1;
	while (data->game_lines[++i])
	{
		k = -1;
		while (data->game_lines[i][++k])
		{
			if (ft_strchr("WESN", data->game_lines[i][k]))
			{
				while (data->game_lines[i][k] != "ENWS"[t])
					t++;
				map->ang = t * 90;
				data->game_lines[i][k] = '0';
				map->y = i;
				map->x = k;
				return ;
			}
		}
	}
}