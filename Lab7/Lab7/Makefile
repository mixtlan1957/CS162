
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Int_LinkedList.o Integer_Input_Val.o Main.o Node.o

SRCS = Int_LinkedList.cpp Integer_Input_Val.cpp Main.cpp Node.cpp

HEADERS = Int_LinkedList.hpp Integer_Input_Val.hpp Node.hpp
#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm ${OBJS}

