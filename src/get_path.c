/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:22:23 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/23 16:02:15 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	*get_path(char *buf, char *tab)
{
	char	*tmp;

	tmp = ft_strjoin(tab, "/");
	tmp = ft_strjoin(tmp, buf);
	return (tmp);
}
