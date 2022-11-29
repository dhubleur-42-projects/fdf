/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:33:34 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 18:48:08 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**read_error(int **table, int status)
{
	int	i;

	i = -1;
	if (!table)
	{
		while (table[++i] != NULL)
			free(table[i]);
		free(table);
	}
	if (status == -1)
		ft_putendl_fd("Memory allocation error", 1);
	if (status == -2)
		perror("The specified file cannot be read");
	if (status == -3)
		ft_putendl_fd("Impossible to parse file", 1);
	return (NULL);
}

int	**read_file(int fd, int *line_size, int *line_count)
{
	char	*line;
	int		status;
	int		**table;

	table = NULL;
	status = 0;
	while (TRUE)
	{
		line = get_next_line(fd, &status);
		if (!line)
		{
			if (status < 0)
				return (read_error(table, status));
			break ;
		}
		*line_count = *line_count + 1;
		table = process_line(line, table, line_size);
		if (!table)
		{
			free(line);
			return (read_error(table, -3));
		}
		free(line);
	}
	return (table);
}

t_map	*parse_map(char *file)
{
	int		fd;
	int		**table;
	int		line_size;
	int		line_count;
	t_map	*map;

	line_count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("The specified file cannot be open");
		return (NULL);
	}
	table = read_file(fd, &line_size, &line_count);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = table;
	map->line_count = line_count;
	map->line_size = line_size;
	close(fd);
	return (map);
}
