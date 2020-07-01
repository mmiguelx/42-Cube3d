/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubelib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:55:57 by mpernia-          #+#    #+#             */
/*   Updated: 2020/03/05 14:33:37 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBELIB_H
# define CUBELIB_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "includes/libft/libft.h"
# include "includes/error.h"

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define UDIV 1.2
# define VDIV 1.2

# define NORTH_TEXT 0
# define SOUTH_TEXT 1
# define EAST_TEXT 2
# define WEST_TEXT 3
# define FLOOR_TEXT 4
# define CEALING_TEXT 5
# define SPRITE_TEXT 6

# define BITMAP_SIZE 54
# define BITS_PER_PIXEL 24
# define DPI 2835
# define OFFSET 14
# define DIB_HEADER 40

# define MAX_SCREEN_HEIGHT 2560
# define MAX_SCREEN_WIDTH 1440
# define MIN_SCREEN_RESOLUTION 200

typedef struct	s_player
{
	int			side;
	int			step_x;
	int			step_y;
	char		dir;
	double		step;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		old_dir_x;
}				t_player;

typedef struct	s_camera
{
	int			y;
	int			hit;
	int			map_x;
	int			map_y;
	int			cell_x;
	int			cell_y;
	float		pos_z;
	float		floor_x;
	float		floor_y;
	float		ray_dir_x0;
	float		ray_dir_y0;
	float		ray_dir_x1;
	float		ray_dir_y1;
	float		row_distance;
	float		floor_step_x;
	float		floor_step_y;
	double		x;
	double		wall_x;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		old_plane_x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		*z_buffer;
}				t_camera;

typedef struct	s_draw
{
	int			sl;
	int			bbp;
	int			end;
	int			red;
	int			blue;
	int			green;
	int			start;
	int			line_h;
	int			endian;
	int			tex_num;
	int			texture_x;
	int			texture_y;
	int			floor_red;
	int			floor_blue;
	int			*view_data;
	int			floor_color;
	int			*texture[7];
	int			fc_textures;
	int			floor_green;
	int			cealing_red;
	int			cealing_blue;
	int			screen_width;
	int			cealing_green;
	int			screen_height;
	int			cealing_color;
	int			texture_x_floor;
	int			texture_y_floor;
	void		*view_ptr;
	void		*texture_ptr;
	double		tex_pos;
}				t_draw;

typedef struct	s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			f;
	int			left;
	int			right;
}				t_keys;

typedef struct	s_sprites
{
	int			num;
	int			width;
	int			*used;
	int			height;
	int			screen_x;
	int			v_move_screen;
	int			texture_x;
	int			texture_y;
	int			draw_end_x;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_start_y;
	double		*x;
	double		*y;
	double		pos_x;
	double		pos_y;
	double		inv_det;
	double		*distance;
	double		transform_x;
	double		transform_y;
}				t_sprites;

typedef struct	s_params
{
	int			save_bmp;
	int			map_width;
	int			map_height;
	int			**world_map;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*map_str;
	t_draw		*draw;
	t_keys		*keys;
	t_player	*player;
	t_camera	*camera;
	t_sprites	*sprites;
}				t_params;

int				exit_game(t_params *prm);
int				get_index(t_params *prm);
int				sprites_init(t_params *prm);
int				move_and_draw(t_params *prm);
int				key_pressed(int key, t_params *prm);
int				key_released(int key, t_params *prm);
int				get_color(int red, int green, int blue);

void			error_handler(int i);
void			ray_y(t_params *prm);
void			create_bmp(t_params *prm);
void			camera_hit(t_params *prm);
void			player_init(t_params *prm);
void			wall_casting(t_params *prm);
void			pick_texture(t_params *prm);
void			set_start_end(t_params *prm);
void			draw_on_screen(t_params *prm);
void			get_wall_height(t_params *prm);
void			sprites_casting(t_params *prm);
void			read_file(t_params *prm, int fd);
void			calculate_distances(t_params *prm);
void			load_extra_textures(t_params *prm);
void			read_map(t_params *prm, char *line);
void			set_values_and_ray_x(t_params *prm);
void			floor_ceiling_casting(t_params *prm);
void			move_up_down(t_params *prm, double speed);
void			move_left_right(t_params *prm, double speed);
void			check_and_set_textures(t_params *prm, char *line);
void			rotate_left_right(t_params *prm, double rot_speed);
void			check_and_set_resolution(t_params *prm, char *line);
void			check_and_set_floor_color(t_params *prm, char *line);
void			check_and_set_cealing_color(t_params *prm, char *line);
void			argument_checker(int argc, char **argv, t_params *prm);

#endif
