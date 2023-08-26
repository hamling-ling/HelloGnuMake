SUBPROJS= \
	jansson \
	app

all: ${SUBPROJS}

clean:
	@for prj in ${SUBPROJS} ; do \
		make clean -C $$prj ; \
	done
	rm -rf INC LIBS

${SUBPROJS}:
	make -C $@

.PHONY: all clean ${SUBPROJS}
