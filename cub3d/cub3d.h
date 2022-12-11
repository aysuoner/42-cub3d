/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:47:26 by aoner             #+#    #+#             */
/*   Updated: 2022/12/02 14:54:29 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define  CUB3D_H
# define BUFFER_SIZE 100
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_map
{
	int		x;
	int		y;
	float	ang; ///float????
} t_map;

typedef struct s_pixel
{
	int	o;
	int	r;
	int	g;
	int	b;
	int	f;
} t_pixel;

typedef struct s_image
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bbp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_data
{
    int	    	fd;
    char		**collect_lines;
	char		**game_lines;
	int			last_element_line;
	int			game_start_line;
	int			game_last_line;
	int			game_line_count;
    int			tot_line_count;
	char		*no; //no,so,we,ea map structuna atabilirsin:
	char		*so;
	char		*we;
	char		*ea;
	void		*mlx;
	void		*mlx_win;
	int			floor_color;
	int			ceil_color;
	int			x_size;
	int			y_size;
	float		look;
	t_image		screen;
	t_image		imgs[4];
	t_pixel		f;
	t_pixel		c;
} t_data;



int		main(int argc, char **argv);
void	save_cub_file(char *path, t_data *data);
int		save_game_map(t_data *data);
int		ft_strcmp(const char *s1, const char *s2);

//cleaner
int	clear_map(t_data *data);

//start_game
void	start_game(t_data *data, t_map *map);
void	render(t_data *data);
void	fill_screen(t_data *data);

//controller;
void    exist_file_ctrl(char *path, t_data *data);
void	argc_ctrl(int argc);
void	map_name_ctrl(char **argv);
int     map_linecount_ctrl(t_data *data);
int		unwanted_element_ctrl(char c);
int		map_char_ctrl(t_data *data, char *diff_char, char *just_one);
int		map_wall_ctrl(t_data *data);

//Utils
int		is_space(int c);
int		is_valid_space(int c);
void	fill_the_space(t_data *data);
void	fill_the_wall(t_data *data);

//PARser
void	find_start_pos(t_data *data, t_map *map);

//classify_the_elements
int		classify_the_elements(t_data *data);

//mlx_image_setup
void	ft_image_setup(t_data *data);

//GNL
char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_get_line(char *save);
int     has_return(char *str);
char	*ft_strjoingnl(char *s1, char const *s2);
size_t	ft_strlengnl(const char *s);

#endif