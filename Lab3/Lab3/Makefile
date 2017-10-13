.PHONY: valgrind
valgrind:
	valgrind --tool=memcheck output


CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Die.o Game.o Integer_Input_val.o LoadedDie.o Main.o

SRCS = Die.cpp Game.cpp Integer_Input_val.cpp LoadedDie.cpp Main.cpp

HEADERS = Die.hpp Game.hpp Integer_Input_val.hpp LoadedDie.hpp

#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm ${OBJS}

