TOOL_LIST := tools
LIB_LIST := src/libraries 
APP_LIST := src/apps

all: tools libs apps

libs: 
	$(MAKE) --directory=$(LIB_LIST) all

apps: 
	$(MAKE) --directory=$(APP_LIST) all

tools: 
	$(MAKE) --directory=$(TOOL_LIST) all
sdk:
	$(MAKE) clean
	$(MAKE) --directory=$(TOOL_LIST)/sdk_builder generate-sdk

clean:
	$(MAKE) --directory=$(TOOL_LIST) clean
	$(MAKE) --directory=$(LIB_LIST) clean
	$(MAKE) --directory=$(APP_LIST) clean

.PHONY: all clean tools libs apps sdk