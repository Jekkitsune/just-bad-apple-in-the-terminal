/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparis <fparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:46:14 by fparis            #+#    #+#             */
/*   Updated: 2024/04/24 17:57:18 by fparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_reader.h"

void	ft_sleep(char *time)
{
	int		pid;
	char	**cmd;

	//usleep(100000);
	//return ;
	cmd = malloc(sizeof(char *) * 3);
	cmd[0] = "/bin/sleep";
	cmd[1] = time;
	cmd[2] = NULL;
	pid = fork();
	if (!pid)
	{
		execve(cmd[0], cmd, NULL);
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
	free(cmd);
}

void	line_reader(char *path, int size)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_sleep("0.03333");
		printf("\033c");
		i = 0;
		while (line[i])
		{
			if (i % size == 0)
				printf("\n");
			if (line[i] == '1')
				printf("#");
			else
				printf(" ");
			i++;
		}
		free(line);
		line = get_next_line(fd);
		if (!line)
			return ;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("first argument: txt path\nsecond argument: size\n");
		return (1);
	}
	line_reader(argv[1], ft_atoi(argv[2]));
}