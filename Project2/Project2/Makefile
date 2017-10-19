
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Animal.o Integer_Input_Val.o Main.o Penguin.o randomNumGen.o Tiger.o Turtle.o Zoo.o

SRCS = Animal.cpp Integer_Input_Val.cpp Main.cpp Penguin.cpp randomNumGen.cpp Tiger.cpp Turtle.cpp Zoo.cpp

HEADERS = Animal.hpp Integer_Input_Val.hpp Penguin.hpp randomNumGen.hpp Tiger.hpp Turtle.hpp Zoo.hpp

#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm ${OBJS}

