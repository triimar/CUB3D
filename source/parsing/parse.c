/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:16:45 by crepou            #+#    #+#             */
/*   Updated: 2023/09/30 16:11:41 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

/*getting the line with the colors and save each inside a t_color struct*/
int	get_color(char *line, t_color *color)
{
	char	**colors;

	colors = ft_split(line, ',');
	if (!colors)
		return (printf("Error!\n Problem during saving color.\n"), FALSE);
	if (!colors[0] || !is_number(colors[0]))
		return (free_after_split(colors), FALSE);
	color->red = ft_atoi(colors[0]);
	if (!colors[1] || !is_number(colors[1]))
		return (free_after_split(colors), FALSE);
	color->green = ft_atoi(colors[1]);
	if (!colors[2] || !is_number(colors[2]))
		return (free_after_split(colors), FALSE);
	color->blue = ft_atoi(colors[2]);
	free_after_split(colors);
	return (TRUE);
}

/* It process and saves the info of the map*/
int	save_information(t_info *map_info, char *line)
{
	if (!ft_strncmp(line, "\n", 1))
		return (TRUE);
	if (!ft_strncmp(line, "NO ", 3))
		map_info->north_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "SO ", 3))
		map_info->south_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "EA ", 3))
		map_info->east_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "WE ", 3))
		map_info->west_texture = get_info(line, 3, -1);
	else if (!ft_strncmp(line, "F ", 2))
	{
		if (!get_color(get_info(line, 2, -1), &map_info->floor_color))
			return (printf("This is not a correct color!\n"), FALSE);
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (!get_color(get_info(line, 2, -1), &map_info->ceiling_color))
			return (printf("This is not a correct color!\n"), FALSE);
	}
	if (files_exist(map_info))
		return (TRUE);
	return (FALSE);
}

void	print_list(t_line *head)
{
	int	i;

	i = 0;
	while (head)
	{
		printf("Line %d: %s\n", i, head->ln);
		i++;
		head = head->next;
	}
}

int	save_line(char *line, t_cub3d *cub3d_info)
{
	int		*ln;
	int		i;
	char	*curr_num;

	ln = (int *)malloc(cub3d_info->width * sizeof(int));
	if (!ln)
		return (printf("Problem during allocation!\n"), FALSE);
	i = -1;
	while (++i < cub3d_info->width)
	{
		if (line[i] == 32)
			ln[i] = -1;
		else if (ft_isdigit(line[i]))
		{
			curr_num = char_to_string(line[i]);
			ln[i] = ft_atoi(curr_num);
			free(curr_num);
		}
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			ln[i] = -2;
		else
			return (printf("Error! This is not a valid line: %s\n", line), free(ln), FALSE);
	}
	cub3d_info->map[cub3d_info->index] = ln;
	return (cub3d_info->index++, TRUE);
}

int	create_map_array(t_line *head, t_cub3d *cub3d_info)
{
	t_line	*list;

	list = head;
	cub3d_info->width = get_width(head->ln);
	cub3d_info->index = 0;
	cub3d_info->map = (int **)malloc(cub3d_info->height * sizeof(int *));
	while (list)
	{
		if (!save_line(list->ln, cub3d_info))
			return (FALSE);
		list = list->next;
	}
	printf("SUCCESS: saved all lines!\n");
	return (TRUE);
}

int	save_map(t_cub3d *cub3d_info, char *curr_line, int fd)
{
	t_line	*map_lines;
	t_line	*tail;
	t_line	*head;

	if (!curr_line)
		return (printf("Error!\n There is not map to parse\n"), FALSE);
	tail = (t_line *)malloc(sizeof(t_line));
	if (!tail)
		return (printf("Error!\n Map allocation problem\n"), FALSE);
	tail->ln = curr_line;
	tail->next = NULL;
	head = tail;
	cub3d_info->height = 0;
	while (!is_empty_file(&curr_line, fd))
	{
		map_lines = (t_line *)malloc(sizeof(t_line));
		if (!map_lines)
			return (free_map_lines(head), \
				printf("Error!\n Map allocation problem\n"), FALSE);
		map_lines->ln = curr_line;
		map_lines->next = NULL;
		tail->next = map_lines;
		tail = tail->next;
		cub3d_info->height++;
	}
	//print_list(head);
	create_map_array(head, cub3d_info);
	return (free_map_lines(head), TRUE);
}
