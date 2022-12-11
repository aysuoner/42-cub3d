/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:28:41 by aoner             #+#    #+#             */
/*   Updated: 2022/12/01 12:24:21 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_the_space(t_data *data)
{
	int	i;
	int	j;

	i = 0;
    while (data->game_lines[i])
    {
        j = 0;
        while (data->game_lines[i][j])
        {
            if (is_valid_space(data->game_lines[i][j]))
			{
				while(data->game_lines[i][j] && is_valid_space(data->game_lines[i][j]))
				{
					data->game_lines[i][j] = '1';
					j++;
				}
				j--;
			}
			j++;
        }
		i++;
    }
}