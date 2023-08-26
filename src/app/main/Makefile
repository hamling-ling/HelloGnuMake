MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR  := $(dir $(MAKEFILE_PATH))
TOP_DIR := $(abspath $MAKEFILE_DIR/../../..)
INC_DIR := $(TOP_DIR)/INC/
LIB_DIR := $(TOP_DIR)/LIBS

PROG:=hello
SRCS := main.cpp
OBJS := ${SRCS:%.cpp=%.o}
DEPS := ${SRCS:%.cpp=%.d}

CXXFLAGS += -I$(INC_DIR)/jansson-2.14/include 
LDFLAGS += -L$(LIB_DIR)
LIBS += -ljansson

CXX := g++

all: ${PROG}

${PROG}: ${OBJS}
	${CXX} $(CXXFLAGS) $(LDFLAGS) -o $@ ${OBJS} $(LIBS)

${DEPS}: %.d: %.cpp
	${CXX} $(CXXFLAGS) $< -MM -MP -MF $@

${OBJS}: %.o: %.cpp %.d
	${CXX} $(CXXFLAGS) -c $< -o $@

include $(shell ls ${DEPS} 2>/dev/null)

clean:
	${RM} ${PROG} ${OBJS} ${DEPS}

.PHONY: all clean
