# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME		= materia

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g


# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

OBJ_DIR = objs/

SRCS =		main.cpp \
			srcs/AMateria.cpp \
			srcs/Character.cpp \
			srcs/Cure.cpp \
			srcs/Ice.cpp \
			srcs/MateriaSource.cpp \
			utils/utils.cpp


# **************************************************************************** #
#                                   COMPIL                                     #
# **************************************************************************** #

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re