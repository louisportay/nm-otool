# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lportay <lportay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 17:01:50 by lportay           #+#    #+#              #
#    Updated: 2019/04/10 18:03:07 by lportay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

CC= gcc-8
CFLAGS= -Wall -Wextra -Werror $(INCLUDE)
DEBUG=no
ARCH:= $(shell uname)

ifeq ($(ARCH), Darwin)
	CC= clang
endif

ifeq ($(DEBUG),yes)
	CFLAGS += -g3
else ifeq ($(DEBUG),sanitize)
	CFLAGS += -fsanitize=address -g3
endif

NAME= libft.a

all: $(NAME)

OBJDIR=obj

include array/array.mk
include bridge/bridge.mk
include buf/buf.mk
#include hash/hash.mk
#include io/io.mk
include is/is.mk
include err/err.mk
include mem/mem.mk
include bytes/bytes.mk
#include list/list.mk
#include other/other.mk
#include result/result.mk
#include stack/stack.mk
include str/str.mk
#include string/string.mk
#include utf/utf.mk
#include vector/vector.mk
#include wcs/wcs.mk
include maths/maths.mk

vpath %.c $(SRCDIR)
vpath %.h $(SRCDIR)

GREEN="\033[32m"
RESET="\033[0m"

$(NAME): $(OBJ)
		ar rc $@ $?
		ranlib $@
		@echo $(GREEN)$(NAME)" Successfully created"$(RESET)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
