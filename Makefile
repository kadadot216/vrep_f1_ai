##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for Need4Stek
##

CC		=	gcc
DBCC		=	gcc -g
RM		=	rm -f

#	Library settings
LIB_DIR		=	lib
LIB_NAMEDIR	=	my
LIB_PATH	=	$(LIB_DIR)/$(LIB_NAMEDIR)

LIB_HDPATH	=	$(LIB_PATH)/include

LIB_HDSRC	=	my.h

LIB_HDS		=	$(addprefix $(LIB_HDPATH)/, $(LIB_HDSRC))

LIB_SRCS	=	my_putstr_fd.c		\
			str/my_strncmp.c	\
			str/my_strdup.c		\
			str/my_strlen.c		\
			str/my_memset.c		\
			my_getnbr.c
			
LIB_SRC		=	$(addprefix $(LIB_PATH)/, $(LIB_SRCS))
LIB_OBJ		=	$(LIB_SRC:.c=.o)
LIB_NAME	=	lib$(LIB_NAMEDIR).a

#	Program settings
HDPATH		=	./include
CFLAGS		+=	-I$(HDPATH)
LDFLAGS		=	-L./$(LIB_DIR)
LIBFLAG		=	-l$(LIB_NAMEDIR)
NAME		=	ai

MAIN		=	src/main.c

SRC		=	src/simulation.c		\
			src/callback/callback.c		\
			src/callback/collection.c	\
			src/callback/collection_free.c	\
			src/callback/collection_fill.c	\
			src/callback/col_print.c	\
			src/callback/print.c		\
			src/callback/get_parts.c	\
			src/callback/rvals.c		\
			src/callback/getcmd.c		\
			src/command/commandtab.c	\
			src/command/compose.c		\
			src/command/cmd_newval.c	\
			src/ext/str_go_to_tok.c		\
			src/ext/my_strfree.c		\
			src/ext/my_strn_eq.c		\
			src/ext/my_fnew.c		\
			src/ext/my_inew.c		\
			src/vehicle/vehicle.c		\
			src/vehicle/update.c		\
			src/vehicle/setters.c		\
			src/vehicle/actions.c		\
			src/vehicle/ai/direction.c	\
			src/vehicle/range.c		\
			src/vehicle/ai/speed.c

OBJ		=	$(SRC:.c=.o)
OBJ		+=	$(MAIN:.c=.o)

#	Tests settings
TEST_NAME	=	unit_tests
TEST_SRC	=	tests/redirect_all_std.c	\
			tests/t_maze_display.c

TEST_FLAGS	=	--coverage -lcriterion

GDB_MAIN	=	tests/main.c
GDB_NAME	=	gdb.out


.PHONY: tclean gclean fclean lclean lfclean $(NAME)

all:	libre $(NAME)

lib:	libmyhds libmy

libmyhds:
	@mkdir -p $(LIB_DIR)/$(HDPATH)
	cp $(LIB_HDS) $(HDPATH)

libmy:	$(LIB_OBJ)
	ar rc $(LIB_DIR)/$(LIB_NAME) $^

libclean:
	$(RM) $(LIB_OBJ)

libfclean: libclean
	rm -rf $(LIB_DIR)/$(HDPATH)
	$(RM) $(LIB_DIR)/$(LIB_NAME)

libre: libfclean lib

#	Program rules
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $^ $(LIBFLAG)

re: fclean lib $(NAME)

clean:
	$(RM) $(OBJ)

cclean:	clean 
	$(RM) $(HDTGR)
	$(RM) $(NAME)

#	Tests rules
gdb:	gclean libre
	$(DBCC) $(CFLAGS) $(LDFLAGS) -o $(GDB_NAME) $(GDB_MAIN) $(SRC)	\
		$(LIB_SRC)

gclean:
	$(RM) $(GDB_NAME)

tests_run:
	$(CC) -I./tests/ $(CFLAGS) -o $(TEST_NAME) $(TEST_SRC) $(SRC) $(TEST_FLAGS)
	./$(TEST_NAME)

tclean:
	$(RM) *.gc*
	$(RM) *vgcore*
	$(RM) $(TEST_NAME)

fclean: tclean gclean cclean libfclean
