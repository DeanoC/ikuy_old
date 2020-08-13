GIT_VERSION := $(shell git describe --tags)

RM         := rm -rf
COPY       := cp -a
PATH_SEP   := /

BASE_DIR   := .
SRC_DIR    := .
GEN_DIR    := ../../generated
SDK_DIR    := ../../src/libraries/a9sdk

ADD_CFLAGS :=
ADD_LFLAGS := 
PACKAGE    := sdk_builder

CFLAGS     := $(ADD_CFLAGS) \
			  -Wall -Wextra \
			  -DGIT_VERSION=u\"$(GIT_VERSION)\" -std=gnu11
CXXFLAGS   := -Wall -Wextra \
			  -DGIT_VERSION=u\"$(GIT_VERSION)\" \
			  -std=c++2a 

IMM_DIR	   :=$(GEN_DIR)/software/$(PACKAGE)
OBJ_DIR    := $(IMM_DIR)/obj

CSOURCES   := $(wildcard $(SRC_DIR)/*.c)
CPPSOURCES := $(wildcard $(SRC_DIR)/*.cpp) 
TXTSOURCES := $(wildcard $(SRC_DIR)/*.txt)
COBJS      := $(addprefix $(OBJ_DIR)/, $(notdir $(CSOURCES:.c=.o)))
CXXOBJS    := $(addprefix $(OBJ_DIR)/, $(notdir $(CPPSOURCES:.cpp=.o)))
OBJECTS    := $(COBJS) $(CXXOBJS)
VPATH      := $(SRC_DIR)

QUIET      := @

ALL        := all
TARGET     := $(GEN_DIR)/sdk/bin/$(PACKAGE)
CLEAN      := clean

$(ALL): $(TARGET)

$(OBJECTS): | $(OBJ_DIR)

$(TARGET): $(OBJECTS) $(TXTSOURCES)
	$(QUIET) $(CXX) $(OBJECTS) -o $@

$(OBJ_DIR):
	$(QUIET) mkdir -p $(OBJ_DIR)

$(COBJS) : $(OBJ_DIR)/%.o : %.c $(BASE_DIR)/Makefile
	$(QUIET) $(CC) -c $< $(CFLAGS) -o $@ -MMD

$(OBJ_DIR)/%.o: %.cpp
	$(QUIET) $(CXX) -c $< $(CXXFLAGS) -o $@ -MMD

%.txt:

clean:
	-$(QUIET) $(RM) $(subst /,$(PATH_SEP),$(wildcard $(OBJ_DIR)/*.d))
	-$(QUIET) $(RM) $(subst /,$(PATH_SEP),$(wildcard $(OBJ_DIR)/*.o))
	-$(QUIET) $(RM) $(TARGET)

generate-sdk: ${ALL} 
	-$(QUIET) $(TARGET)
	$(MAKE) copy_headers 

copy_headers:
	-$(QUIET) $(COPY) $(wildcard $(GEN_DIR)/sdk/*.h) $(SDK_DIR)


include $(wildcard $(OBJ_DIR)/*.d)

.PHONY: ${ALL} ${CLEAN}