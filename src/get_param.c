/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:14:59 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/08 19:37:50 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		*get_param(char *e)
{
	size_t	i;
	int		j;
	char	*param;

	i = 0;
	j = 0;
	while (e[i] != '=')
		i++;
	i++;
	param = malloc(sizeof(char) * (ft_strlen(e) - i));
	while (i < ft_strlen(e))
	{
		param[j] = e[i];
		i++;
		j++;
	}
	return (param);
}
