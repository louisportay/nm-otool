STR=\
	ft_strcat.c\
	ft_strchr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnstr.c\
	ft_strstr.c\
	strdel.c\
	strnew.c\
	strequ.c\
	strjoin.c\
	strsplit.c\
	strsub.c\
	strtrim.c\
	stroccur.c\
	ft_tolower.c\
	ft_toupper.c\
	strchri.c\

STR_DIR=str

OBJ+=$(addprefix $(OBJDIR)/$(STR_DIR)/, $(STR:%.c=%.o))

SRCDIR+=$(STR_DIR)/

INCLUDE+=-I$(STR_DIR)/

HEADER=str

$(OBJDIR)/$(STR_DIR)/%.o: %.c $(HEADER) | $(OBJDIR)/$(STR_DIR)
	$(COMPILE.c) $< -o $@

$(OBJDIR)/$(STR_DIR):
	mkdir -p $(OBJDIR)/$(STR_DIR)
