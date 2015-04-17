/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 11:35:57 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/10 18:58:11 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_command(char **arg, char **e)
{
	if (ft_strcmp(arg[0], "exit") == 0)
		exit(0);
	else if (ft_findbuiltin(arg) == 1)
		e = ft_cd(arg, e);
	else if (ft_findbuiltin(arg) == 0)
		e = ft_builtin(arg, e);
	else
		ft_exe(arg, e);
	return (e);
}

int		main(int ac, char **av, char **env)
{
	char	buf[1000];
	int		nb;
	char	**arg;
	char	**e;

	if (ac && av && env)
		e = ft_env(env);
	while (1)
	{
		ft_putstr("<3 ");
		nb = read(0, buf, 1000);
		if (nb == 0)
		{
			ft_putchar('\n');
			exit(0);
		}
		buf[nb - 1] = '\0';
		arg = get_arg(buf);
		if (arg[0] && env[0])
			e = ft_command(arg, e);
	}
	return (0);
}
