MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR  := $(dir $(MAKEFILE_PATH))

INST_DIR := $(MAKEFILE_DIR)/inst
INC_DEST := $(abspath $MAKEFILE_DIR/../../INC/jansson-2.14)
LIB_DEST := $(abspath $MAKEFILE_DIR/../../LIBS)


all : downloadif buildif copyfiles

downloadif:
	@[ -f .downloaded ] || make download

download:
	curl -OL https://github.com/akheron/jansson/releases/download/v2.14/jansson-2.14.tar.bz2 && \
	touch .downloaded

buildif:
	@[ -f .built ] || make build

build:
	mkdir -p $(INST_DIR)
	tar jxvf jansson-2.14.tar.bz2
	cd jansson-2.14 && \
		./configure --prefix=$(INST_DIR) && \
		make && \
		make install
	touch .built

copyfiles:
	mkdir -p $(INC_DEST)
	mkdir -p $(LIB_DEST) 
	cp -r $(MAKEFILE_DIR)/inst/include $(INC_DEST)/
	cp -r $(MAKEFILE_DIR)/inst/lib/*.so* $(LIB_DEST)/

clean:
	rm -rf jansson-2.14.tar.bz2 jansson-2.14 .downloaded .built
	rm -rf $(INST_DIR) $(INC_DEST) $(LIB_DEST)/libjansson*
