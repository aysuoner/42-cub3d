/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:33 by aoner             #+#    #+#             */
/*   Updated: 2022/12/01 13:31:51 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	allocate_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->game_lines[++y])
	{
		x = 0;
		while (data->game_lines[y][x])
			x++;
		if (data->x_size < x)
			data->x_size = x;
	}
	data->y_size = y;
}

void	fill_the_wall(t_data *data)
{
	int		x;
	int		y;
	int		lock;
	char	**temp_arr;
	int		i;

	y = -1;
	i = -1;
	allocate_map(data);
	temp_arr = (char **)ft_calloc(data->y_size + 1, sizeof(char *));
	while (++i < data->y_size)
		temp_arr[i] = (char *)ft_calloc(data->x_size, sizeof(char));
	while (++y < data->y_size)
	{
		x = -1;
		lock = 0;
		while (++x < data->x_size)
		{
			if (!lock && (data->game_lines[y][x] == '\0'))
				lock = 1;
			if (lock)
				temp_arr[y][x] = '1';
			else
				temp_arr[y][x] = data->game_lines[y][x];
		}
		free(data->game_lines[y]);
		data->game_lines[y] = ft_strdup(temp_arr[y]);
		free(temp_arr[y]);
	}
	free(temp_arr);
}

