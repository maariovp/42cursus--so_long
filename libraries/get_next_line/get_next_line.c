/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavicent <mavicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:39 by mavicent          #+#    #+#             */
/*   Updated: 2023/05/30 00:34:26 by mavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delete_first_line(char *file)
{
	char	*temp;
	size_t	file_index;
	size_t	temp_index;

	file_index = 0;
	while (file[file_index] != '\0' && file[file_index] != '\n')
		file_index++;
	if (!file[file_index])
	{
		free(file);
		return (NULL);
	}
	temp = ft_calloc((ft_strlen(file) - file_index), sizeof(char));
	file_index++;
	temp_index = 0;
	while (file[file_index] != '\0')
		temp[temp_index++] = file[file_index++];
	free(file);
	return (temp);
}

char	*get_first_line(char *file)
{
	char	*f_line;
	size_t	index;

	index = 0;
	if (!file[index])
		return (NULL);
	while (file[index] != '\0' && file[index] != '\n')
		index++;
	f_line = ft_calloc(index + 2, sizeof(char));
	index = 0;
	while (file[index] != '\0' && file[index] != '\n')
	{
		f_line[index] = file[index];
		index++;
	}
	if (file[index] == '\n')
		f_line[index] = '\n';
	return (f_line);
}

char	*ft_free(char *file, char *temp)
{
	char	*final;

	final = ft_strjoin(file, temp);
	free(file);
	return (final);
}

char	*ft_makefile(int fd, char *file)
{
	char	*temp;
	ssize_t	r_bytes;

	if (!file)
		file = ft_calloc(1, 1);
	if (ft_strchr(file, '\n'))
		return (file);
	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	r_bytes = 1;
	while (r_bytes > 0)
	{
		r_bytes = read(fd, temp, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(temp);
			free(file);
			return (NULL);
		}
		temp[r_bytes] = 0;
		file = ft_free(file, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = ft_makefile(fd, file);
	if (!file)
		return (NULL);
	line = get_first_line(file);
	file = delete_first_line(file);
	return (line);
}
