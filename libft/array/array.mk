ARRAY=\
	  array_clear.c\
	  array_destroy.c\
	  array_new.c\
	  array_len.c\
	  array_map.c\
	  array_print.c\
	  array_dup.c\
#	  array_sort.c\

ARRAY_DIR=array

OBJ+=$(addprefix $(OBJDIR)/$(ARRAY_DIR)/, $(ARRAY:%.c=%.o))

SRCDIR+=$(ARRAY_DIR)/

INCLUDE+=-I$(ARRAY_DIR)/

HEADER=array

$(OBJDIR)/$(ARRAY_DIR)/%.o: %.c $(HEADER) | $(OBJDIR)/$(ARRAY_DIR)
	$(COMPILE.c) $< -o $@

$(OBJDIR)/$(ARRAY_DIR):
	mkdir -p $(OBJDIR)/$(ARRAY_DIR)
