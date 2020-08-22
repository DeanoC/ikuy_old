BOARD = pynqz2-z7-20
PART = xc7z020clg400-1

SRC_VERILOG_PATH = /home/deano/ikuy/src/hardware/verilog/
SRC_VERILOG = $(SRC_VERILOG_PATH)/main.v

CONSTRAINTS = boards/$(BOARD)/top.xdc

GEN_DIR = /home/deano/ikuy/generated

all: $(GEN_DIR)/Makefile


%.xdc:

%.v:
	
$(GEN_DIR)/Makefile: $(CONSTRAINTS) $(SRC_VERILOG)
	/usr/share/fpgamake/fpgamake --debug --verbose \
		-B $(BOARD) -p $(PART) --constraints $(CONSTRAINTS) -t main -o $(GEN_DIR)/Makefile -v $(SRC_VERILOG_PATH)
	make --directory=$(GEN_DIR) everything

clean:
	rm $(GEN_DIR)/Makefile
	rm -rf Impl
	rm -rf Synth
	rm -rf Cache
	rm -rf generated
	rm -rf build
	rm -f mkTop.bit
	rm -f mkTop.bin
	rm -f synth.mk
	rm -f usage_stat*.*
	rm -f *.jou
	rm -f *.log
	rm -f arty.xpr

.PHONY: build all