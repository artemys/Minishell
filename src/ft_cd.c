/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:18:19 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/14 16:53:10 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char **go_home(char *tmp, char **arg, char **e)
{
	int		pwd;
	char	*new;

	if (!(new = malloc(sizeof(char) * ft_strlen(e[find_arg(e, "HOME")]) - 5)))
		return (NULL);
	new = get_param(e[find_arg(e, "HOME")]);
	if (new == NULL)
		exit(0);
	if (ft_strlen(arg[1]) > 1)
		new = set_newenv(new, arg);
	chdir(new);
	pwd = find_arg(e, "PWD");
	if (pwd != -1)
	{
		e[find_arg(e, "OLDPWD")] = ft_strjoin("OLDPWD=", get_param(e[pwd]));
		e[pwd] = ft_strjoin("PWD=", getcwd(tmp, 2048));
	}
	free(new);
	return (e);
}

char **go_home_directory(char *tmp, char **e)
{
	int		pwd;
	char	*new;

	new = malloc(sizeof(char) * ft_strlen(e[find_arg(e, "HOME")]) - 5);
	new = get_param(e[find_arg(e, "HOME")]);
	if (new == NULL)
		exit(0);
	chdir(new);
	pwd = find_arg(e, "PWD");
	if (pwd != -1)
	{
		e[find_arg(e, "OLDPWD")] = ft_strjoin("OLDPWD=", get_param(e[pwd]));
		e[pwd] = ft_strjoin("PWD=", getcwd(tmp, 2048));
	}
	free(new);
	return (e);
}

void creat_new_pwd(char *tmp, char **arg)
{
	char *new;

	if (ft_strcmp(arg[1], "/") != 0)
	{
		new = ft_strjoin(getcwd(tmp, 2048), "/");
		new = ft_strjoin(new, arg[1]);
		new = ft_strjoin(new, "/");
	}
	else
		new = ft_strdup("/");
	chdir(new);
}

char **ft_cd(char **arg, char **e)
{
	t_cd	c;

	c.pwd = find_arg(e, "PWD");
	c.tmp = NULL;
	c.tmp2 = ft_strchr(e[c.pwd], '=');
	if (find_arg(e, "HOME") == -1)
		e = ft_setenv(e, "HOME", getcwd(c.tmp, 2048));
	if (!arg[1] && e[0])
		e = go_home_directory(c.tmp, e);
	else if (ft_strncmp(arg[1], "~", 1) == 0 && e[0])
		e = go_home(c.tmp, arg, e);
	else if (access(arg[1], F_OK) == -1 && e[0])
		ft_putendl("Error : No such file or directory.");
	else if (c.pwd == -1 && e[0])
		creat_new_pwd(c.tmp, arg);
	else if (arg[1] && access(arg[1], F_OK) == 0 && e[0])
	{
		creat_new_pwd(c.tmp, arg);
		c.pwd = find_arg(e, "PWD");
		e[find_arg(e, "OLDPWD")] = ft_strjoin("OLDPWD", c.tmp2);
		e[c.pwd] = ft_strjoin("PWD=", getcwd(c.tmp, 2048));
	}
	return (e);
}
