/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:28:19 by aoner             #+#    #+#             */
/*   Updated: 2022/12/01 14:38:39 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	find_bottom_line(t_data *data)
{
	int	i;

	i = data->tot_line_count - 2;
	while (i > data->game_start_line)
	{
		if (data->collect_lines[i][0] && data->collect_lines[i][0] == '1')
		{
			data->game_last_line = i;
			return (1);
		}
		if (data->collect_lines[i][0] && data->collect_lines[i][0] != '\n')
			return (-1);
		i--;
	}
	return (1);
}

static int	find_top_line(t_data *data)
{
	int	i;

	i = data->last_element_line;
	while (data->collect_lines[i])
	{
		if (data->collect_lines[i][0] && data->collect_lines[i][0] == '1')
		{
			data->game_start_line = i;
			return(1);
		}
		else if (data->collect_lines[i][0] && data->collect_lines[i][0] != '\n')
			return (-1);
		i++;
	}
	return (1);
}

int	save_game_map(t_data *data)
{
    int		i;
	int		k;
	char	*line;
	char	*t_line;
	int		len;

	k = 0;
	i = 0;
	if (find_top_line(data) == -1 || find_bottom_line(data) == -1)
		return (-1);
	i = data->game_start_line;
	data->game_lines = (char **)ft_calloc(sizeof(char *), (data->game_last_line - data->game_start_line) + 2);
    while (i <= data->game_last_line)
	{
		line = data->collect_lines[i];
		t_line = ft_strtrim(line, " \v\f\t\r\n");
		len = ft_strlen(t_line);
		data->game_lines[k] = ft_substr(t_line, 0,  len);
		free(t_line);
		i++;
		k++;
	}
	data->game_lines[k] = NULL;
	data->game_line_count = k - 1;
	return (k);
}