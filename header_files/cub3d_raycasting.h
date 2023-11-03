/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:24:57 by tmarts            #+#    #+#             */
/*   Updated: 2023/11/03 15:26:12 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCASTING_H
# define CUB3D_RAYCASTING_H

# define CUBE_SIDE 126
# define PLAYER_EYELINE 64
# define ANGLE_TOLERANCE 0.002

# include "cub3d.h"

typedef struct s_raycaster
{
	double			proj_distance;
	double			ray_angle_step;
}	t_caster;

typedef struct s_ray
{
	double			true_angle;
	double			hit_x;
	double			hit_y;
	double			distance;
	t_orientation	wall;
	int				wall_h;
}	t_ray;

typedef struct s_pt
{
	double	x;
	double	y;
}	t_pt;

typedef struct s_ray_utils
{
	int			modifier;
	int			direction;
	t_player	*pt_0;
}	t_ray_utils;

void	initiate_casting(t_caster *cast_data);
void	get_ray_data(t_cub3d *cub3d, t_ray *ray);
void	draw_column(t_cub3d *cub3d_data, double ray_angle, int ray_i);
void	draw_raycast_image(t_cub3d *cub3d_data);

bool	is_wall_hit(char **map, int x, int y);
double	remove_distortion(double distance, double angle_offcenter);
double	get_true_angle(double player_angle, double ray_angle);

#endif