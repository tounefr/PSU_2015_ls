##
## Makefile for  in /home/thomas/Documents/LS
## 
## Made by Thomas Henon
## Login   <thomas.henon@epitech.eu>
## 
## Started on  Fri Nov 27 17:40:06 2015 Thomas Henon
## Last update Sun Nov 29 23:45:42 2015 Thomas Henon
##

NAME	= my_ls

CC	= gcc

RM	= rm -f

CFLAGS = -g
CFLAGS += -l my -L ./my -I ./my
CFLAGS += -I ./include

SRCS	=	ls.c \
		linked_lists.c \
		linked_lists2.c \
		ls_sort.c \
		ls_details.c \
		ls_util.c \
		ls_util2.c \
		ls_args.c \
		ls_display.c \
		ls_display2.c \
		ls_main.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
