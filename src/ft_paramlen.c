/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:32:58 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/17 13:49:06 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

size_t	ft_paramlen(char *env)
{
	size_t	len;

	len = 0;
	while (env[len] != '=')
		len++;
	return (len);
}
