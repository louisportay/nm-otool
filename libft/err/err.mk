ERR= err.c\

ERR_DIR=err

OBJ+=$(addprefix $(OBJDIR)/$(ERR_DIR)/, $(ERR:%.c=%.o))

SRCDIR+=$(ERR_DIR)/

INCLUDE+=-I$(ERR_DIR)/

HEADER=err

$(OBJDIR)/$(ERR_DIR)/%.o: %.c $(HEADER) | $(OBJDIR)/$(ERR_DIR)
	$(COMPILE.c) $< -o $@

$(OBJDIR)/$(ERR_DIR):
	mkdir -p $(OBJDIR)/$(ERR_DIR)
