/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:43:53 by aoner             #+#    #+#             */
/*   Updated: 2022/12/02 13:24:28 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	image_controller(t_data *data)
{
	if (!data->imgs[0].img || !data->imgs[1].img
		|| !data->imgs[2].img || !data->imgs[3].img)
	{
		ft_putstr_fd("image error!\n", 2);
		exit(1);
	}
}

void	ft_image_setup(t_data *data)
{
	data->imgs[0].img = mlx_xpm_file_to_image(data->mlx,
			data->no, &data->imgs[0].width, &data->imgs[0].height);
	data->imgs[1].img = mlx_xpm_file_to_image(data->mlx,
			data->so, &data->imgs[1].width, &data->imgs[1].height);
	data->imgs[2].img = mlx_xpm_file_to_image(data->mlx,
			data->ea, &data->imgs[2].width, &data->imgs[2].height);
	data->imgs[3].img = mlx_xpm_file_to_image(data->mlx,
		data->we, &data->imgs[3].width, &data->imgs[3].height);
	image_controller(data);
	data->imgs[0].addr = mlx_get_data_addr(data->imgs[0].img,
			&data->imgs[0].bbp, &data->imgs[0].line_len, &data->imgs[0].endian);
	data->imgs[1].addr = mlx_get_data_addr(data->imgs[1].img,
			&data->imgs[1].bbp, &data->imgs[1].line_len, &data->imgs[1].endian);
	data->imgs[2].addr = mlx_get_data_addr(data->imgs[2].img,
			&data->imgs[2].bbp, &data->imgs[2].line_len, &data->imgs[2].endian);
	data->imgs[3].addr = mlx_get_data_addr(data->imgs[3].img,
			&data->imgs[3].bbp, &data->imgs[3].line_len, &data->imgs[3].endian);
	data->floor_color = (data->f.r << 16) + (data->f.g << 8) + data->f.b;
	data->ceil_color = (data->c.r << 16) + (data->c.g << 8) + data->c.b;
}