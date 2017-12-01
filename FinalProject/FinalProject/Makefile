
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Main.o BattleMage.o GameBoard.o IceBoss.o char_Input_Val.o Integer_Input_Val.o DefaultRoom.o MobsRoom.o FinalBossRoom.o Space.o FireBossRoom.o randNoGen.o

SRCS = Main.cpp BattleMage.cpp GameBoard.cpp IceBoss.cpp char_Input_Val.cpp Integer_Input_Val.cpp DefaultRoom.cpp MobsRoom.cpp FinalBossRoom.cpp randNoGen.cpp

HEADERS = BattleMage.hpp GameBoard.hpp IceBoss.hpp char_Input_Val.hpp Integer_Input_Val.hpp DefaultRoom.hpp MobsRoom.hpp FinalBossRoom.hpp Space.hpp FireBossRoom.hpp randNoGen.hpp

#main stuff/output
output: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o output

#objects
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


clean:
	rm ${OBJS}

