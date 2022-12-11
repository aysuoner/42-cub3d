/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:46:13 by aoner             #+#    #+#             */
/*   Updated: 2022/11/30 17:52:07 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	clear_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
    {
		free(arg[i]);
        i++;
    }
	if (arg)
		free(arg);
	return (0);
}

int	clear_map(t_data *data)
{
	if (!data)
		return (1);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	clear_arg(data->collect_lines);
 	 if (data->game_lines)
		clear_arg(data->game_lines);
	free(data);
	return (0);
}