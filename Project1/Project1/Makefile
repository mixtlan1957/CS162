CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Ant.o getInt.o Main.o menuFunction.o randNoGen.o

SRCS = Ant.cpp getInt.cpp Main.cpp menuFunction.cpp randNoGen.cpp

HEADERS = Ant.hpp getInt.hpp menuFunction.hpp randNoGen.hpp

#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm ${OBJS}

