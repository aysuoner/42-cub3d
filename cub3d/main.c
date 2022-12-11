/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:51:10 by aoner             #+#    #+#             */
/*   Updated: 2022/12/02 14:55:50 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	maintwo(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "CUKUR");
	data->screen.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->screen.width = WIN_WIDTH;
	data->screen.height = WIN_HEIGHT;
	data->screen.addr = mlx_get_data_addr(data->screen.img, \
	&data->screen.bbp, &data->screen.line_len, &data->screen.endian);
	ft_image_setup(data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;

 	argc_ctrl(argc);
	map_name_ctrl(argv);
	data = ft_calloc(sizeof(t_data), 1);
	save_cub_file(argv[1], data);
	data->last_element_line = classify_the_elements(data);
	if (data->last_element_line == -1 || data->c.f == -1 || data->f.f == -1)
	{
		ft_putstr_fd("Error\ntype1:Map Error\n", 2);
		clear_map(data);
		return(1);
	}
	if (save_game_map(data) < 3 || map_char_ctrl(data, "01NSEW ", "NWES") || !map_wall_ctrl(data))
	{
		ft_putstr_fd("Error\ntype2:Map Error\n", 2);
		clear_map(data);
		return(1);
	}
	fill_the_space(data);
	fill_the_wall(data);
	map = ft_calloc(sizeof(t_map), 1);
	find_start_pos(data, map);
	maintwo(data);
	return (0);
}

















//printf
/* 	int i = 0;
	while (data->collect_lines[i])
	{
		printf("%s<", data->collect_lines[i]);
		i++;
	}
	getchar();
	printf("NO %s\n", data->no);
	printf("EA %s\n", data->ea);
	printf("SO %s\n", data->so);
	printf("WE %s\n", data->we);
	printf("FR %d\n", data->f.r);
	printf("FG %d\n", data->f.g);
	printf("FB %d\n", data->f.b);
	printf("CR %d\n", data->c.r);
	printf("CG %d\n", data->c.g);
	printf("CB %d\n", data->c.b);
	getchar();
	printf("\n\n");
	system("leaks cub3D"); */

//game_map
/* 		int z = 0;
	while(data->game_lines[z])
	{
		printf("%s", data->game_lines[z]);
		z++;
	} */


//collect_map:
/* 	int z = 0;
	while(data->collect_lines[z])
	{
		printf("z:%d	%s", z, data->collect_lines[z]);
		z++;
	} */