/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/10/09 14:55:52 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"
#include "../header_files/cub3d_minimap.h"

int	main(int argc, char *argv[])
{
	int			fd;
	t_cub3d		cub3d_data;
	t_minimap	minimap;

	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	if (read_file(fd, &cub3d_data) != TRUE)
		return (-1);
	cub3d_data.player->mini_player = NULL;
	cub3d_data.player->x_position += 0.5;
	cub3d_data.player->y_position += 0.5;
	printf("x:%f, y:%f\n", cub3d_data.player->x_position, cub3d_data.player->y_position);
	printf("%d\n", cub3d_data.player->orientation);
	initiate_window(&cub3d_data);
	init_minimap(&cub3d_data, &minimap);
	ft_memset(cub3d_data.img->pixels, 255, cub3d_data.img->width * cub3d_data.img->height * sizeof(int32_t));
	draw_minimap(&cub3d_data, &minimap);
	mlx_key_hook(cub3d_data.window, &esc_keyfunc, (void *)cub3d_data.window);
	mlx_loop_hook(cub3d_data.window, (void (*)(void *))generic_hooks, &cub3d_data);
	mlx_loop(cub3d_data.window);
	mlx_delete_image(cub3d_data.window, cub3d_data.img);
	mlx_terminate(cub3d_data.window);
	free(cub3d_data.map);
	return (0);
}



