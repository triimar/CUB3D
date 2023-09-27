/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:29:46 by crepou            #+#    #+#             */
/*   Updated: 2023/09/27 16:54:59 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	main(int argc, char *argv[])
{
	int	fd;
	t_displ s_displ;

	fd = is_input_valid(argc, argv);
	if (!fd)
		return (-1);
	initiate_window(&s_displ);
	mlx_key_hook(s_displ.window, &single_key_h, (void *)&s_displ);
	mlx_loop(s_displ.window);
	mlx_delete_image(s_displ.window, s_displ.image);
	mlx_terminate(s_displ.window);
	return (0);
}



