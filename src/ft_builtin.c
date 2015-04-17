/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:11:07 by aliandie          #+#    #+#             */
/*   Updated: 2015/03/04 16:15:26 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_builtin(char **arg, char **e)
{
	int		j;

	j = 1;
	if (ft_strcmp(arg[0], "setenv") == 0)
	{
		if (arg[2])
			e = ft_setenv(e, arg[1], arg[2]);
		else
			e = ft_setenvvoid(e, arg[1]);
	}
	if (ft_strcmp(arg[0], "env") == 0)
		ft_puttab(e);
	if (ft_strcmp(arg[0], "unsetenv") == 0)
	{
		if (find_arg(e, arg[j]) != -1)
		{
			while (arg[j])
			{
				e = ft_unsetenv(e, arg[j]);
				j++;
			}
		}
	}
	return (e);
}
