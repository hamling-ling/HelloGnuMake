SUBPROJS= \
	main

all: ${SUBPROJS}

clean:
	@for prj in ${SUBPROJS} ; do \
		make clean -C $$prj ; \
	done

${SUBPROJS}:
	make -C $@

.PHONY: all clean ${SUBPROJS}
