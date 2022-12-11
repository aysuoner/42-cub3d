/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:54:25 by aoner             #+#    #+#             */
/*   Updated: 2022/11/30 14:38:39 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_char_ctrl(t_data *data, char *diff_char, char *just_one)
{
	int		i;
	int		j;
	int		k;
	int		c;

	k = 0;
	i = 0;
	c = 0;
	printf("MAPCHARCTRL\n");
	while (i < data->game_line_count - 1)
	{
		j = 0;
		while (data->game_lines[i][j])
		{
			c = data->game_lines[i][j];
			if (!ft_strchr(diff_char,c))
				return (-1);
			if (ft_strchr(just_one, c))
				k++;
			j++;
		}
		i++;
	}
	if (1 != k)
		return (-1);
	//i = 0;
	return (0);
}
