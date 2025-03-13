/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:27:33 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/13 08:19:07 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	findpath(char ***envp)
{
	while (**envp != NULL)
	{
		if (ft_strnstr(**envp, "PATH=", 5) != NULL)
			return ;
		(*envp)++;
	}
}

char	*findcommandpath(char **comand, char **envp)
{
	char	**all_path;
	char	*finalpath;
	char	*cmdpath;
	int		i;

	findpath(&envp);
	all_path = ft_split(*envp + 5, ':');
	i = 0;
	while (all_path[i])
	{
		finalpath = ft_strjoin(all_path[i], "/");
		cmdpath = ft_strjoin(finalpath, *comand);
		free(finalpath);
		if (access(cmdpath, X_OK) == 0)
			return (cmdpath);
		free(cmdpath);
		i++;
	}
	freearray(all_path);
	return (NULL);
}

void	freearray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	executecmd(char *input, char **envp)
{
	char	**cmd;
	char	*executable;

	cmd = ft_split(input, ' ');
	executable = findcommandpath(cmd, envp);
	if (!cmd)
	{
		freearray(cmd);
		error();
	}
	if (executable == NULL)
	{
		freearray (cmd);
		error ();
	}
	if (execve(executable, cmd, envp) == -1)
	{
		freearray (cmd);
		error();
	}
}

void	error(void)
{
	ft_printf("ERROR\n");
	exit(1);
}
