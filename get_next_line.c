#include "get_next_line.h"

static char	*check_remainder(char **remainder, char **line)
{
	char		*tmp;
	char		*tmp2;

	tmp = NULL;
	*line = ft_strdup("");
	if (*remainder)
	{
		if ((tmp = ft_strchr(*remainder, '\n')))
		{
			*tmp = '\0';
			tmp2 = *line;
			*line = ft_strjoin(*line, *remainder);
			free(tmp2);
			tmp2 = *remainder;
			*remainder = ft_strdup(++tmp);
			free(tmp2);
			return (tmp);
		}
		tmp2 = *line;
		*line = ft_strdup(*remainder);
		free(tmp2);
		free(*remainder);
		*remainder = NULL;
	}
	return (NULL);
}

int			get_next_line(int fd, char **line)
{
	char		buf[2];
	char		*tmp;
	char		*new_line;
	static char *remainder;
	int			read_bytes;

	if (fd < 0 || !(line) || read(fd, buf, 0) == -1)
		return (-1);
	tmp = NULL;
	tmp = check_remainder(&remainder, line);
	while (!tmp && (read_bytes = read(fd, buf, 1)) > 0)
	{
		buf[read_bytes] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
		{
			*tmp = '\0';
			tmp++;
			remainder = ft_strdup(tmp);
		}
		new_line = *line;
		*line = ft_strjoin(*line, buf);
		free(new_line);
	}
	return ((read_bytes || (remainder)) ? 1 : 0);
}
