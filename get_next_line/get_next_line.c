#include "get_next_line.h"

void	to_next_line(char *buff, char **memo, int ret, char **rtn)
{
	int		first_idx;
	char	*temp;

	first_idx = find_first_idx(buff, '\n');
	if (first_idx < ret)
	{
		if (*memo)
		{
			temp = ft_substr(*memo, first_idx + 1, (ret - first_idx - 1));
			free(*memo);
			*memo = temp;
		}
		else if (buff[first_idx + 1])
			*memo = ft_substr(buff, first_idx + 1, (ret - first_idx - 1));
	}
	buff[first_idx + 1] = 0;
	if (!*rtn)
		*rtn = ft_strdup(buff);
	else
	{
		temp = ft_strjoin(*rtn, buff);
		free(*rtn);
		*rtn = temp;
	}
}

int	check_buff(char *buff, char **memo, int ret, char **rtn)
{
	int		i;
	char	*temp;

	buff[ret] = 0;
	i = find_first_idx(buff, '\n');
	if (i != -1)
	{
		to_next_line(buff, memo, ret, rtn);
		return (1);
	}
	if (!*rtn)
		*rtn = ft_strdup(buff);
	else
	{
		temp = ft_strjoin(*rtn, buff);
		free(*rtn);
		*rtn = temp;
	}
	return (0);
}

int	check_memo(char **memo, char **rtn)
{
	int		len_memo;
	int		first_idx;
	char	*temp;

	first_idx = find_first_idx(*memo, '\n');
	len_memo = ft_strlen(*memo);
	if (first_idx != -1)
	{
		if (first_idx < len_memo - 1)
		{
			*rtn = ft_substr(*memo, 0, first_idx + 1);
			temp = ft_substr(*memo, first_idx + 1, len_memo - first_idx - 1);
			free(*memo);
			*memo = temp;
			return (1);
		}
		*rtn = *memo;
		*memo = 0;
		return (1);
	}
	temp = ft_strjoin("", *memo);
	free(*memo);
	*memo = 0;
	*rtn = temp;
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*rtn;
	static char	*memo;
	int			ret;

	rtn = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (memo && check_memo(&memo, &rtn))
		return (rtn);
	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		if (check_buff(buff, &memo, ret, &rtn))
		{
			free(buff);
			return (rtn);
		}
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (rtn);
}
