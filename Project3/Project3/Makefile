
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Barbarian.o BlueMen.o Character.o Game.o HarryPotter.o Integer_Input_Val.o Main.o Medusa.o randNoGen.o Vampire.o

SRCS = Barbarian.cpp BlueMen.cpp Character.cpp Game.cpp HarryPotter.cpp Integer_Input_Val.cpp Main.cpp Medusa.cpp randNoGen.cpp Vampire.cpp

HEADERS = Barbarian.hpp BlueMen.hpp Character.hpp Game.hpp HarryPotter.hpp Integer_Input_Val.hpp Medusa.hpp randNoGen.hpp

#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm ${OBJS}

