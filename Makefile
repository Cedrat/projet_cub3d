# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 19:13:28 by lnoaille          #+#    #+#              #
#    Updated: 2020/09/18 14:27:23 by lnoaille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

SRCS =	./etc/free_all.c				\
		./engine/ft_distance_to_wall.c	\
	  	./parsing/ft_extract_reso.c		\
	  	./engine/ft_screen.c			\
		./parsing/ft_verif_map.c		\
		./gnl/get_next_line.c			\
		./engine/main.c					\
		./parsing/ft_color.c       		\
		./etc/ft_error_code.c        	\
		./parsing/ft_parsing1.c      	\
		./engine/ft_tri_sprite.c  		\
		./parsing/ft_verif_map_utils_2.c\
		./gnl/get_next_line_utils.c 	\
		./engine/ft_control.c     		\
		./parsing/ft_extract_data.c     \
		./engine/ft_pov.c           	\
		./etc/ft_utils.c       			\
		./parsing/ft_verif_map_utils.c  \
		./etc/init.c 					\
		./engine/ft_create_img.c 		\
		./parsing/ft_extract_map.c      \
		./parsing/ft_recup_sprite.c 	\
		./etc/ft_utils_two.c   			\
		./engine/ft_wall.c          	\
		./parsing/is_data.c  			\

OBJS = ${SRCS:.c=.o}

CFLAGS = -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror

RM = rm -f

all : 		${NAME}

${NAME}:	${OBJS}
			$(MAKE) -C mlx all
			gcc -o ${NAME} ${SRCS} mlx/libmlx_Linux.a  ${CFLAGS}

clean :
			${RM} ${OBJS}
			$(MAKE) -C mlx clean


fclean :	clean
			${RM} ${NAME}
			$(MAKE) -C mlx clean
			${RM} mlx/libmlx.a
			${RM} mlx/libmlx_Linux.a

re :		fclean all
