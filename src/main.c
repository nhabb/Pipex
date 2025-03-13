/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:02:34 by nhaber            #+#    #+#             */
/*   Updated: 2025/02/03 14:33:29 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	cmd1(char **envp, char **argv, int *cfd)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		error();
	close(cfd[0]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(cfd[1], STDOUT_FILENO);
	close(cfd[1]);
	executecmd(argv[2], envp);
}

void	cmd2(char **envp, char **argv, int *Cfd)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error();
	close(Cfd[1]);
	dup2(Cfd[0], STDIN_FILENO);
	close(Cfd[0]);
	dup2(fd, STDOUT_FILENO);
	executecmd(argv[3], envp);
}

void	parentproccess(char **envp, char **argv)
{
	int	pid;
	int	cfd[2];

	if (pipe(cfd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		cmd1(envp, argv, cfd);
	else
	{
		wait(NULL);
		cmd2(envp, argv, cfd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_printf("Correct usage: ./pipex file1 cmd1 cmd2 file2");
		exit(1);
	}
	if (check_input(argv[2]) == 0 || check_input(argv[3]) == 0)
	{
		return (0);
	}
	parentproccess(envp, argv);
}

int	check_input(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] != ' ')
			j++;
		i++;
	}
	if (j == 0)
	{
		return (0);
	}
	return (1);
}
