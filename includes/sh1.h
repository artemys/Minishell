/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:20:49 by aliandie          #+#    #+#             */
/*   Updated: 2015/04/10 19:27:49 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>

void				ft_puttab(char **tab);
char				*get_path(char *buf, char *tab);
char				**get_arg(char *buf);
int					ft_tablen(char **tab);
char				**ft_env(char **env);
char				**ft_tabreallocmore(char **env);
char				**ft_setenv(char **env, char *param, char *swap);
char				**ft_setenvvoid(char **env, char *param);
char				**ft_tabreallocless(char **env, int j);
size_t				ft_paramlen(char *env);
char				**ft_unsetenv(char **env, char *param);
char				**ft_builtin(char **arg, char **e);
int					ft_findbuiltin(char **arg);
int					find_arg(char **e, char *arg);
char				*get_param(char *e);
char				**ft_cd(char **arg, char **e);
char				*set_newenv(char *n, char **arg);
void				ft_exe(char **arg, char **env);

typedef	struct		s_exe
{
	char	**tab;
	int		i;
	pid_t	test;
	int		w;
	char	*tmp;
}					t_exe;

typedef	struct		s_cd
{
	char	*tmp;
	int		pwd;
	char	*tmp2;
}					t_cd;

#endif
