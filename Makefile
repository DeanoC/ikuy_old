TOOL_LIST := tools
LIB_LIST := src/libraries 
APP_LIST := src/apps

all: tools

tools: 
	$(MAKE) --directory=$(TOOL_LIST) all
sdk:
	$(MAKE) clean
	$(MAKE) --directory=$(TOOL_LIST)/sdk_builder generate-sdk

clean:
	$(MAKE) --directory=$(TOOL_LIST) clean

.PHONY: all clean tools