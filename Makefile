##
## EPITECH PROJECT, 2020
## PSU
## File description:
## Makefile
##


NM     =	src/nm/main.c

OBJ     =	src/obj/main.c			\
			src/obj/is_file.c		\
			src/obj/32/obj_32.c		\
			src/obj/64/obj_64.c		\
			src/obj/is_space.c

OBJNM     =       $(NM:.c=.o)

OBJDUMP     =       $(OBJ:.c=.o)

NAME_NM    =	my_nm

NAME_OBJ    =	my_objdump

CC	=	gcc -I ./include

FLAG	=	-W -I ./include

all:	$(NAME_NM) $(NAME_OBJ)

nm:	$(NAME_NM)

objdump: $(NAME_OBJ)

$(NAME_NM):	$(OBJNM)
	$(CC) -o $(NAME_NM) $(OBJNM) $(FLAG)
	@echo NM Completed

$(NAME_OBJ):	$(OBJDUMP)
	$(CC) -o $(NAME_OBJ) $(OBJDUMP) $(FLAG)
	@echo OBJ Completed

clean:
	rm -f $(shell find $(SOURCEDIR) -name '*.o')
	rm -f vgcore*

fclean: clean
	rm -f $(NAME_NM)
	rm -f $(NAME_OBJ)

re:     fclean all

.PHONY: all clean fclean re