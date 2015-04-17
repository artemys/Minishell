/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenvvoid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:30:54 by aliandie          #+#    #+#             */
/*   Updated: 2015/03/02 20:57:18 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		**ft_setenvvoid(char **env, char *param)
{
	int		i;

	i = 0;
	if (param)
	{
		while ((ft_strncmp(env[i], param, ft_strlen(param)) != 0) &&
				i < ft_tablen(env) - 1)
			i++;
		if ((i + 1) == ft_tablen(env))
		{
			env = ft_tabreallocmore(env);
			env[i + 1] = ft_strdup(param);
			env[i + 1] = ft_strjoin(env[i + 1], "=");
		}
	}
	else
		ft_puttab(env);
	return (env);
}
