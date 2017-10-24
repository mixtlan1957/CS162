
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = arraySum.o Integer_Input_Val.o Main.o menuFunction.o reverseString.o triangular.o

SRCS = arraySum.cpp Integer_Input_Val.cpp Main.cpp menuFunction.cpp reverseString.cpp triangular.cpp

HEADERS = arraySum.hpp Integer_Input_Val.hpp menuFunction.hpp reverseString.hpp triangular.hpp
#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm ${OBJS}

