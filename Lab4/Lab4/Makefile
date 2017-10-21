
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Building.o float_Input_Val.o Instructor.o Integer_Input_Val.o messageReader.o Person.o simpleStringSearch.o Student.o University.o Main.o

SRCS = Building.cpp float_Input_Val.cpp Instructor.cpp Integer_Input_Val.cpp messageReader.cpp Person.cpp simpleStringSearch.cpp Student.cpp University.cpp Main.cpp

HEADERS = Building.hpp float_Input_Val.hpp Instructor.hpp Integer_Input_Val.hpp messageReader.hpp Person.hpp simpleStringSearch.hpp Student.hpp University.hpp 
#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm ${OBJS}

