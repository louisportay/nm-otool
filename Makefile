# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lportay <lportay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 10:52:14 by lportay           #+#    #+#              #
#    Updated: 2019/02/20 21:15:14 by lportay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all tags rules

SRCDIR= src_nm/ src_otool/

vpath %.c $(SRCDIR)
vpath %.h includes/

CFLAGS= -Wall -Wextra -Werror $(INCLUDE)
DEBUG=sanitize
OPT=LIB
ARCH:= $(shell uname)

ifeq ($(ARCH), Darwin)
	CC= clang
else ifeq ($(ARCH), Linux)
	CC=gcc-8
endif

ifeq ($(BIN), 32)
	CFLAGS+= -m32
endif

ifeq ($(DEBUG), yes)
	CFLAGS+= -g3
else ifeq ($(DEBUG), prod)
	CFLAGS+= -O3 -DNDEBUG
else ifeq ($(DEBUG), sanitize)
	CFLAGS+= -g3 -fsanitize=address
endif

INCLUDE=\
-Iincludes\
-I$(LIBDIR)bridge\
-I$(LIBDIR)is\
-I$(LIBDIR)err\
-I$(LIBDIR)buf\
-I$(LIBDIR)mem\
-I$(LIBDIR)bytes\
-I$(LIBDIR)str\
-I$(LIBDIR)array\


HEADERS= nm.h\
		 otool.h\

SRC_NM= \
		ar.c\
		fat.c\
		ndian.c\
		nm.c\
		nm_main.c\
		print.c\
		s32.c\
		s64.c\
		sort.c\
		utils.c\

SRC_OTOOL= otool_main.c\
		   otool.c\

OBJDIR= obj
OBJ_NM= $(addprefix $(OBJDIR)/, $(SRC_NM:%.c=%.o))
OBJ_OTOOL= $(addprefix $(OBJDIR)/, $(SRC_OTOOL:%.c=%.o))

LIBDIR= libft/
LIB= libft.a

NM= ft_nm
#OTOOL = ft_otool
NAME= $(NM) $(OTOOL)

GREEN="\033[32m"
RESET="\033[0m"

all: $(LIB) $(NAME)

$(NM): $(LIBDIR)$(LIB) $(OBJ_NM)
	$(CC) $(CFLAGS) -o $@ $(OBJ_NM) -L$(LIBDIR) -lft
	@echo $(GREEN)$@" Successfully created"$(RESET)

$(OTOOL): $(LIBDIR)$(LIB) $(OBJ_OTOOL)
	$(CC) $(CFLAGS) -o $@ $(OBJ_OTOOL) -L$(LIBDIR) -lft
	@echo $(GREEN)$@" Successfully created"$(RESET)

$(OBJDIR)/%.o: %.c $(HEADERS) | $(OBJDIR)
	$(COMPILE.c) $< -o $@ $(INCLUDE)

$(OBJDIR):
	-mkdir -p $@

$(LIB):
	@$(MAKE) -C $(LIBDIR)

$(LIBDIR)$(LIB):
	@$(MAKE) -C $(LIBDIR)

main: $(LIB)
	$(CC) $(CFLAGS) -o test $(main) -L$(LIBDIR) -lft
	-rm -f $(main:.c=.o)

tags:
	ctags -R *

rules:
	@echo 'lportay' > auteur
	@echo "Here are the things to review before turning in your work\n\
	1. Leaks\n\
	2. Forbidden Functions\n\
	3. Drop Useless Libraries\n\
	3. Norme\n\
	4. Adequate Compilation Flags\n\
	5. Squash Commits"

clean:

ifeq ($(OPT), LIB)
	@$(MAKE) clean -C $(LIBDIR)
endif
	$(RM) -r $(OBJDIR) 
	@$(RM) test a.out
	@$(RM) -r test.dSYM

fclean: clean

ifeq ($(OPT), LIB)
	@$(MAKE) fclean -C $(LIBDIR)
endif		
	$(RM) $(NAME) $(SYMLINK)
	@$(RM) -r $(NAME).dSYM

re : fclean all
