##
## Makefile for Makefile in /home/e.goumy/my_tar
## 
## Made by Eléonore Goumy
## Login   <e.goumy@epitech.net>
## 
## Started on  Fri Mar  3 20:30:20 2017 Eléonore Goumy
## Last update Fri Mar  3 20:40:04 2017 Eléonore Goumy
##

SRC1	=

SRC2	=

SRC3	=

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

OBJ3	=	$(SRC3:.c=.o)

NAME1	=	my_archive

NAME2	=	my_unarchive

NAME3	=	my_tar

CFLAG	=	-I include

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(OBJ1)
	gcc $(OBJ1) -o $(NAME1) $(CFLAGS)

$(NAME2): $(OBJ2)
	gcc $(OBJ2) -o $(NAME2) $(CFLAGS)

$(NAME3): $(OBJ3)
	gcc $(OBJ3) -o $(NAME3) $(CFLAGS)

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3)

fclean: clean
	rm -f $(NAME1) $(NAME2) $(NAME3)

re: fclean all

.PHONY: all clean fclean re
