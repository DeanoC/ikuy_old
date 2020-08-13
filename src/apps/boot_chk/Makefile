RM         := rm -rf
COPY       := cp -a
PATH_SEP   := /

BASE_DIR   := .
GEN_DIR    := ../../../generated
SDK_DIR    := ../../../src/libraries/a9sdk

ADD_CFLAGS :=
ADD_LFLAGS := 
PACKAGE    := boot_chk

CFLAGS     := $(ADD_CFLAGS) \
			  -Wall -Wextra \
			  -I $(SDK_DIR) \
			  -D DEBUG_WRITES=1
			  -std=gnu11

IMM_DIR	   :=$(GEN_DIR)/software/$(PACKAGE)
OBJ_DIR    := $(IMM_DIR)/obj

CSOURCES   := $(wildcard ../boot/*.c)
COBJS      := $(addprefix $(OBJ_DIR)/, $(notdir $(CSOURCES:.c=.o)))
OBJECTS    := $(COBJS)
VPATH      := $(SRC_DIR)

QUIET      := @

ALL        := all
TARGET     := $(GEN_DIR)/software/apps/$(PACKAGE)
CLEAN      := clean

$(ALL): $(TARGET)

$(OBJECTS): | $(OBJ_DIR)

$(TARGET): $(OBJECTS) 
	$(QUIET) $(CC) $(OBJECTS) -o $@

$(OBJ_DIR):
	$(QUIET) mkdir -p $(OBJ_DIR)

$(COBJS) : $(OBJ_DIR)/%.o : ../boot/%.c $(BASE_DIR)/Makefile
	$(QUIET) $(CC) -c $< $(CFLAGS) -o $@ -MMD

clean:
	-$(QUIET) $(RM) $(subst /,$(PATH_SEP),$(wildcard $(OBJ_DIR)/*.d))
	-$(QUIET) $(RM) $(subst /,$(PATH_SEP),$(wildcard $(OBJ_DIR)/*.o))
	-$(QUIET) $(RM) $(TARGET)

run: $(TARGET)
	$(TARGET)

.PHONY: ${ALL} ${CLEAN} run

include $(wildcard $(OBJ_DIR)/*.d)

