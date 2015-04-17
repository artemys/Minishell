/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabreallocmore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:29:04 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/08 14:57:28 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_tabreallocmore(char **env)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char**)malloc(sizeof(char*) * (ft_tablen(env) + 2));
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	return (tmp);
}
