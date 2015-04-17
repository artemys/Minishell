# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/26 13:38:59 by aliandie          #+#    #+#              #
#    Updated: 2015/04/17 16:36:05 by aliandie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
CCLIB = -Llibft -lft
CCFLAGS = -Wall -Werror -Wextra
SRCDIR = src
OBJDIR = obj
INCDIR = includes libft/includes

SRC = 	main.c\
		find_arg.c\
		ft_findbuiltin.c\
		ft_cd.c\
		ft_env.c\
		ft_exe.c\
		ft_builtin.c\
		ft_paramlen.c\
		ft_puttab.c\
		ft_tablen.c\
		ft_setenv.c\
		ft_setenvvoid.c\
		ft_tabreallocless.c\
		ft_tabreallocmore.c\
		ft_unsetenv.c\
		get_arg.c\
		get_param.c\
		get_path.c\
		set_newenv.c\

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
		@make -C libft
		@gcc $(CCLIB) -o $(NAME) $(OBJS)
build:
		@mkdir -p $(OBJDIR)
clean:
		@make -C libft clean
		@rm -f $(OBJS)
fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)
re: fclean all

dev : all
		@./$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@gcc -c $(CCFLAGS) $(INCS) -o $@ $<
