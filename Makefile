CXX = g++
CXX_FLAGS = -std=c++14 -Wall -g -Iinclude -Llib -lsdl2
OBJECTS = main.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = pong

${EXEC}: ${OBJECTS}
	${CXX} ${CXX_FLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}