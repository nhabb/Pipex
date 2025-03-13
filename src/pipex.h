/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:52:06 by nhaber            #+#    #+#             */
/*   Updated: 2025/03/13 08:18:31 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

void	freearray(char **array);
char	*findcommandpath(char **comand, char **envp);
void	findpath(char ***envp);
void	executecmd(char *input, char **envp);
void	error(void);
void	cmd1(char **envp, char **argv, int *cfd);
void	cmd2(char **envp, char **argv, int *cfd);
void	parentproccess(char **envp, char **argv);
int		check_input(char *input);
#endif