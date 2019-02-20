BYTES=\
	  bswap.c\

BYTES_DIR=bytes

OBJ+=$(addprefix $(OBJDIR)/$(BYTES_DIR)/, $(BYTES:%.c=%.o))

SRCDIR+=$(BYTES_DIR)/

INCLUDE+=-I$(BYTES_DIR)/

HEADER=bytes

$(OBJDIR)/$(BYTES_DIR)/%.o: %.c $(HEADER) | $(OBJDIR)/$(BYTES_DIR)
	$(COMPILE.c) $< -o $@

$(OBJDIR)/$(BYTES_DIR):
	mkdir -p $(OBJDIR)/$(BYTES_DIR)
