
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Main.o Building.o char_Input_Val.o float_Input_Val.o Instructor.o Integer_Input_Val.o messageReader.o Person.o simpleStringSearch.o Student.o University.o

SRCS = Main.cpp Building.cpp char_Input_Val.cpp float_Input_Val.cpp Instructor.cpp Integer_Input_Val.cpp messageReader.cpp Person.cpp simpleStringSearch.cpp Student.cpp University.cpp

HEADERS = Building.hpp char_Input_Val.hpp float_Input_Val.hpp Instructor.hpp Integer_Input_Val.hpp messageReader.hpp Person.hpp simpleStringSearch.hpp Student.hpp University.hpp

#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.hpp=.hpp)


clean:
	rm ${OBJS}

