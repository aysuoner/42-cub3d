/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:34:32 by aoner             #+#    #+#             */
/*   Updated: 2022/11/30 17:41:43 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	top_bot_wall_ctrl(t_data *data, size_t li)
{
	size_t	i;

	i = 0;
	//printf("topbot:		%s\n", data->game_lines[li]);
	while (data->game_lines[li][i])
	{
		if (data->game_lines[li][i] != '1' && !is_valid_space(data->game_lines[li][i]))
			return(0);	
		i++;
	}
	return(1);
}

static int	middle_walls_ctrl(t_data *data, size_t li)
{
	size_t	last_i;
	size_t	i;

	i = 0;
	last_i = ft_strlen(data->game_lines[li]) - 1;
	if (data->game_lines[li][i] != '1' || data->game_lines[li][last_i] != '1')
		return(0);
	return(1);
}

int	map_wall_ctrl(t_data *data)
{
	size_t	li;
	int		row;

	row = 0;
	printf("mapWALLctrl\n");
	while (row <= data->game_line_count)
	{
		li = row;
		if (row == 0)
		{
			if (!top_bot_wall_ctrl(data, li))
			{
				printf("top\n");
				return(0);
			}
		}
		else if (row != data->game_line_count)
		{
			if(!middle_walls_ctrl(data, li))
			{
				printf("mid\n");
				return(0);
			}
		}
		else if (row == data->game_line_count)
		{
			if(!top_bot_wall_ctrl(data, li))
			{
				printf("bot\n");
				return(0);
			}
		}
		row++;
	}
	return(1);
}
