/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:30:04 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/10 19:57:30 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_setenv(char **env, char *param, char *swap)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while ((ft_strncmp(env[i], param, ft_strlen(param)) != 0) &&
i < ft_tablen(env) - 1)
		i++;
	if ((i + 1) == ft_tablen(env))
	{
		env = ft_tabreallocmore(env);
		env[i + 1] = ft_strdup(param);
		env[i + 1] = ft_strjoin(env[i + 1], "=");
		env[i + 1] = ft_strjoin(env[i + 1], swap);
		return (env);
	}
	while (env[i][j] != '=')
		j++;
	j++;
	env[i] = ft_strnew((ft_strlen(swap) + ft_strlen(param) + 1));
	env[i] = ft_strjoin(env[i], param);
	env[i] = ft_strjoin(env[i], "=");
	env[i] = ft_strjoin(env[i], swap);
	return (env);
}
