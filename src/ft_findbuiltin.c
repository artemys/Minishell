/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findbuiltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:08:37 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/26 19:41:54 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		ft_findbuiltin(char **arg)
{
	if (ft_strcmp(arg[0], "cd") == 0)
		return (1);
	if (ft_strcmp(arg[0], "env") == 0)
		return (0);
	if (ft_strcmp(arg[0], "unsetenv") == 0)
		return (0);
	if (ft_strcmp(arg[0], "setenv") == 0)
		return (0);
	return (-1);
}
