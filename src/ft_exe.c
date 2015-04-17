/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:16:29 by aliandie          #+#    #+#             */
/*   Updated: 2015/03/04 16:15:23 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char **set_tab(char **env)
{
	char **tab;

	if (find_arg(env, "PATH") == -1)
		tab = ft_strsplit(ft_strdup("/bin:/usr/bin"), ':');
	else
		tab = ft_strsplit(get_param(env[find_arg(env, "PATH")]), ':');
	return (tab);
}

void ft_exe(char **arg, char **env)
{
	t_exe	exe;

	exe.i = 0;
	exe.test = 1;
	exe.test = fork();
	exe.tab = set_tab(env);
	if (exe.test > 0)
		wait(&exe.w);
	if (exe.test == 0)
	{
		execve(arg[0], arg, env);
		if (ft_findbuiltin(arg) < 0)
		{
			while (exe.tab[exe.i])
			{
				exe.tmp = get_path(arg[0], exe.tab[exe.i]);
				execve(exe.tmp, arg, env);
				exe.i++;
			}
			ft_putstr("Error: Command not found\n");
		}
		exit(0);
	}
}
