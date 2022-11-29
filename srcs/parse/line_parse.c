/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:41:52 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 18:47:46 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_table_lines(int **table)
{
	int	i;

	i = 0;
	while (table[i] != NULL)
		i++;
	return (i);
}

int	**table_realloc(int **table)
{
	int	**new_table;
	int	i;

	if (!table)
	{
		table = malloc(sizeof(*table));
		if (!table)
			return (NULL);
		table[0] = NULL;
	}
	new_table = malloc(sizeof(*table) * (count_table_lines(table) + 2));
	if (!new_table)
		return (NULL);
	i = -1;
	while (++i < count_table_lines(table))
	{
		new_table[i] = table[i];
	}
	new_table[i++] = NULL;
	new_table[i] = NULL;
	free(table);
	return (new_table);
}

int	*get_int_line(char *line, int *line_size)
{
	char	**split;
	int		*int_line;
	int		length;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	length = 0;
	while (split[length] != NULL)
		length++;
	int_line = malloc(sizeof(int) * (length));
	if (int_line)
	{
		i = -1;
		while (++i < length)
			int_line[i] = ft_atoi(split[i]);
		*line_size = i;
	}
	length = -1;
	while (split[++length] != NULL)
		free(split[length]);
	free(split);
	return (int_line);
}

int	**process_line(char *line, int **table, int *line_size)
{
	int	*int_line;

	table = table_realloc(table);
	if (!table)
		return (NULL);
	int_line = get_int_line(line, line_size);
	if (!int_line)
		return (NULL);
	if (count_table_lines(table) == 0)
		table[0] = int_line;
	else
		table[count_table_lines(table)] = int_line;
	return (table);
}
