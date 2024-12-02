/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:57:45 by rlebaill          #+#    #+#             */
/*   Updated: 2024/11/12 09:26:59 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buff)
{
	char	*tmp;
	char	*line;
	char	*new_line;
	ssize_t	bytes_read;

	line = ft_strjoin(buff, "");
	while (!ft_strchr(line, '\n'))
	{
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tmp)
			return (free(line), NULL);
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), free(tmp), NULL);
		if (bytes_read == 0)
			return (free(tmp), line);
		tmp[bytes_read] = '\0';
		new_line = ft_strjoin(line, tmp);
		free(line);
		free(tmp);
		line = ft_strdup(new_line);
		free(new_line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_file(fd, buff);
	if (!line)
		return (buff[0] = '\0', NULL);
	if (!line[0])
		return (free(line), NULL);
	if (!ft_strchr(line, '\n'))
		return (ft_strcpy(buff, ""), line);
	ft_strcpy(buff, ft_strchr(line, '\n') + 1);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n' && line[i + 1])
		line[i + 1] = '\0';
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char *line;

// 	fd = open("get_next_line_utils.c", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
