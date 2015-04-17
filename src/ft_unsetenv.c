/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:33:57 by aliandie          #+#    #+#             */
/*   Updated: 2015/03/02 20:58:21 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		**ft_unsetenv(char **env, char *param)
{
	int	i;
	int memi;

	i = 0;
	param = ft_strjoin(param, "=");
	while (i < ft_tablen(env))
	{
		if ((ft_strncmp(env[i], param, ft_strlen(param)) == 0))
			memi = i;
		i++;
	}
	env = ft_tabreallocless(env, memi);
	return (env);
}
